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
又因為 $I(t) = C \frac{dy(t)}{dt}$，代入得到：
$$x(t) = RC \frac{dy(t)}{dt} + y(t)$$  

這是 RC 電路的基本微分方程，描述輸入與輸出電壓的關係。

---

頻率響應
對上式進行傅立葉轉換：
$$X(\omega) = Y(\omega)(1 + j\omega RC)$$  
因此：
$$H(\omega) = \frac{Y(\omega)}{X(\omega)} = \frac{1}{1 + j\omega RC}$$  

此為 RC 電路的頻率響應，為低通濾波器。

---

穩態輸出
若輸入為 $x(t) = e^{j\omega t}$，則輸出為：
$$y(t) = e^{j\omega t} \cdot \frac{1}{1 + j\omega RC}$$  


###  Problem 2 
###  Problem 3
###  Problem 4
###  Problem 5
###  Problem 6
