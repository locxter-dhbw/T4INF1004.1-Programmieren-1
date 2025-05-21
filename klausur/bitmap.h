#ifndef BITMAP_H
#define BITMAP_H
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Sicherstellen, dass structs korrekt gepackt werden
#pragma pack(1)

// Strukturen für Bitmap-Daten
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

typedef struct {
    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;
    uint16_t *data;
    long pixelCount;
} BITMAP;

// Speicher muss manuell wieder freigegeben werden
BITMAP *readBmp(char *filename);

void printInfoBmp(BITMAP bitmap);

// Speicher muss manuell wieder freigegeben werden
void invertBmp(BITMAP *bitmap);

// Kleiner Helfer für die Entwicklung der Invertierung
void printBin(uint16_t num);

// Speicher muss manuell wieder freigegeben werden
void invertRedBmp(BITMAP *bitmap);

// Speicher muss manuell wieder freigegeben werden
void invertGreenBmp(BITMAP *bitmap);

// Speicher muss manuell wieder freigegeben werden
void invertBlueBmp(BITMAP *bitmap);

// Speicher muss manuell wieder freigegeben werden
void rotateBmp(BITMAP *bitmap);

void writeBmp(char *filename, BITMAP bitmap);

void freeBmp(BITMAP *bitmap);
#endif //BITMAP_H
