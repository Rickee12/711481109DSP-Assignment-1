# 數位訊號處理作業1
### 學號:711481109 姓名:莊祐儒
---
作業包含多個手寫數學的掃描檔與數位版本，以及Problem 7的程式碼實現與分析。

---

## **手寫作業 (Problems 1-6)**
此部分包含多個手寫數學且以LaTeX方法來編寫

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

System Definition and Parameters
 設定輸入 $x(t) = e^{j\omega t}$  
 
 設定 RC 元件參數 $R$ 與 $C$  
 
 計算角頻率 $\omega = 2\pi f$  

Transfer Function
 計算 RC 低通濾波器傳遞函數：
 
 $$H(\omega) = \frac{1}{1 + RC j \omega}$$
 
 預計算 $RC\omega = f/400$  

---

Case 1: $f = 100$ Hz
計算傳遞函數：

 $$
 H(\Omega) = \frac{1}{1 + j0.25} = \frac{16}{17} - j\frac{4}{17}
 $$
 
計算幅值與相位：
 
 $$
 |H| \approx 0.970, \quad \angle H \approx -14.04^\circ
 $$
 
計算輸出信號：

 $$
 y(t) \approx 0.970 e^{j(200\pi t - 14.04^\circ)}
 $$

---

Case 2: $f = 400$ Hz
計算傳遞函數：

 $$
 H(\Omega) = \frac{1}{1 + j} = \frac{1}{2} - j \frac{1}{2}
 $$
 
計算幅值與相位：

 $$
 |H| \approx 0.707, \quad \angle H = -45^\circ
 $$
 
計算輸出信號：

 $$
 y(t) \approx 0.707 e^{j(800\pi t - 45^\circ)}
 $$

---

Case 3: $f = 3000$ Hz
計算傳遞函數：

 $$
 H(\Omega) = \frac{1}{1 + j7.5} = \frac{4}{229} - j \frac{30}{229}
 $$
 
計算幅值與相位：

 $$
 |H| \approx 0.132, \quad \angle H \approx -82.41^\circ
 $$
 
計算輸出信號：

 $$
 y(t) \approx 0.132 e^{j(6000\pi t - 82.41^\circ)}
 $$

### Problem 4

System Definition and Parameters
 設定輸入 $x(t) = e^{j\Omega t}$  
 設定 RC 元件參數 $R = 1000 \, \Omega, \ C = \frac{1}{2\pi \cdot 400 \cdot 1000} \, F$  
 計算時間常數 $RC = \frac{1}{800\pi}$  

總輸出方程式：

 $$
 y(t) = \frac{1}{1+j\Omega RC} (e^{j\Omega t} - e^{-t/RC}), \quad t \ge 0
 $$

---

Case 1: $f = 100$ Hz
 計算角頻率：

 $$
 \Omega = 2\pi f = 2\pi (100) = 200\pi \, \text{rad/s}
 $$
 
 計算傳遞函數：

 $$
 1+j\Omega RC = 1 + j(200\pi)\left(\frac{1}{800\pi}\right) = 1 + j\frac{1}{4} = 1.031 e^{j14.04^\circ}
 $$
 $$
 \frac{1}{1+j\Omega RC} \approx 0.970 e^{-j14.04^\circ}
 $$
 
 計算輸出信號：

 $$
 y(t) \approx 0.970 e^{-j14.04^\circ} (e^{j200\pi t} - e^{-800\pi t})
 $$

---

Case 2: $f = 400$ Hz
 計算角頻率：

 $$
 \Omega = 2\pi f = 2\pi (400) = 800\pi \, \text{rad/s}
 $$
 
 計算傳遞函數：

 $$
 1+j\Omega RC = 1 + j(800\pi)\left(\frac{1}{800\pi}\right) = 1 + j1 = \sqrt{2} e^{j45^\circ} \approx 1.414 e^{j45^\circ}
 $$
 $$
 \frac{1}{1+j\Omega RC} \approx 0.707 e^{-j45^\circ}
 $$
 
 計算輸出信號：

 $$
 y(t) \approx 0.707 e^{-j45^\circ} (e^{j800\pi t} - e^{-800\pi t})
 $$

---

Case 3: $f = 3000$ Hz
 計算角頻率：

 $$
 \Omega = 2\pi f = 2\pi (3000) = 6000\pi \, \text{rad/s}
 $$
 
 計算傳遞函數：

 $$
 1+j\Omega RC = 1 + j(6000\pi)\left(\frac{1}{800\pi}\right) = 1 + j7.5 = 7.566 e^{j82.41^\circ}
 $$
 $$
 \frac{1}{1+j\Omega RC} \approx 0.132 e^{-j82.41^\circ}
 $$
 
 計算輸出信號：

 $$
 y(t) \approx 0.132 e^{-j82.41^\circ} (e^{j6000\pi t} - e^{-800\pi t})
 $$

###  Problem 5

System Definition and Parameters
 設定差分方程：
 
 $$
 y[n] = \frac{RC}{R\tau+RC} y[n-1] + \frac{\tau}{R\tau+RC} x[n]
 $$
 
 計算 Z 轉換：
 
 $$
 Y(z) = \frac{RC}{R\tau+RC} z^{-1} Y(z) + \frac{\tau}{R\tau+RC} X(z)
 $$
 
 計算傳遞函數：
 
 $$
 H(z) = \frac{Y(z)}{X(z)} = \frac{\frac{\tau}{R\tau+RC}}{1 - \frac{RC}{R\tau+RC} z^{-1}} = \frac{\tau}{R\tau + RC - RC z^{-1}}
 $$

---

Transfer Function Simplification
 將分子分母同除以 $\tau$：

 $$
 H(z) = \frac{1}{R + \frac{RC}{\tau} (1 - z^{-1})}
 $$

 帶入 $RC = \frac{1}{800\pi}$：

 $$
 H(z) = \frac{1}{R + \frac{1}{800\pi \tau} (1 - z^{-1})}
 $$

---

Frequency Response
 計算頻率響應 $H(\omega) = H(z)\big|_{z = e^{j\omega}}$：

 $$
 H(\omega) = \frac{1}{R + \frac{1}{800\pi \tau} (1 - e^{-j\omega})} = \frac{1}{1 + \frac{1}{800\pi \tau} (1 - e^{-j\omega})}
 $$

---

Steady-State Response
 對輸入 $x[n] = e^{j\omega n}$，系統穩態響應為：

 $$
 y[n] = H(\omega) \cdot x[n] = \frac{1}{1 + \frac{1}{800\pi \tau} (1 - e^{-j\omega})} e^{j\omega n}
 $$

###  Problem 6

