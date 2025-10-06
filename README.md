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


System Transfer Function
 設定系統傳遞函數：
 
 $$
 H(z) = \frac{\tau}{\tau + RC (1-z^{-1})}
 $$

Input Signal Z-Transform
 輸入信號 Z 轉換：
 
 $$
 X(z) = \frac{1}{1 - e^{j\omega} z^{-1}}
 $$

---

Output Z-Transform and Partial Fraction Expansion:

 
 $$
 Y(z) = \underbrace{\frac{A}{1 - e^{j\omega} z^{-1}}}_{\text{穩態}} + \underbrace{\frac{B}{\tau + RC (1-z^{-1})}}_{\text{暫態}}
 $$

---

Coefficient Calculation

1. Steady-State Coefficient \(A\)

 $$
 A = Y(z) \cdot (1 - e^{j\omega} z^{-1}) \Big|_{z^{-1} = e^{-j\omega}} = H(e^{j\omega})
 $$
 $$
 A = \frac{\tau}{\tau + RC (1-e^{-j\omega})}
 $$

2. Transient Coefficient \(B\)


 $$
 B = X(z) \cdot \tau \Big|_{z^{-1} = 1+\frac{\tau}{RC}} 
 $$
 $$
 B = \frac{1}{1 - e^{j\omega} z^{-1}} \cdot \tau \Big|_{z^{-1} = 1+\frac{\tau}{RC}}
 $$
 $$
 B = \frac{\tau}{1 - e^{j\omega} (1+\frac{\tau}{RC})}
 $$

---

Final Response \(y[n]\)

將 Y(z) 的兩項進行 Z 反變換：

穩態部分：

$$
y_{ss}[n] = \frac{\tau}{\tau + RC (1-e^{-j\omega})} \, e^{j\omega n} \, u[n]
$$

暫態部分：

$$
y_{tr}[n] = \frac{1}{1 - e^{j\omega} (1+\frac{\tau}{RC})} \left( \frac{RC}{\tau+RC} \right)^n u[n]
$$

最終完整響應：

$$
y[n] = y_{ss}[n] + y_{tr}[n]
$$

###  Problem 7  RC電路低通濾波器(以C語言撰寫)

## 目錄

1.標頭與常數定義

2.WAV 檔案結構定義

3.檢查命令列參數

4.開啟輸入檔案

5.讀取 WAV header

6.讀取 PCM 音訊資料

7.從檔名解析濾波 cutoff frequency

8.設定 RC 濾波參數

9.初始化濾波暫存

10.RC 低通濾波處理

11.寫出濾波後 WAV

---

## 1. 標頭與常數定義

```c
#include <stdio.h>
#include <math.h>
#include <memory.h>
#include <stdlib.h>
#include <string.h>
#define PI 3.14159265359
```


說明：

載入檔案、數學、記憶體、字串操作標頭

定義圓周率 PI

## 2. WAV檔案結構定義

```c
typedef struct {
    char chunkID[4];     
    unsigned int chunkSize;
    char format[4];      
} RIFFHeader;

typedef struct {
    char subchunk1ID[4]; 
    unsigned int subchunk1Size; 
    unsigned short audioFormat; 
    unsigned short numChannels; 
    unsigned int sampleRate;    
    unsigned int byteRate;      
    unsigned short blockAlign;  
    unsigned short bitsPerSample;
} FmtSubchunk;

typedef struct {
    char subchunk2ID[4]; 
    unsigned int subchunk2Size;
} DataSubchunk;
```

說明：

定義 WAV 檔案結構，用於讀寫 header 與資料區

## 3. 檢查命令列參數

```c
int main(int argc, char *argv[])
{
    if(argc != 3){
        printf("Usage: %s in_fn out_fn\n", argv[0]);
        return 1;
    }
```


說明：

確保使用者提供輸入檔名和輸出檔名

