#include "bitmap.h"

// Speicher muss manuell freigegeben werden
char *readInput(char *inputFilename) {
    // Datei öffnen
    FILE *inputFile = fopen(inputFilename, "r");
    if (inputFile == NULL) {
        printf("Input-Datei konnte nicht geöffnet werden.\n");
        exit(1);
    }
    // Dateigröße berechnen
    fseek(inputFile, 0, SEEK_END);
    long inputSize = ftell(inputFile);
    rewind(inputFile);
    // Speicher reservieren
    char *inputData = malloc(inputSize * sizeof(char));
    if (inputData == NULL) {
        printf("Input-Datei konnte nicht geöffnet werden.\n");
        exit(1);
    }
    // Mit Nullen initialisieren
    memset(inputData, 0, inputSize);
    size_t inputRead = fread(inputData, sizeof(char), inputSize, inputFile);
    if (inputRead < inputSize) {
        printf("Input-Datei konnte nicht geöffnet werden.\n");
        exit(1);
    }
    fclose(inputFile);
    return inputData;
}

// Raw byte size
long getInputSize(char *inputFilename) {
    FILE *inputFile = fopen(inputFilename, "r");
    if (inputFile == NULL) {
        printf("Input-Datei konnte nicht geöffnet werden.\n");
        exit(1);
    }
    fseek(inputFile, 0, SEEK_END);
    long inputSize = ftell(inputFile);
    rewind(inputFile);
    fclose(inputFile);
    return inputSize;
}

// Number of pixels (3 byte (chars) result in one pixel)
long getInputPixels(long inputSize) {
    if (inputSize % 3 == 0) return inputSize / 3;
    return inputSize / 3 + 1;
}

// Number of horizontal pixels
long getOutputWidth(long inputSize) {
    long outputWidth = 0;
    long inputPixels = getInputPixels(inputSize);
    while (outputWidth * outputWidth < inputPixels) {
        outputWidth++;
    }
    return outputWidth;
}

// Raw byte size
long getOutputSize(long inputSize) {
    long outputWidth = getOutputWidth(inputSize);
    return outputWidth * outputWidth * 3;
}

// Speicher muss manuell freigegeben werden
char *generateBmp(char *inputData, long inputSize) {
    // Größe des zu erstellenden Bitmaps ermitteln
    long outputSize = getOutputSize(inputSize);
    char *outputData = malloc(outputSize);
    if (outputData == NULL) {
        printf("Output-Datei konnte nicht erstellt werden.\n");
        exit(1);
    }
    // Mit Nullen initialisieren
    memset(outputData, 0, inputSize);
    // Pixel beschreiben (Padding am Ende, wird oben dargestellt, da Bild von unten nach oben gezeichnet wird)
    for (long i = 0; i < inputSize; i++) {
        outputData[i] = inputData[i];
    }
    // Filtern der Pixel
    for (long i = 0; i < outputSize; i++) {
        unsigned char buf = outputData[i];
        switch (i % 3) {
            // Little Endian, daher vertauscht (anstatt RGB aka 012 gilt BGR 210 fürs Modulo)
            case 2:
                // Rot => binär invertiert
                buf = ~buf;
                break;
            case 1:
                // Grün => oberen und unteren 4 Bit vertauschen (unteren nach links verschieben, oberen nach rechts)
                unsigned char upper = buf >> 4;
                unsigned char lower = buf << 4;
                buf = upper | lower;
                break;
            default:
                // Blau => Bits im Kreis nach rechts verschieben
                unsigned char right = buf >> 2;
                unsigned char overflow = buf << 6;
                buf = overflow | right;
                break;
        }
        outputData[i] = buf;
    }
    return outputData;
}

void writeBmp(char *outputFilename, char *outputData, long outputSize, long outputWidth) {
    BITMAPFILEHEADER fileHeader = {
        0x4d42, // Little Endian, daher andersherum
        sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + outputSize,
        0,
        sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER)
    };
    BITMAPINFOHEADER infoHeader = {
        sizeof(BITMAPINFOHEADER),
        outputWidth, // Sollte eigentlich auch Little Endian sein, aber geht dann net KP
        outputWidth,
        1,
        24,
        0,
        0,
        0,
        0,
        0,
        0,
    };
    // Daten in Bilddatei ausgeben
    FILE *outputFile = fopen(outputFilename, "wb");
    if (outputFile == NULL) {
        printf("Output-Datei konnte nicht geöffnet werden.\n");
        exit(1);
    }
    fwrite(&fileHeader, sizeof(fileHeader), 1, outputFile);
    fwrite(&infoHeader, sizeof(infoHeader), 1, outputFile);
    fwrite(outputData, sizeof(char), outputSize, outputFile);
    fclose(outputFile);
}
