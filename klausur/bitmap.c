#include "bitmap.h"

// Kündigungsgrund, aber warum auch immer notwendig für diese Datei
char secretHeaderPart[14];

// Speicher muss manuell wieder freigegeben werden
BITMAP *readBmp(char *filename) {
    // Datei öffnen
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Input-Datei konnte nicht geöffnet werden\n");
        exit(1);
    }
    // Dateigröße in Byte berechnen
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);

    // Dirty Fix für den geheimen Teil des Headers
    fseek(file, 55, SEEK_SET);
    fread(secretHeaderPart, sizeof(char), 14, file);
    rewind(file);
    // Fix Ende

    // Daten einlesen
    BITMAP *bitmap = malloc(sizeof(BITMAP));
    if (bitmap == NULL) {
        printf("Input-Datei konnte nicht geöffnet werden\n");
        free(bitmap);
        fclose(file);
        exit(1);
    }
    size_t read = fread(&bitmap->fileHeader, 1, sizeof(BITMAPFILEHEADER), file);
    if (read < sizeof(BITMAPFILEHEADER)) {
        printf("Input-Datei konnte nicht geöffnet werden\n");
        free(bitmap);
        fclose(file);
        exit(1);
    }
    read = fread(&bitmap->infoHeader, 1, sizeof(BITMAPINFOHEADER), file);
    if (read < sizeof(BITMAPINFOHEADER)) {
        printf("Input-Datei konnte nicht geöffnet werden\n");
        free(bitmap);
        fclose(file);
        exit(1);
    }
    // Speicher für Bilddaten reservieren und initialisieren
    long dataSize = size - bitmap->fileHeader.bfOffBits;
    uint16_t *data = malloc(dataSize);
    if (data == NULL) {
        printf("Input-Datei konnte nicht geöffnet werden\n");
        free(bitmap);
        free(data);
        fclose(file);
        exit(1);
    }
    memset(data, 0, dataSize);
    // Bilddaten einlesen (erst zur richtigen Position springen)
    rewind(file);
    fseek(file, bitmap->fileHeader.bfOffBits, SEEK_SET);
    read = fread(data, 1, dataSize, file);
    if (read < sizeof(dataSize)) {
        printf("Input-Datei konnte nicht geöffnet werden\n");
        free(bitmap);
        free(data);
        fclose(file);
        exit(1);
    }
    bitmap->data = data;
    bitmap->pixelCount = dataSize / 2;
    fclose(file);
    return bitmap;
}

void printInfoBmp(BITMAP bitmap) {
    printf("Bild Info:\n");
    printf("biCompression:\t");
    switch (bitmap.infoHeader.biCompression) {
        case 0:
            printf("BI_RGB");
            break;
        case 1:
            printf("BI_RLE8");
            break;
        case 2:
            printf("BI_RLE4");
            break;
        case 3:
            printf("BI_BITFIELDS");
            break;
        default:
            printf("Unbekannt");
            break;
    }
    printf("\nbiBitCount:\t%d Bit\n", bitmap.infoHeader.biBitCount);
    printf("biHeight:\t%d px\n", bitmap.infoHeader.biHeight);
    printf("biWidth:\t%d px\n", bitmap.infoHeader.biWidth);
    printf("biSizeImage:\t%d Byte\n", bitmap.infoHeader.biSizeImage);
}

// Speicher muss manuell wieder freigegeben werden
void invertBmp(BITMAP *bitmap) {
    if (bitmap->infoHeader.biBitCount != 16) {
        printf("Bild verwendet keine 16 Bit Farbkodierung!\n");
        free(bitmap);
        exit(1);
    }
    for (int i = 0; i < bitmap->pixelCount; ++i) {
        // Alle Subpixel invertieren
        bitmap->data[i] = ~bitmap->data[i];
    }
}

// Kleiner Helfer für die Entwicklung der Invertierung
void printBin(uint16_t num) {
    printf("%d", num >> 15 & 1);
    printf("%d", num >> 14 & 1);
    printf("%d", num >> 13 & 1);
    printf("%d", num >> 12 & 1);
    printf("%d", num >> 11 & 1);
    printf("%d", num >> 10 & 1);
    printf("%d", num >> 9 & 1);
    printf("%d", num >> 8 & 1);
    printf("%d", num >> 7 & 1);
    printf("%d", num >> 6 & 1);
    printf("%d", num >> 5 & 1);
    printf("%d", num >> 4 & 1);
    printf("%d", num >> 3 & 1);
    printf("%d", num >> 2 & 1);
    printf("%d", num >> 1 & 1);
    printf("%d\n", num & 1);
}

