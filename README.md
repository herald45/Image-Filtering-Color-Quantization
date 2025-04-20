# 🎨 CG1\_25L\_01204477\_Proj1-2 — Image Filtering & Color Quantization

**Computer Graphics Project**\
**Author:** NKOUNKOU Herald\
**Course:** L3 Informatique — Computer Graphics\
**Date:** 2025

---

## 📌 Description

This project is a graphical application for applying **image filters**, **dithering**, and **color quantization** using **OpenCV** and **Qt**. It has been developed in two parts:

### 🧩 Project 1 — Image Filtering

A basic application to:

- ✅ Load and display an image
- ✅ Apply image filters:
  - Inversion
  - Gamma correction
  - Gaussian blur
  - Edge detection (Sobel, Laplacian, etc.)
- ✅ Save filtered image
- ✅ Modify filter parameters dynamically via an interactive **Qt GUI**

### 🎯 Project 2 — Dithering & Color Quantization

This part extends the previous application with:

- ✅ One **color quantization algorithm**: **Octree Quantization**
- ✅ One **dithering algorithm**: **Error Diffusion (Floyd-Steinberg)**
- ✅ Interactive controls to:
  - Convert image to grayscale
  - Adjust number of quantized colors
  - Apply dithering on color or grayscale images
  - Display original vs processed image
  - Save processed image

> All filtering and image transformation operations are implemented manually using **pixel-level manipulation**, except for loading and displaying handled by OpenCV.

---

## 🧪 Features Summary

| Feature                            | Status        |
| ---------------------------------- | ------------- |
| Load image                         | ✅             |
| Display original & processed image | ✅             |
| Save image                         | ✅             |
| Convert to grayscale               | ✅             |
| Error Diffusion Dithering          | ✅             |
| Octree Color Quantization          | ✅             |
| Dynamic filter parameter control   | ✅             |
| Reset to original image            | ⚠️ (Optional) |
| GUI (Qt Widgets)                   | ✅             |

---

## ⚙️ Build Instructions

### With CMake

From the project root directory:

```bash
mkdir build && cd build
cmake ..
cmake --build .
./app  # Run the application
```

Or:

```bash
cd ..
rm -rf build
mkdir build && cd build
cmake ..
cmake --build .
./app
```

> 📝 Make sure you have installed **Qt** and **OpenCV** and that your `CMakeLists.txt` points to the correct locations.

---

## 📂 Structure

```
Project2/
├── src/
│   ├── main.cpp                 # Main application with UI
│   ├── octree_quantizer.h/.cpp # Octree quantization algorithm
├── CMakeLists.txt              # Build configuration
└── build/                      # Generated build files (after compiling)
```

---

## 📷 Screenshots 
<img width="883" alt="Capture d’écran 2025-03-31 à 19 55 18" src="https://github.com/user-attachments/assets/f7389225-e6c2-41cd-aca9-e1422facc5a6" />

<img width="901" alt="Capture d’écran 2025-03-31 à 19 55 25" src="https://github.com/user-attachments/assets/5616f54c-c4e5-4077-b3ca-36c579c73de6" />

---
