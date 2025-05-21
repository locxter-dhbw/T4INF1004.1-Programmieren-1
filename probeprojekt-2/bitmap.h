#ifndef BITMAP_H
#define BITMAP_H
	#include <stdio.h>
	#include <stdlib.h>
	#include <ctype.h>
	#include <string.h>

	// Sicherstellen, dass Structs korrekt gepackt werden
	#pragma pack(1)
	
	// Fehlende Typen definieren
	#define int16_t short
	#define uint16_t unsigned short
	#define int32_t int
	#define uint32_t unsigned int

	// Structs für Dateikopf und Dateiinfo erstellen
	typedef struct {
		uint16_t bfType;
		uint32_t bfSize;
		uint32_t bfReserved;
		uint32_t bfOffBits;
	} BITMAPFILEHEADER;

	typedef struct {
		uint32_t biSize;
		int32_t biWidth;
		int32_t biHeight;
		uint16_t biPlanes;
		uint16_t biBitCount;
		uint32_t biCompression;
		uint32_t biSizeImage;
		int32_t biXPelsPerMeter;
		int32_t biYPelsPerMeter;
		uint32_t biClrUsed;
		uint32_t biClrImportant;
	} BITMAPINFOHEADER;

	// Speicher muss manuell freigegeben werden
	char *readInput(char *inputFilename);

	long getInputSize(char *inputFilename);

	long getInputPixels(long inputSize);

	long getOutputWidth(long inputSize);

	long getOutputSize(long inputSize);

	// Speicher muss manuell freigegeben werden
	char *generateBmp(char *inputData, long inputSize);

	void writeBmp(char *outputFilename, char *outputData, long outputSize, long outputWidth);

#endif //BITMAP_H