// Speicher muss manuell wieder freigegeben werden
void invertRedBmp(BITMAP *bitmap) {
    if (bitmap->infoHeader.biBitCount != 16) {
        printf("Bild verwendet keine 16 Bit Farbkodierung!\n");
        free(bitmap);
        exit(1);
    }
    for (int i = 0; i < bitmap->pixelCount; ++i) {
        // Nur rote Subpixel invertieren
        uint16_t invertedRed = bitmap->data[i] >> 11;
        invertedRed = ~invertedRed;
        invertedRed = invertedRed << 11;
        uint16_t greenBlue = bitmap->data[i] << 5;
        greenBlue = greenBlue >> 5;
        bitmap->data[i] = invertedRed | greenBlue;
    }
}

// Speicher muss manuell wieder freigegeben werden
void invertGreenBmp(BITMAP *bitmap) {
    if (bitmap->infoHeader.biBitCount != 16) {
        printf("Bild verwendet keine 16 Bit Farbkodierung!\n");
        free(bitmap);
        exit(1);
    }
    for (int i = 0; i < bitmap->pixelCount; ++i) {
        // Nur grüne Subpixel invertieren
        // Natürlich auch anders möglich, aber ich mag isolieren, Operation anwenden und zusammenführen (auch wenn's langsam ist)
        uint16_t invertedGreen = ~bitmap->data[i] << 5;
        invertedGreen = invertedGreen >> 10;
        invertedGreen = invertedGreen << 5;
        uint16_t red = bitmap->data[i] >> 11;
        red = red << 11;
        uint16_t blue = bitmap->data[i] << 11;
        blue = blue >> 11;
        bitmap->data[i] = red | invertedGreen | blue;
    }
}

// Speicher muss manuell wieder freigegeben werden
void invertBlueBmp(BITMAP *bitmap) {
    if (bitmap->infoHeader.biBitCount != 16) {
        printf("Bild verwendet keine 16 Bit Farbkodierung!\n");
        free(bitmap);
        exit(1);
    }
    for (int i = 0; i < bitmap->pixelCount; ++i) {
        // Nur rote Subpixel invertieren
        uint16_t invertedBlue = bitmap->data[i] << 11;
        invertedBlue = ~invertedBlue;
        invertedBlue = invertedBlue >> 11;
        uint16_t redGreen = bitmap->data[i] >> 5;
        redGreen = redGreen << 5;
        bitmap->data[i] = invertedBlue | redGreen;
    }
}

// Speicher muss manuell wieder freigegeben werden
void rotateBmp(BITMAP *bitmap) {
    // Speicher für gedrehtes Bild reservieren
    uint16_t *rotatedData = malloc(bitmap->pixelCount * 2);
    if (rotatedData == NULL) {
        printf("Bild konnte nicht gedreht werden\n");
        free(bitmap);
        free(rotatedData);
        exit(1);
    }
    memset(rotatedData, 0, bitmap->pixelCount);
    // Bild drehen
    for (int i = 0; i < bitmap->infoHeader.biHeight; ++i) {
        for (int j = 0; j < bitmap->infoHeader.biWidth; ++j) {
            // Alternativ auch über Arrays-Notation möglich, aber keine Lust die Datentypen zu ändern
            *(rotatedData + bitmap->infoHeader.biHeight * j + i) = *(bitmap->data + bitmap->infoHeader.biWidth * i + j);
        }
    }
    // Header drehen
    int32_t biWidth = bitmap->infoHeader.biWidth;
    bitmap->infoHeader.biWidth = bitmap->infoHeader.biHeight;
    bitmap->infoHeader.biHeight = biWidth;
    // Bild austauschen
    free(bitmap->data);
    bitmap->data = rotatedData;
}

void writeBmp(char *filename, BITMAP bitmap) {
    // Datei öffnen
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Output-Datei konnte nicht geöffnet werden\n");
        free(&bitmap);
        fclose(file);
        exit(1);
    }

    // Dirty Fix für den geheimen Teil des Headers
    fseek(file, 55, SEEK_SET);
    fwrite(secretHeaderPart, 14, 1, file);
    rewind(file);
    // Fix Ende

    // Daten in Bilddatei schreiben (Bilddaten nach biOffBits)
    fwrite(&bitmap.fileHeader, sizeof(BITMAPFILEHEADER), 1, file);
    fwrite(&bitmap.infoHeader, sizeof(BITMAPINFOHEADER), 1, file);
    rewind(file);
    fseek(file, bitmap.fileHeader.bfOffBits, SEEK_SET);
    fwrite(bitmap.data, bitmap.infoHeader.biSizeImage, 1, file);
    fclose(file);
}

void freeBmp(BITMAP *bitmap) {
    if (bitmap == NULL) return;
    free(bitmap->data);
    free(bitmap);
}