## 4. 開啟輸入檔案
 
 ```c
    char *in_fn = argv[1];   
    char *out_fn = argv[2];  

    FILE *fp = fopen(in_fn, "rb");  // 以二進位模式開啟輸入 WAV
    if(!fp){
        fprintf(stderr, "Cannot open file %s\n", in_fn);
        return 1;
    }
```


說明：

開啟 WAV 檔案，如果失敗則退出

##  5. 讀取 WAV header

```c
    RIFFHeader riff;
    FmtSubchunk fmt;
    DataSubchunk data;

    fread(&riff, sizeof(RIFFHeader), 1, fp);
    fread(&fmt, sizeof(FmtSubchunk), 1, fp);
    fread(&data, sizeof(DataSubchunk), 1, fp);
```

說明：

讀取 WAV header，取得取樣率、聲道數、位元深度等資訊

##  6. 讀取 PCM 音訊資料

```c
    int fs = fmt.sampleRate;
    int bitsPerSample = fmt.bitsPerSample;
    int numChannels = fmt.numChannels;
    size_t N = data.subchunk2Size / (numChannels * bitsPerSample / 8);

    short *stereo = malloc(N * fmt.numChannels * sizeof(short));
    fread(stereo, sizeof(short), N*fmt.numChannels, fp);
    fclose(fp);
```

說明：

計算總取樣數 N

分配記憶體存放 PCM 資料

讀入資料並關閉檔案

## 7. 從檔名解析 cutoff frequency

```c
    int f = 0;  // cutoff frequency
    char *first_f = strchr(in_fn, 'f');
    if(first_f != NULL){
        char *second_f = strchr(first_f + 1, 'f');
        if(second_f != NULL){
            f = atoi(second_f + 1);
            printf("Extracted cutoff frequency f = %d Hz\n", f);
        }
    }
    if(f <= 0){
        fprintf(stderr, "Failed to extract cutoff frequency from filename.\n");
        return 1;
    }
```

說明：

解析檔名，例如 audio_f400_out.wav → f = 400 Hz

若抓不到數字，程式退出


## 8. 設定 RC 濾波參數

```c
    double T = 1.0/fs;   // 取樣週期
    double R = 1000;     
    double C = 1.0/(2*PI*f*1000);  // cutoff frequency 自動使用 f
    double a = R*C/(R*C+T);
```

說明：

計算 RC 濾波係數 a

用於離散一階 RC 濾波公式

## 9. 初始化濾波暫存

```c
    double out_l = 0, out_r = 0;
    size_t total_samples = data.subchunk2Size / (numChannels * bitsPerSample / 8);
```


說明：

左右聲道濾波暫存

計算總取樣數

## 10. RC 低通濾波處理

```c
    for (size_t n = 0; n < total_samples; n+=2){
        double in_L = stereo[n];       
        double in_R = stereo[n+1];     

        out_l = (1-a) * in_L + a * out_l;
        out_r = (1-a) * in_R + a * out_r;

        stereo[n] = (short)round(out_l);
        stereo[n+1] = (short)round(out_r);

        // 限幅避免溢位
        if (stereo[n] > 32767) stereo[n] = 32767;
        if (stereo[n] < -32768) stereo[n] = -32768;
        if (stereo[n+1] > 32767) stereo[n+1] = 32767;
        if (stereo[n+1] < -32768) stereo[n+1] = -32768;
    }

```
說明：

使用離散 RC 公式對左右聲道濾波

限幅在 16-bit PCM 範圍內

## 11. 寫出濾波後 WAV

```c
    fp = fopen(out_fn, "wb");
    if(!fp){ fprintf(stderr, "Cannot save %s\n", out_fn); exit(1); }

    fwrite(&riff, sizeof(RIFFHeader), 1, fp);
    fwrite(&fmt, sizeof(FmtSubchunk), 1, fp);
    fwrite(&data, sizeof(DataSubchunk), 1, fp);
    fwrite(stereo, sizeof(short), N*fmt.numChannels, fp);

    free(stereo);
    fclose(fp);

    return 0;
}
```

說明：

開啟輸出檔案並寫入 header 與濾波後音訊

釋放記憶體並結束程式
