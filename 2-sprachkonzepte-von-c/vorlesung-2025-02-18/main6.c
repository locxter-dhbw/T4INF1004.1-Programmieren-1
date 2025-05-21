#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    float lng;
    float lat;
} GPS;

int main6(int argc, char **argv) {
    // Binäres Schreiben
    GPS gpsArr[] = {{1.2f, 3.5f}, {2.3f, 5.4f}};
    FILE* file = fopen("gps.dat", "wb");
    fwrite(gpsArr, sizeof(GPS), sizeof(gpsArr) / sizeof(GPS), file); // 2 Elemente von Größe GPS hintereinander
    // ODER einfacher
    fwrite(gpsArr, sizeof(gpsArr), 1, file); // 1 Element von Größe gpsArr hinterinander (Array)
    fclose(file);
    return 0;
}