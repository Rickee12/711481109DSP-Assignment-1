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

#include <stdio.h>
#include <math.h>
#include <memory.h>
#include <stdlib.h>
#include <string.h>
#define PI 3.14159265359
引入必要標頭檔：

stdio.h → 檔案與輸出入

math.h → 數學函式 (sin, cos, round)

memory.h → 記憶體操作

stdlib.h → 標準函式 (malloc, atoi, exit)

string.h → 字串操作

定義圓周率常數 PI

c
複製程式碼
typedef struct {
    char chunkID[4];     // "RIFF"
    unsigned int chunkSize;
    char format[4];      // "WAVE"
} RIFFHeader;

typedef struct {
    char subchunk1ID[4]; // "fmt "
    unsigned int subchunk1Size;
    unsigned short audioFormat;
    unsigned short numChannels;
    unsigned int sampleRate;
    unsigned int byteRate;
    unsigned short blockAlign;
    unsigned short bitsPerSample;
} FmtSubchunk;

typedef struct {
    char subchunk2ID[4]; // "data"
    unsigned int subchunk2Size;
} DataSubchunk;
定義 WAV 檔案的三個結構：

RIFFHeader → WAV 的主標頭

FmtSubchunk → 格式資訊 (取樣率、聲道數、每取樣位元)

DataSubchunk → 音訊資料大小

c
複製程式碼
int main(int argc, char *argv[])
{
    if(argc != 3){
        printf("Usage: %s in_fn out_fn\n", argv[0]);
        return 1;
    }
主程式入口

檢查輸入參數數量：程式名稱 + 輸入檔 + 輸出檔

c
複製程式碼
    char *in_fn = argv[1];   // 輸入檔名
    char *out_fn = argv[2];  // 輸出檔名

    FILE *fp = fopen(in_fn, "rb");  
    if(!fp){
        fprintf(stderr, "Cannot open file %s\n", in_fn);
        return 1;
    }
開啟輸入 WAV 檔案，檢查是否成功開啟

c
複製程式碼
    RIFFHeader riff;
    FmtSubchunk fmt;
    DataSubchunk data;
    fread(&riff, sizeof(RIFFHeader), 1, fp);
    fread(&fmt, sizeof(FmtSubchunk), 1, fp);
    fread(&data, sizeof(DataSubchunk), 1, fp);
讀取 WAV 檔的三個 header 結構，取得檔案資訊

c
複製程式碼
    int fs = fmt.sampleRate; 
    int bitsPerSample = fmt.bitsPerSample;
    int numChannels = fmt.numChannels;
    size_t N = data.subchunk2Size / (numChannels * bitsPerSample/8);

    short *stereo = malloc(N * fmt.numChannels * sizeof(short));
    fread(stereo, sizeof(short), N*fmt.numChannels, fp);
    fclose(fp);
從 header 讀取取樣率、位元深度與聲道數

計算取樣數 N

分配記憶體存放 PCM 音訊資料

讀取音訊資料並關閉輸入檔案

c
複製程式碼
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
從輸入檔名抓取第二個 f 後面的數字作為 RC 濾波的截止頻率

例如 audio_f400_out.wav → f = 400 Hz

c
複製程式碼
    double T = 1.0/fs; // 取樣週期
    double R = 1000;   // 電阻
    double C = 1.0/(2*PI*400*1000); // 電容 (可改為根據 f 計算)
    double a = R*C/(R*C+T); // 一階 RC 濾波係數

    double out_l = 0, out_r = 0;
    size_t total_samples = data.subchunk2Size / (numChannels * bitsPerSample / 8);
設定 RC 濾波器參數

計算濾波係數 a

初始化輸出變數 out_l、out_r

c
複製程式碼
    for (size_t n = 0; n < total_samples; n+=2) {
        double in_L = stereo[n];
        double in_R = stereo[n+1];

        // 一階 RC 濾波公式
        out_l = (1-a) * in_L + a * out_l;
        out_r = (1-a) * in_R + a * out_r;

        // 寫回 short 型態，並限制範圍 [-32768, 32767]
        stereo[n] = (short)round(out_l);
        stereo[n+1] = (short)round(out_r);

        if (stereo[n] > 32767) stereo[n] = 32767;
        if (stereo[n] < -32768) stereo[n] = -32768;
        if (stereo[n+1] > 32767) stereo[n+1] = 32767;
        if (stereo[n+1] < -32768) stereo[n+1] = -32768;
    }
逐取樣對左右聲道進行 RC 低通濾波

寫回 PCM 資料並防止溢位

c
複製程式碼
    fp = fopen(out_fn, "wb"); 
    if(!fp){
        fprintf(stderr, "Cannot save %s\n", out_fn);
        exit(1);
    }

    fwrite(&riff, sizeof(RIFFHeader), 1, fp);
    fwrite(&fmt, sizeof(FmtSubchunk), 1, fp);
    fwrite(&data, sizeof(DataSubchunk), 1, fp);
    fwrite(stereo, sizeof(short), N*fmt.numChannels, fp);

    free(stereo);
    fclose(fp);

    return 0;
}
開啟輸出檔案

