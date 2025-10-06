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

# Problem 2: System Analysis with Laplace Transform

Given
* Input signal: $x(t) = e^{j\Omega t} u(t)$  
* System time constant: $\tau = RC$  

---

Step 1: Laplace Transform of Input and System Function

輸入與系統函數轉換到 s-domain：

$$
\mathcal{L}\{x(t)\} = X(s) = \frac{1}{s - j\Omega}
$$

$$
\mathcal{L}\{h(t)\} = H(s) = \frac{1}{1 + \tau s} \quad \text
$$


---

Step 2: Output in s-domain

輸出 $Y(s)$ 為輸入與系統函數的乘積：

$$
Y(s) = X(s) \cdot H(s) = \frac{1}{s - j\Omega} \cdot \frac{1}{1 + \tau s} = \frac{1}{\tau} \cdot \frac{1}{s - j\Omega} \cdot \frac{1}{s + 1/\tau}
$$



---

Step 3: Partial Fraction Expansion (PFE)

將 $Y(s)$ 拆成兩個簡單分數：

$$
Y(s) = \frac{1}{\tau} \left( \frac{A}{s - j\Omega} + \frac{B}{s + 1/\tau} \right)
$$

### Residues
- **A (對應輸入極點 $s=j\Omega$)**：
$$
A = \frac{\tau}{1 + j\Omega \tau}
$$
- **B (對應系統極點 $s=-1/\tau$)**：
$$
B = -\frac{\tau}{1 + j\Omega \tau}
$$

代回後：

$$
Y(s) = \frac{1}{1 + j\Omega \tau} \cdot \frac{1}{s - j\Omega} - \frac{1}{1 + j\Omega \tau} \cdot \frac{1}{s + 1/\tau}
$$


---

Step 4: Inverse Laplace Transform

使用 $\mathcal{L}^{-1}\left\{\frac{1}{s-a}\right\} = e^{at} u(t)$：

$$
y(t) = \frac{1}{1 + j\Omega \tau} e^{j\Omega t} u(t) - \frac{1}{1 + j\Omega \tau} e^{-t/\tau} u(t), \quad t \ge 0
$$

代入 $\tau = RC$：

$$
y(t) = \frac{1}{1 + j\Omega RC} e^{j\Omega t} - \frac{1}{1 + j\Omega RC} e^{-t/RC}, \quad t \ge 0
$$

---

 Step 5: Steady-State and Transient Response

 1️⃣ 穩態解 (Steady-State Response)
$$
\color{blue}{y_{ss}(t) = \frac{1}{1 + j\Omega RC} e^{j\Omega t}}
$$


 2️⃣ 暫態解 (Transient Response)
$$
\color{red}{y_{tr}(t) = - \frac{1}{1 + j\Omega RC} e^{-t/RC}}
$$
- 對應系統極點 $s = -1/RC$  
- 隨時間衰減至 0  
- 代表系統初始調整與暫態行為  


###  Problem 3
###  Problem 4
###  Problem 5
###  Problem 6
