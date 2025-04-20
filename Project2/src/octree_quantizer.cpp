#include "octree_quantizer.h"

OctreeQuantizer::OctreeQuantizer(int maxColors)
    : maxLeaves(maxColors), leafCount(0) {
    root = new Node();
    levels.resize(8);
}

int OctreeQuantizer::getColorIndex(const cv::Vec3b& color, int depth) {
    int shift = 7 - depth;
    int r = (color[2] >> shift) & 1;
    int g = (color[1] >> shift) & 1;
    int b = (color[0] >> shift) & 1;
    return (r << 2) | (g << 1) | b;
}

void OctreeQuantizer::addColor(const cv::Vec3b& color) {
    insertColor(root, color, 0);
    while (leafCount > maxLeaves) {
        reduceTree();
    }
}

void OctreeQuantizer::insertColor(Node* node, const cv::Vec3b& color, int depth) {
    if (depth == 8) {
        if (!node->isLeaf) {
            node->isLeaf = true;
            ++leafCount;
        }
        node->red += color[2];
        node->green += color[1];
        node->blue += color[0];
        node->pixelCount++;
        return;
    }

    int idx = getColorIndex(color, depth);
    if (!node->children[idx]) {
        node->children[idx] = std::make_unique<Node>();
        node->children[idx]->depth = depth + 1;
        node->children[idx]->parent = node;
        levels[depth].push_back(node->children[idx].get());
    }

    insertColor(node->children[idx].get(), color, depth + 1);
}

void OctreeQuantizer::reduceTree() {
    for (int d = 7; d >= 0; --d) {
        if (!levels[d].empty()) {
            Node* node = levels[d].back();
            levels[d].pop_back();

            int r = 0, g = 0, b = 0, count = 0;
            for (auto& child : node->children) {
                if (child && child->isLeaf) {
                    r += child->red;
                    g += child->green;
                    b += child->blue;
                    count += child->pixelCount;
                    --leafCount;
                    child.reset();
                }
            }

            node->isLeaf = true;
            node->red = r;
            node->green = g;
            node->blue = b;
            node->pixelCount = count;
            ++leafCount;
            return;
        }
    }
}

void OctreeQuantizer::buildPalette() {
    palette.clear();
    collectLeaves(root);
}

void OctreeQuantizer::collectLeaves(Node* node) {
    if (node->isLeaf && node->pixelCount > 0) {
        cv::Vec3b avg;
        avg[2] = node->red / node->pixelCount;
        avg[1] = node->green / node->pixelCount;
        avg[0] = node->blue / node->pixelCount;
        palette.push_back(avg);
    } else {
        for (auto& child : node->children) {
            if (child) collectLeaves(child.get());
        }
    }
}

cv::Vec3b OctreeQuantizer::getQuantizedColor(const cv::Vec3b& color) {
    Node* current = root;
    for (int depth = 0; depth < 8 && !current->isLeaf; ++depth) {
        int idx = getColorIndex(color, depth);
        if (current->children[idx]) {
            current = current->children[idx].get();
        } else {
            break;
        }
    }

    if (current->pixelCount == 0) return color;

    return cv::Vec3b(
        current->blue / current->pixelCount,
        current->green / current->pixelCount,
        current->red / current->pixelCount
    );
}

cv::Mat OctreeQuantizer::quantizeImage(const cv::Mat& image) {
    OctreeQuantizer quant(maxLeaves);
    for (int y = 0; y < image.rows; ++y) {
        for (int x = 0; x < image.cols; ++x) {
            quant.addColor(image.at<cv::Vec3b>(y, x));
        }
    }

    quant.buildPalette();

    cv::Mat result = image.clone();
    for (int y = 0; y < result.rows; ++y) {
        for (int x = 0; x < result.cols; ++x) {
            result.at<cv::Vec3b>(y, x) = quant.getQuantizedColor(image.at<cv::Vec3b>(y, x));
        }
    }

    return result;
}
