# HW4
- local histogram equalization
- Average filter and Gaussian filter
- 0-degree/90-degree **Sobel filter** and 4-neighbor/8-neighbor **laplacian filter**

## key point
### Introduction of spatial domain edge detection
**Spatial domain edge detection** involves applying convolutional filters directly to pixel values to detect intensity changes that signify edges. This project implements two common edge detection methods:

- **The Sobel filter** computes image **gradients** to highlight edges, with the 0° kernel detecting vertical edges and the 90° kernel detecting horizontal edges.

- **The Laplacian filter** is a rotation-invariant **second-order derivative** filter that highlights edges by measuring intensity differences from neighboring pixels, commonly using 4- or 8-neighbor kernels.

### 🖼️ Example Results

![orginal](https://github.com/LinTom-coder/ADIP/blob/main/hw4/img/astronomy1280x720.png)
![AfterSobel](https://github.com/LinTom-coder/ADIP/blob/main/hw4/img/hw4_sobel.png)

If the image contains noise, the Sobel or Laplacian filter may enhance the noise, since both are sensitive to **high-frequency components**.
![Noise](https://github.com/LinTom-coder/ADIP/blob/main/hw4/img/astronomy_noise1280x720.png)
![NoiseAfterSobel](https://github.com/LinTom-coder/ADIP/blob/main/hw4/img/hw4_sobel_noise.png)

---
