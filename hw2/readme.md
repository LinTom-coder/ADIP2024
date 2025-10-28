# HW2
- Nearest and bilinear image shrinkage and enlargement operation (hw2_1_1.cpp and hw2_1_2.cpp)
- **Floyd Steinberg dithering algorithm** (hw2_2.cpp)
- Path search (hw3.cpp)

---

## highlight
### Introduction of Floyd-Steinberg dithering algorithm
False contours often appear due to quantization. A common solution is **Floyd–Steinberg dithering**, which distributes the quantization error of a pixel to its neighboring pixels to create a visually smoother result.

### 🔧 Performance
- ▶️ 8-bit to 4-bit Grayscale
  ![4-bit quantized grayscale image](https://github.com/LinTom-coder/ADIP/blob/main/hw2/img/hw2_2_8to4.png)  
  ![4-bit dithered grayscale image](https://github.com/LinTom-coder/ADIP/blob/main/hw2/img/hw2_2_floyd4.png)
- ▶️ 8-bit to 1-bit Grayscale
  ![1-bit quantized grayscale image](https://github.com/LinTom-coder/ADIP/blob/main/hw2/img/hw2_2_8to1.png)  
  ![1-bit dithered grayscale image](https://github.com/LinTom-coder/ADIP/blob/main/hw2/img/hw2_2_floyd1.png)


