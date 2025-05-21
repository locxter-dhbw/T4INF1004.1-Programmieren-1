#include <stdio.h>
#include <stdlib.h>
#include "helper.h"

// True und False können als Präprozessordirektiven definiert werden
#define true 1
#define false 0

int main(void) {
    // Zuweisung liefern auch Ergebnisse
    int i, j;
    // i == 2 und j == 2
    printf("%d\n", j = 1 + 1);
    i = j = 1 + 1;
    // i == 2 und j == 1
    printf("%d\n", j = 1);
    printf("%d\n", (j = 1) + 1);
    i = (j = 1) + 1;
    // Paar Grundrechenarten
    i = i + 1;
    i = -1;
    i = i - 1;
    // Ganzzahldivision Binär => Bitshift Right
    char c1 = 0x72;
    toBin8(c1);
    c1 = c1 / 2;
    toBin8(c1);
    c1 = c1 / 2;
    toBin8(c1);
    c1 = c1 / 2;
    toBin8(c1);
    //  Ganzzahldivision Binär => Bitshift Right, aber immer 4 Bit (1 Nibble)
    short s1 = 0x7af4;
    toBin16(s1);
    s1 = s1 / 0x10; // bzw. s1 = s1 / 16
    toBin16(s1);
    s1 = s1 / 0x10; // bzw. s1 = s1 / 16
    toBin16(s1);
    s1 = s1 / 0x10; // bzw. s1 = s1 / 16
    toBin16(s1);
    // Modulo (Rest der Ganzzahldivision)
    i = 5 % 2;
    printf("%d\n", i);
    // Letztes Nibble wird ausgegebenen
    s1 = 0x7af4;
    toBin16(s1);
    i = s1 % 0x10;
    toBin16(i);
    // Ergebnis eines Vergleiches ist ein Integer (Katastrophe, aber möglich)
    i = ((1 == 1) + 1) > 2;
    printf("%d\n", i);

    return 0;
}