寫入 WAV 檔頭與濾波後的音訊資料

釋放記憶體並關閉檔案

🔹 程式總結：
讀取 WAV 檔案

解析 header 取得音訊資訊

從檔名抓 cutoff 頻率

對左右聲道進行一階 RC 濾波

將濾波後音訊輸出為新 WAV 檔

如果你願意，我可以幫你把 C 濾波部分改成自動用檔名 f 計算 C，這樣 cutoff 就真的等於檔名數值，而不是寫死 400 kHz。

你希望我幫你改嗎？







你說：
程式分段大致解釋並用github markdown撰寫


ChatGPT 說：
當然可以，下面我幫你用 GitHub Markdown 把程式分段大致解釋，每段附簡單說明，重點抓流程與邏輯，而非每行註解：

c
複製程式碼
#include <stdio.h>
#include <math.h>
#include <memory.h>
#include <stdlib.h>
#include <string.h>
#define PI 3.14159265359
說明：
引入檔案操作、數學運算、記憶體操作、字串處理等標頭，定義圓周率。

c
複製程式碼
typedef struct { char chunkID[4]; unsigned int chunkSize; char format[4]; } RIFFHeader;
typedef struct { char subchunk1ID[4]; unsigned int subchunk1Size; unsigned short audioFormat; unsigned short numChannels; unsigned int sampleRate; unsigned int byteRate; unsigned short blockAlign; unsigned short bitsPerSample; } FmtSubchunk;
typedef struct { char subchunk2ID[4]; unsigned int subchunk2Size; } DataSubchunk;
說明：
定義 WAV 檔三個主要結構：主標頭（RIFF）、格式資訊（fmt）、資料區（data）。

