# 數位訊號處理作業1
### 學號:711481109 姓名:莊祐儒
---
作業包含多個手寫數學的掃描檔與數位版本，以及Problem 7的程式碼實現與分析。

---

## **手寫作業 (Problems 1-6)**
此部分包含手寫算式的圖檔，手寫的內容也有以LaTeX方法來編寫

### **Problem 1 - LaTeX

\section*{Problem 2: 連續時間系統響應 (Continuous-Time System Response)}
給定 $x(t) = e^{j\nu t} u(t)$，假設 $\tau = RC$。系統函數 $H(s) = \frac{1}{1 + \tau s}$.

\subsection*{$s$-域 (Laplace Transform) 轉換}
\[X(s) = \mathcal{L}\{x(t)\} = \frac{1}{s - j\nu}\]
\[H(s) = \mathcal{L}\{h(t)\} = \frac{1}{1 + \tau s} = \frac{1}{\tau} \cdot \frac{1}{s + \frac{1}{\tau}}\]

\subsection*{輸出 $Y(s)$}
\[Y(s) = X(s) \cdot H(s) = \frac{1}{s - j\nu} \cdot \frac{1}{\tau} \cdot \frac{1}{s + \frac{1}{\tau}}\]

\subsection*{部分分式分解 (Partial Fraction Decomposition)}
\[\frac{1}{(s - j\nu)(s + \frac{1}{\tau})} = \frac{A}{s - j\nu} + \frac{B}{s + \frac{1}{\tau}}\]
\[\text{其中 } A = \left. \frac{1}{s + \frac{1}{\tau}} \right|_{s=j\nu} = \frac{1}{j\nu + \frac{1}{\tau}}, \quad B = \left. \frac{1}{s - j\nu} \right|_{s=-\frac{1}{\tau}} = \frac{1}{-\frac{1}{\tau} - j\nu}\]
\[Y(s) = \frac{1}{1 + j\nu\tau} \cdot \frac{1}{s - j\nu} - \frac{1}{1 + j\nu\tau} \cdot \frac{1}{s + \frac{1}{\tau}}\]
