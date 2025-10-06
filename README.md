# 數位訊號處理作業1
### 學號:711481109 姓名:莊祐儒
---
作業包含多個手寫數學的掃描檔與數位版本，以及Problem 7的程式碼實現與分析。

---

## **手寫作業 (Problems 1-6)**
此部分包含手寫算式的圖檔，手寫的內容也有以LaTeX方法來編寫

###  Problem 1 - LaTeX

### 電路分析與微分方程

1. **KVL 方程：**  
   $$x(t) = I(t)R + y(t)$$

2. **電容電荷：**  
   $$Q(t) = C y(t)$$

3. **電流：**  
   $$I(t) = \frac{dQ(t)}{dt} = C \frac{dy(t)}{dt}$$

4. **代回 KVL 方程：**  
   $$x(t) = RC \frac{dy(t)}{dt} + y(t)$$

---

### 頻率響應 $H(\nu)$
$$X(\nu) = RC(j\nu)Y(\nu) + Y(\nu) = Y(\nu)(1 + RCj\nu)$$  
$$H(\nu) = \frac{Y(\nu)}{X(\nu)} = \frac{1}{1 + RCj\nu}$$

---

### 穩態輸出 $y(t)$（當 $x(t) = e^{j\nu t}$）
$$y(t) = e^{j\nu t} \cdot \frac{1}{1 + RCj\nu}$$
