#include <stdio.h>
#include <math.h>
#include <memory.h>
#include <stdlib.h>
#include <string.h>
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
	if(argc != 3){                                      // �ˬd�ѼƼƶq
        printf("Usage: %s in_fn out_fn\n", argv[0]);
        return 1;
    }

    char *in_fn = argv[1];   // ��J�ɦW
    char *out_fn = argv[2];  // ��X�ɦW

    FILE *fp = fopen(in_fn, "rb");  // �}�ҿ�J WAV ��
    if(!fp){
        fprintf(stderr, "Cannot open file %s\n", in_fn);
        return 1;
    }
    
    // Ū�� WAV ���Y
	RIFFHeader riff;     
    FmtSubchunk fmt;
    DataSubchunk data;
    fread(&riff, sizeof(RIFFHeader), 1, fp);
    fread(&fmt, sizeof(FmtSubchunk), 1, fp);
    fread(&data, sizeof(DataSubchunk), 1, fp);
    
	// �q header Ū���Ѽ� 
	int fs = fmt.sampleRate;  
	int bitsPerSample = fmt.bitsPerSample;
	int numChannels = fmt.numChannels;
	size_t N = data.subchunk2Size / (numChannels * bitsPerSample/8);
	
	// Ū�����T��� 
    short *stereo = malloc(N * fmt.numChannels * sizeof(short));     
    fread(stereo, sizeof(short), N*fmt.numChannels, fp);
    fclose(fp);
    
    
    //  �q��J�ɦW����f 
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

    
    // RC�q���Ѽ� 
    double T = 1.0/fs;                                     
    double R = 1000;
    double C = 1.0/(2*PI*400*1000);
    double a = R*C/(R*C+T);
    double out_l = 0, out_r = 0;
    size_t n;// sample index
    size_t total_samples = data.subchunk2Size / (numChannels * bitsPerSample / 8);

    //�o�i
    for (n = 0; n < total_samples; n+=2) {

    double in_L = stereo[n];
    double in_R = stereo[n+1];

    // �@�� RC �o�i����
    out_l = (1-a) * in_L + a * out_l;
    out_r = (1-a) * in_R + a* out_r;
    
    // �g�^ short ���A�ð��d�򭭨�
    stereo[n] = (short)round(out_l);
    stereo[n+1] = (short)round(out_r);
    if (stereo[n] > 32767) stereo[n] = 32767;
    if (stereo[n] < -32768) stereo[n] = -32768;
    if (stereo[n+1] > 32767) stereo[n+1] = 32767;
    if (stereo[n+1] < -32768) stereo[n+1] = -32768;
    }
    
    // ��X�s�� WAV �� 
    fp = fopen(out_fn, "wb");// open a file pointer to save a binary file
    if( !fp ) {// chech if the file is opened sucessfully
        fprintf(stderr, "Cannot save %s\n", out_fn);
        exit(1);// stop and exit this program if error
    }
    
    // �g�J header + data
    fwrite(&riff, sizeof(RIFFHeader), 1, fp);
    fwrite(&fmt, sizeof(FmtSubchunk), 1, fp);
    fwrite(&data, sizeof(DataSubchunk), 1, fp);
    fwrite(stereo, sizeof(short), N*fmt.numChannels, fp); 
    
	free(stereo);
    fclose(fp);
    return 0;
}





