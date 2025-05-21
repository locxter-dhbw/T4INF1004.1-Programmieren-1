#include "bitmap.h"

#define MATRIKELNUMMER "1330251"

typedef enum { INFO, INVERT, INVERT_RED, INVERT_GREEN, INVERT_BLUE, ROTATE, ERROR } Mode;

void printArgumentError();

/*
 * Verwendung:
 * Alle Farben invertieren:         in.bmp out.bmp invert
 * Eine Farbe invertieren:          in.bmp out.bmp invert [blau|rot|gruen]
 * Bild um 90° nach links rotieren: in.bmp out.bmp rotate
 * Informationen zum Bild ausgeben: in.bmp info
 */

int main(int argc, char **argv) {
    // Kommandzeilenargumente einlesen
    Mode mode = ERROR;
    char *inputFilename = NULL;
    char *outputFilename = NULL;
    if (argc == 3) {
        // Info ausgeben
        inputFilename = argv[1];
        if (!strcmp(argv[2], "info")) mode = INFO;
    } else if (argc == 4) {
        // Alle Farben invertieren oder drehen
        inputFilename = argv[1];
        outputFilename = argv[2];
        if (!strcmp(argv[3], "invert")) mode = INVERT;
        else if (!strcmp(argv[3], "rotate")) mode = ROTATE;
    } else {
        // Eine Farbe invertieren
        inputFilename = argv[1];
        outputFilename = argv[2];
        if (!strcmp(argv[3], "invert")) {
            if (!strcmp(argv[4], "rot")) mode = INVERT_RED;
            else if (!strcmp(argv[4], "gruen")) mode = INVERT_GREEN;
            else if (!strcmp(argv[4], "blau")) mode = INVERT_BLUE;
        }
    }
    if (mode == ERROR) {
        printArgumentError();
        return 1;
    }
    // Eigentliche Verarbeitung durchführen
    BITMAP *bitmap = readBmp(inputFilename);
    if (mode == INFO) {
        // Info ausgeben
        printInfoBmp(*bitmap);
    } else {
        // Verarbeitung durchführen
        switch (mode) {
            case INVERT:
                invertBmp(bitmap);
                break;
            case INVERT_RED:
                invertRedBmp(bitmap);
                break;
            case INVERT_GREEN:
                invertGreenBmp(bitmap);
                break;
            case INVERT_BLUE:
                invertBlueBmp(bitmap);
                break;
            case ROTATE:
                rotateBmp(bitmap);
                break;
            default:
                printArgumentError();
                freeBmp(bitmap);
                return 1;
                break;
        }
        // Datei speichern
        writeBmp(outputFilename, *bitmap);
    }
    freeBmp(bitmap);
    // Some more fun
    printf("Und weil der Code an sich jetzt funktioniert, hier noch ein paar Spielereien, um den Nutzer bei Laune zu halten:\n");
    printf("Ist 3 gerade? %s\n", 3 % 2 ? "Ja" : "Nein");
    printf("Ich zähle bis 10 hoch:\n");
    int i = 0;
    while (i < 11) {
        printf("%d ", i);
        i++;
    }
    printf("\nUnd ich auch:\n");
    i = 0;
    do {
        printf("%d ", i);
        i++;
    } while (i < 11);
    printf("\nIch bin ein mehrdimensionales Array mit vielen tollen Werten:\n");
    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("Ich wurde von der Matrikelnummer %s entwickelt :)", MATRIKELNUMMER);
    return 0;
}

void printArgumentError() {
    printf("Bitte mindestens zwei Parameter und eine der folgenden Kombinationen eingeben:\n");
    printf("in.bmp info\n");
    printf("in.bmp out.bmp invert\n");
    printf("in.bmp out.bmp invert [blau|rot|gruen]\n");
    printf("in.bmp neu.bmp rotate\n");
}
