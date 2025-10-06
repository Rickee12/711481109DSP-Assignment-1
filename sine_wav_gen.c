#include <stdio.h>
#include <math.h>
#include <memory.h>
#include <stdlib.h>
#define PI 3.14159265359
/* This program generates a PCM file of 1 second 440Hz pure sin wave*/

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


int main(int argc, char *argv[])
{
	if(argc != 5){                                      // 檢查是否輸入4個參數
        printf("Usage: %s fs f L out_fn\n", argv[0]);
        return 1;
    }

    double fs = atof(argv[1]);       // sampling frequency
    double f  = atof(argv[2]);       // frequency of sin wave (Hz)
    double L  = atof(argv[3]);       // length of sin wave in an unit of second
    char *fn  = argv[4];             // 輸出檔名
    double T = 1/fs;// sampling period 1/16k
    double A = 10000;// amplitude of sin wave
    short *x;// array of the sin wave (2 byte for each sample)
    short *y;// array of the cos wave (2 byte for each sample)
    double tmp_sin;// temp variable
    double tmp_cos;// temp variable
    size_t N = (size_t)(L * fs);// length of sin wave (sample)
    size_t n;// sample index
    FILE *fp;// a file pointet to save waveform
    
    x = (short *) malloc(sizeof(short) * N);
    y = (short *) malloc(sizeof(short) * N);
    for( n = 0; n < N; n ++ ) {
        tmp_sin = A * sin(2 * PI * f * n * T); // generate sin wave for each sample
        tmp_cos = A * cos(2 * PI * f * n * T); // generate cos wave for each sample
        x[n] = (short)floor(tmp_sin + 0.5);// quantization
        y[n] = (short)floor(tmp_cos + 0.5);// quantization
    }
    
    short *stereo = (short *)malloc(sizeof(short) * N * 2);      //雙聲道 
    for ( n = 0; n < N; n++) {
    stereo[2*n] = x[n];      // 左聲道
    stereo[2*n + 1] = y[n];  // 右聲道
    }
    
    RIFFHeader riff = {{'R','I','F','F'}, 36 + (unsigned int)(N*2*2), {'W','A','V','E'}};                   // 建立 WAV 檔頭
    FmtSubchunk fmt = {{'f','m','t',' '}, 16, 1, 2, (unsigned int)fs, (unsigned int)(fs*2*2), 4, 16};
    DataSubchunk data = {{'d','a','t','a'}, (unsigned int)(N*2*2)};

    fp = fopen(fn, "wb");// open a file pointer to save a binary file
    if( !fp ) {// chech if the file is opened sucessfully
        fprintf(stderr, "Cannot save %s\n", fn);
        exit(1);// stop and exit this program if error
    }                                        
    fwrite(&riff, sizeof(RIFFHeader), 1, fp);         // 依序寫入檔頭與波形資料
    fwrite(&fmt, sizeof(FmtSubchunk), 1, fp);
    fwrite(&data, sizeof(DataSubchunk), 1, fp);
    fwrite(stereo, sizeof(short), N*2, fp);
    
    free(x);             // 釋放記憶體
	free(y); 
	free(stereo);
	
    fclose(fp);          // 關閉檔案
    return 0;
}


