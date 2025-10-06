# 數位訊號處理作業1
### 學號:711481109 姓名:莊祐儒
---
作業包含多個手寫數學的掃描檔與數位版本，以及Problem 7的程式碼實現與分析。

---

## **手寫作業 (Problems 1-6)**
此部分包含手寫算式的圖檔，手寫的內容也有以LaTeX方法來編寫

###  Problem 1 - LaTeX

首先考慮一個串聯的 RC 電路，輸入電壓為 $x(t)$，輸出為電容兩端電壓 $y(t)$。

1. 根據 Kirchhoff 電壓定律 (KVL)，輸入電壓可表示為：
   $$
   x(t) = I(t) \cdot R + y(t)
   $$
   其中 $I(t)$ 為通過電阻與電容的電流。

2. 電容兩端的電荷與電壓關係為：
   $$
   Q(t) = C \cdot y(t)
   $$

3. 電流為電荷的時間導數：
   $$
   I(t) = \frac{dQ(t)}{dt} = C \cdot \frac{dy(t)}{dt}
   $$

4. 將 (2)、(3) 式代回 (1)，得到微分方程：
   $$
   x(t) = R \left( C \frac{dy(t)}{dt} \right) + y(t)
   $$
   或簡化為：
   $$
   x(t) = RC \frac{dy(t)}{dt} + y(t)
   $$

---

## 頻率響應 $H(\nu)$（Fourier Transform）

對上述微分方程進行傅立葉轉換，以求得頻率響應。

令：
$$
X(\nu) = \mathcal{F}\{x(t)\}, \quad 
Y(\nu) = \mathcal{F}\{y(t)\}, \quad 
H(\nu) = \frac{Y(\nu)}{X(\nu)} = \mathcal{F}\{h(t)\}
$$

將 $x(t) = RC \frac{dy(t)}{dt} + y(t)$ 兩邊取傅立葉轉換：

$$
X(\nu) = RC \cdot (j\nu) Y(\nu) + Y(\nu)
$$

整理得：
$$
X(\nu) = Y(\nu) (1 + j\nu RC)
$$

因此系統頻率響應為：
$$
H(\nu) = \frac{Y(\nu)}{X(\nu)} = \frac{1}{1 + j\nu RC}
$$
---

## 穩態輸出 $y(t)$（當 $x(t) = e^{j\nu t}$）

若輸入訊號為複數指數形式：
$$
x(t) = e^{j\nu t}
$$

根據系統頻率響應：
$$
y(t) = x(t) \cdot H(\nu) = e^{j\nu t} \cdot \frac{1}{1 + j\nu RC}
$$