c
複製程式碼
int main(int argc, char *argv[])
{
    if(argc != 3){
        printf("Usage: %s in_fn out_fn\n", argv[0]);
        return 1;
    }
說明：
主程式入口，檢查參數數量，確保有輸入檔名和輸出檔名。

c
複製程式碼
    char *in_fn = argv[1];
    char *out_fn = argv[2];
    FILE *fp = fopen(in_fn, "rb");
    if(!fp){ fprintf(stderr, "Cannot open file %s\n", in_fn); return 1; }
說明：
開啟輸入 WAV 檔，檢查是否成功。

c
複製程式碼
    RIFFHeader riff; FmtSubchunk fmt; DataSubchunk data;
    fread(&riff, sizeof(RIFFHeader), 1, fp);
    fread(&fmt, sizeof(FmtSubchunk), 1, fp);
    fread(&data, sizeof(DataSubchunk), 1, fp);
說明：
讀取 WAV 檔頭資訊，取得取樣率、聲道數、位元深度與資料大小。

c
複製程式碼
    int fs = fmt.sampleRate;
    int bitsPerSample = fmt.bitsPerSample;
    int numChannels = fmt.numChannels;
    size_t N = data.subchunk2Size / (numChannels * bitsPerSample/8);

    short *stereo = malloc(N * fmt.numChannels * sizeof(short));
    fread(stereo, sizeof(short), N*fmt.numChannels, fp);
    fclose(fp);
說明：
計算總取樣數，分配記憶體讀取 PCM 音訊資料，並關閉輸入檔案。

c
複製程式碼
    int f = 0;
    char *first_f = strchr(in_fn, 'f');
    if(first_f != NULL){
        char *second_f = strchr(first_f + 1, 'f');
        if(second_f != NULL){ f = atoi(second_f + 1); printf("Extracted cutoff frequency f = %d Hz\n", f); }
    }
    if(f <= 0){ fprintf(stderr, "Failed to extract cutoff frequency from filename.\n"); return 1; }
說明：
從檔名抓第二個 f 後的數字作為濾波截止頻率，失敗則退出程式。

c
複製程式碼
    double T = 1.0/fs; 
    double R = 1000;
    double C = 1.0/(2*PI*400*1000); 
    double a = R*C/(R*C+T);

    double out_l = 0, out_r = 0;
    size_t total_samples = data.subchunk2Size / (numChannels * bitsPerSample / 8);
說明：
設定 RC 濾波器參數與濾波係數，初始化左右聲道輸出。

c
複製程式碼
    for (size_t n = 0; n < total_samples; n+=2){
        double in_L = stereo[n];
        double in_R = stereo[n+1];

        out_l = (1-a) * in_L + a * out_l;
        out_r = (1-a) * in_R + a * out_r;

        stereo[n] = (short)round(out_l);
        stereo[n+1] = (short)round(out_r);

        if (stereo[n] > 32767) stereo[n] = 32767;
        if (stereo[n] < -32768) stereo[n] = -32768;
        if (stereo[n+1] > 32767) stereo[n+1] = 32767;
        if (stereo[n+1] < -32768) stereo[n+1] = -32768;
    }
說明：
對左右聲道逐取樣進行一階 RC 低通濾波，寫回 short，並限制範圍避免溢位。

c
複製程式碼
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
說明：
開啟輸出檔，寫入 WAV header 與濾波後音訊資料，釋放記憶體並關閉檔案，程式結束。

✅ 這樣你可以清楚看到程式流程：

讀檔 → 2. 解析 header → 3. 讀 PCM → 4. 提取 cutoff → 5. RC 濾波 → 6. 寫檔

如果你願意，我可以幫你改進 RC 部分 直接用檔名的 f 計算 C，讓 cutoff 完全符合檔名數值，會更實用。

你希望我幫你改嗎？







你說：
說明詳細一點 並用github code markdown 撰寫


ChatGPT 說：
當然可以，我幫你把程式用 GitHub Markdown 分段，並加入更詳細的解釋，讓每段流程、用途、計算邏輯都清楚。

c
複製程式碼
#include <stdio.h>
#include <math.h>
#include <memory.h>
#include <stdlib.h>
#include <string.h>
#define PI 3.14159265359
說明：

stdio.h：檔案輸入輸出、printf/fprintf

math.h：數學函式（sin, cos, round, floor）

memory.h：記憶體操作函式（可用於 memset/memcpy）

stdlib.h：動態記憶體配置 malloc/free、字串轉數字 atoi、程式結束 exit

string.h：字串操作函式（strchr 等）

定義圓周率常數 PI

c
複製程式碼
// WAV檔案主標頭
typedef struct {
    char chunkID[4];     // 檔案標識 "RIFF"
    unsigned int chunkSize; // 檔案大小 - 8 bytes
    char format[4];      // "WAVE"
} RIFFHeader;

// WAV檔案格式資訊
typedef struct {
    char subchunk1ID[4]; // "fmt "
    unsigned int subchunk1Size; // 固定16
    unsigned short audioFormat; // PCM = 1
    unsigned short numChannels; // 聲道數
    unsigned int sampleRate;    // 取樣率
    unsigned int byteRate;      // 每秒位元組數 = sampleRate * numChannels * bitsPerSample/8
    unsigned short blockAlign;  // 每個取樣區塊大小 = numChannels * bitsPerSample/8
    unsigned short bitsPerSample; // 每取樣位元
} FmtSubchunk;

// WAV音訊資料區
typedef struct {
    char subchunk2ID[4]; // "data"
    unsigned int subchunk2Size; // 資料大小（byte）
} DataSubchunk;
說明：

定義 WAV 三個主要結構

方便直接 fread/fwrite，存取 WAV header 與資料

c
複製程式碼
int main(int argc, char *argv[])
{
    if(argc != 3){
        printf("Usage: %s in_fn out_fn\n", argv[0]);
        return 1;
    }
說明：

主程式入口

檢查命令列參數數量：程式名稱 + 輸入檔名 + 輸出檔名

若不足則印出使用方法並退出

c
複製程式碼
    char *in_fn = argv[1];   // 輸入檔名
    char *out_fn = argv[2];  // 輸出檔名

    FILE *fp = fopen(in_fn, "rb");  // 以二進位模式開啟輸入 WAV
    if(!fp){
        fprintf(stderr, "Cannot open file %s\n", in_fn);
        return 1;
    }
說明：

開啟輸入檔案

如果開檔失敗，印錯誤訊息並退出

c
複製程式碼
    RIFFHeader riff;
    FmtSubchunk fmt;
    DataSubchunk data;

    fread(&riff, sizeof(RIFFHeader), 1, fp);   // 讀取 RIFF header
    fread(&fmt, sizeof(FmtSubchunk), 1, fp);  // 讀取格式子區
    fread(&data, sizeof(DataSubchunk), 1, fp); // 讀取資料子區 header
說明：

直接將 WAV header 讀入結構

後續可以用 fmt.sampleRate, fmt.numChannels 取得音訊資訊

c
複製程式碼
    int fs = fmt.sampleRate;  // 取樣率
    int bitsPerSample = fmt.bitsPerSample;  // 每取樣位元
    int numChannels = fmt.numChannels;      // 聲道數
    size_t N = data.subchunk2Size / (numChannels * bitsPerSample / 8); // 取樣數

    short *stereo = malloc(N * fmt.numChannels * sizeof(short)); // 動態配置記憶體存 PCM
    fread(stereo, sizeof(short), N*fmt.numChannels, fp); // 讀取音訊資料
    fclose(fp); // 讀完關閉檔案
說明：

計算總取樣數 N

動態配置陣列存放 PCM

fread 讀入全部音訊資料

c
複製程式碼
    // 從檔名抓第二個 f 後的數字作為濾波截止頻率
    int f = 0;  // cutoff frequency
    char *first_f = strchr(in_fn, 'f');
    if(first_f != NULL){
        char *second_f = strchr(first_f + 1, 'f');
        if(second_f != NULL){
            f = atoi(second_f + 1); // 字串轉數字
            printf("Extracted cutoff frequency f = %d Hz\n", f);
        }
    }
    if(f <= 0){
        fprintf(stderr, "Failed to extract cutoff frequency from filename.\n");
        return 1;
    }
說明：

解析輸入檔名，例如 audio_f400_out.wav → f = 400 Hz

若失敗，程式直接退出

c
複製程式碼
    double T = 1.0/fs;   // 取樣週期
    double R = 1000;      // 電阻 1kΩ
    double C = 1.0/(2*PI*400*1000); // RC 電容（可改成自動用 f 計算）
    double a = R*C/(R*C+T); // 一階 RC 濾波係數
說明：

計算濾波係數 a，用於一階離散 RC 濾波公式

c
複製程式碼
    double out_l = 0, out_r = 0; // 左右聲道濾波輸出暫存
    size_t total_samples = data.subchunk2Size / (numChannels * bitsPerSample / 8); // 總取樣數
說明：

初始化左右聲道輸出變數

計算總取樣數，用於迴圈處理

c
複製程式碼
    for (size_t n = 0; n < total_samples; n+=2){
        double in_L = stereo[n];       // 左聲道
        double in_R = stereo[n+1];     // 右聲道

        // 一階 RC 濾波公式
        out_l = (1-a) * in_L + a * out_l;
        out_r = (1-a) * in_R + a * out_r;

        // 限幅並寫回 short
        stereo[n] = (short)round(out_l);
        stereo[n+1] = (short)round(out_r);
        if (stereo[n] > 32767) stereo[n] = 32767;
        if (stereo[n] < -32768) stereo[n] = -32768;
        if (stereo[n+1] > 32767) stereo[n+1] = 32767;
        if (stereo[n+1] < -32768) stereo[n+1] = -32768;
    }
說明：

逐取樣對左右聲道做 RC 低通濾波

寫回 PCM 並限制在 16-bit 範圍，避免溢位

c
複製程式碼
    fp = fopen(out_fn, "wb"); // 開啟輸出 WAV 檔
    if(!fp){ fprintf(stderr, "Cannot save %s\n", out_fn); exit(1); }

    // 寫 WAV header + 音訊資料
    fwrite(&riff, sizeof(RIFFHeader), 1, fp);
    fwrite(&fmt, sizeof(FmtSubchunk), 1, fp);
    fwrite(&data, sizeof(DataSubchunk), 1, fp);
    fwrite(stereo, sizeof(short), N*fmt.numChannels, fp);

    free(stereo);  // 釋放記憶體
    fclose(fp);     // 關閉輸出檔
    return 0;
}
說明：

開啟輸出檔

寫入 WAV header 與濾波後音訊資料

釋放記憶體、關閉檔案

程式結束

