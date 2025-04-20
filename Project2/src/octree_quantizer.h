#ifndef OCTREE_QUANTIZER_H
#define OCTREE_QUANTIZER_H

#include <opencv2/opencv.hpp>
#include <vector>
#include <memory>

class OctreeQuantizer {
public:
    OctreeQuantizer(int maxColors);
    void addColor(const cv::Vec3b& color);
    void buildPalette();
    cv::Vec3b getQuantizedColor(const cv::Vec3b& color);
    cv::Mat quantizeImage(const cv::Mat& image);

private:
struct Node {
    bool isLeaf;
    int pixelCount;
    int red, green, blue;
    std::vector<std::unique_ptr<Node>> children;
    Node* parent;
    int depth;

    Node()
        : isLeaf(false), pixelCount(0), red(0), green(0), blue(0),
          children(8), parent(nullptr), depth(0) {}
};


    Node* root;
    std::vector<std::vector<Node*>> levels;
    std::vector<cv::Vec3b> palette;
    int leafCount;
    int maxLeaves;

    int getColorIndex(const cv::Vec3b& color, int depth);
    void insertColor(Node* node, const cv::Vec3b& color, int depth);
    void reduceTree();
    void collectLeaves(Node* node);
};

#endif // OCTREE_QUANTIZER_H