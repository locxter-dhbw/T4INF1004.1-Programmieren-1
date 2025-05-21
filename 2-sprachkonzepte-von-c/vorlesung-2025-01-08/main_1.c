#include <stdio.h>
#include <stdlib.h>
#include "helper.h"

#define MASK_BIT1 0x01
#define MASK_BIT2 0x02
#define MASK_BIT3 0x04
#define MASK_BIT4 0x08

int main(void) {
    // Inkrementierung/Dekrementierung
    int x = 10;
    int y = 0;
    y = ++x;
    printf("%d\n", x);
    printf("%d\n", y);
    x = 10;
    y = x++;
    printf("%d\n", x);
    printf("%d\n", y);
    // Bitorientiere Operatoren
    unsigned char c1 = 0b11111111; // = 0xff
    toBin8(c1);
    // Bei unsigned mit 0, bei signed mit 1 aufgefüllt
    c1 = c1 >> 1;
    toBin8(c1);
    // Immer mit 0 aufgefüllt
    c1 = c1 << 1;
    toBin8(c1);
    c1 = 0x7f; // = 127
    // Vorzeichenbit (hier 0) bleibt aber prinzipiell immer erhalten
    c1 = c1 >> 1;
    toBin8(c1);
    c1 = c1 << 1;
    toBin8(c1);
    // Schnelle Division durch 2er Potenzen
    c1 = 66;
    c1 = c1 >> 1; // c1 durch 2
    printf("%d\n", c1);
    // Teile der 8 Bit betrachten mit Shifts
    toBin8(c1);
    // Höhere 4 Bit
    unsigned char c2 = c1 >> 4;
    toBin8(c2);
    // Niedrigere 4 Bit
    c2 = (c1 << 4);
    c2 = c2 >> 4;
    toBin8(c2);
    // Teile der 8 Bit betrachten mit UND bzw. ODER
    c1 = 0xab; // = 0b10101011
    toBin8(c1);
    // Niedrigere 4 Bit
    c2 = c1 & 0x0f; // 0f = 0b00001111
    toBin8(c2);
    // Höhere 4 Bit
    c2 = (c1 & 0xf0) >> 4; // Bitmaske 0f = 0b00001111
    toBin8(c2);
    // Checken ob ein Bit gesetzt ist
    toBin8(MASK_BIT1);
    if (c2 & MASK_BIT1) {
        printf("Bit 1 gesetzt\n");
    } else {
        printf("Bit 1 nicht gesetzt\n");
    }
    toBin8(MASK_BIT3);
    if (c2 & MASK_BIT3) {
        printf("Bit 3 gesetzt\n");
    } else {
        printf("Bit 3 nicht gesetzt\n");
    }
    // Base64 => 64 = 2^6 Zeichen (A-Z, a-z, 0-9, + und /) immer mit 6 Bitblöcken
    // Ausgabe immer in 4 Zeichenblöcken, auffüllen mit =
    // => Zeichen aufteilen in 6 Bitblöcke
    // '?' = 8 Bit => 6 Bit + 2 Bit
    // "??" = 16 Bit => 6 Bit + 6 Bit + 4 Bit
    // Der Kommaoperator in Bedingungen (nur der letzte Block rechts wird ausgewertet, der Rest nur ausgeführt)
    int z = 1;
    x = 2;
    if (z = 0, z < x) {
        printf("z kleiner x\n");
    }
    // Operatorreihenfolge beachten, aber ganz große Katastrophe
    int o = -(z & 2) + x << 3 * 5;

    return 0;
}