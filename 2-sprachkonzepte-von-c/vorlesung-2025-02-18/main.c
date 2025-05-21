#include <stdio.h>
#include "klaus.h"


/*
 *
 * HIER KRACHT ES GANZ GEWLALTIG!!!!
 *
*/
/*
void offsetGPS(PGPS pgps, float offset);
void X11();
void X22(); // Compiler weiß jetzt, dass es diese Funktion gibt - erst der Linker muss die Implementierung finden

int main1(void) {
    X11();
    GPS gps = {1.23345f, 4.12345f};
    offsetGPS(&gps, 1.5f);
    printf("Hello, World!\n");
    return 0;
}

void offsetGPS(PGPS pgps, float offset) {
    pgps->latitude += offset;
    pgps->longitude += offset;
}

void X11() {
    X22();
    printf("x11");
    int x = 5;
}
*/