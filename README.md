# 數位訊號處理作業1
### 學號:711481109 姓名:莊祐儒
---
作業包含多個手寫數學的掃描檔與數位版本，以及Problem 7的程式碼實現與分析。

---

## **手寫作業 (Problems 1-6)**
此部分包含手寫算式的圖檔，手寫的內容也有以LaTeX方法來編寫

###  Problem 1 - LaTeX

\section*{Problem 1: 連續時間 RC 濾波器分析}

\subsection*{電路分析與微分方程}
\begin{enumerate}
    \item Kirchhoff 電壓定律 (KVL): $x(t) = I(t) \cdot R + y(t)$
    \item 電容電荷 $Q(t) = C \cdot y(t)$
    \item 電流 $I(t) = \frac{dQ(t)}{dt} = C \cdot \frac{dy(t)}{dt}$
    \item 代回 KVL 方程: 
    \[x(t) = R \left( C \frac{dy(t)}{dt} \right) + y(t)\]
    \[x(t) = RC \frac{dy(t)}{dt} + y(t)\]
\end{enumerate}

\subsection*{頻率響應 $H(\nu)$ (Fourier Transform)}
令 $X(\nu) = \mathcal{F}\{x(t)\}$, $Y(\nu) = \mathcal{F}\{y(t)\}$, $H(\nu) = \mathcal{F}\{h(t)\}$.
對微分方程進行傅立葉轉換:
\[X(\nu) = RC \cdot (j\nu) Y(\nu) + Y(\nu)\]
\[X(\nu) = Y(\nu) (1 + RCj\nu)\]
系統頻率響應 $H(\nu)$:
\[H(\nu) = \frac{Y(\nu)}{X(\nu)} = \frac{1}{1 + RCj\nu}\]

\subsection*{穩態輸出 $y(t)$ (當 $x(t)=e^{j\nu t}$)}
\[y(t) = x(t) \cdot H(\nu) = e^{j\nu t} \cdot \frac{1}{1 + RCj\nu}\]
