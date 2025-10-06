# 數位訊號處理作業1
### 學號:711481109 姓名:莊祐儒
---
作業包含多個手寫數學的掃描檔與數位版本，以及Problem 7的程式碼實現與分析。

---

## **手寫作業 (Problems 1-6)**
此部分包含多個手寫數學，內容以LaTeX方法來編寫


###  Problem 1 

微分方程推導
根據 KVL（Kirchhoff 電壓定律）：
$$x(t) = R \cdot I(t) + y(t)$$  

又因為 $I(t) = C \frac{dy(t)}{dt}$

代入得到：
$$x(t) = RC \frac{dy(t)}{dt} + y(t)$$  



---

頻率響應
對上式進行傅立葉轉換：
$$X(\Omega) = Y(\Omega)(1 + j\Omega RC)$$ 

因此：
$$H(\Omega) = \frac{Y(\Omega)}{X(\Omega)} = \frac{1}{1 + j\Omega RC}$$  

---

穩態輸出
若輸入為 $x(t) = e^{j\Omega t}$，則輸出為：

$$y(t) = e^{j\Omega t} \cdot \frac{1}{1 + j\Omega RC}$$  


###  Problem 2 


Given
* Input signal: $x(t) = e^{j\Omega t} u(t)$  
* System time constant: $\tau = RC$  

---

Step 1: Laplace Transform

將輸入與系統函數轉換到 s-domain：

$$
X(s) = \frac{1}{s - j\Omega}, \quad
H(s) = \frac{1}{1 + \tau s}
$$



---

Step 2: Output in s-domain

輸出為輸入與系統函數的乘積：

$$
Y(s) = X(s) \cdot H(s) = \frac{1}{\tau} \cdot \frac{1}{s - j\Omega} \cdot \frac{1}{s + 1/\tau}
$$

---

Step 3: Partial Fraction Expansion (PFE)

將 $Y(s)$ 拆成兩個簡單分數：

$$
Y(s) = \frac{1}{\tau} \left( \frac{A}{s - j\Omega} + \frac{B}{s + 1/\tau} \right)
$$

係數：

$$A = \frac{\tau}{1 + j\Omega \tau}, \quad$$
$$B = -\frac{\tau}{1 + j\Omega \tau}$$

代回：

$$Y(s) = \frac{1}{1 + j\Omega \tau} \cdot \frac{1}{s - j\Omega} - \frac{1}{1 + j\Omega \tau} \cdot \frac{1}{s + 1/\tau}$$


---

Step 4: Inverse Laplace Transform

將每項反 Laplace：

$$y(t) = \frac{1}{1 + j\Omega RC} e^{j\Omega t} - \frac{1}{1 + j\Omega RC} e^{-t/RC}, \quad t \ge 0$$


Step 5: Steady-State and Transient Response

- Steady-State Response (穩態解)
  
$$y_{ss}(t) = \frac{1}{1 + j\Omega RC} e^{j\Omega t}$$



- Transient Response (暫態解)

$$y_{tr}(t) = - \frac{1}{1 + j\Omega RC} e^{-t/RC}$$


###  Problem 3

若 $$x(t)=e^{j\Omega t}$$

求 $$y(t)$$

$從Problem 1 得$

$$H(\Omega)=\frac{1}{1+j \Omega RC},y(t)=\frac{1}{1+j \Omega RC}e^{j\Omega t}$$

$題目給的參數$

$$R=1000\Omega , C=\frac{1}{2\pi\times400\times1000},\Omega=2\pi f$$
$代入$

$$j\Omega RC=\frac{f}{400}j$$

$example :$ $f=100Hz$

$$H(\Omega)=\frac{1}{1+\frac{100}{400}j}=\frac{1}{1+0.25j}$$

$$|H(\Omega)|=\frac{1}{\sqrt{1^2+0.25^2}}\approx0.9701$$

$$\angle H(\Omega)=-arctan(\frac{0.25}{1})\approx-14.04$$

$So:$

$$H(\Omega)=\approx0.9701e^{-j14.04^\circ}$$

$y(t):$

$$\Omega=2\pi\times10=200\pi\      rad/s$$

$$y(t)=(0.9701e^{-j14.04^\circ})e^{j(200\pi t)}$$

$$ =0.9701e^{j(200\pi t-14.04^\circ)}$$

$$ 以此類推f = 400,3000Hz照著上述的運算邏輯便能得到結果 $$
###  Problem 4
###  Problem 5
###  Problem 6
