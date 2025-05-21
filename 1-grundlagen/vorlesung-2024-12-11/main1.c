#include <stdio.h>
#include <stdlib.h>
#include "helper.h"

int main1(void) {
    char c1;
    c1 = 0;
    toBin8(c1);
    // Alte Compiler können nicht gleichzeitig Deklaration & Initialisierung; ab C99 aber auf jeden Fall
    char c2 = 1;
    toBin8(c2);
    // c1 = 112 (Vorzeichenbit nicht gesetzt)
    c1 = 0x70;
    toBin8(c1);
    // c1 = -128 (Vorzeichenbit gesetzt)
    c1 = 0x80;
    toBin8(c1);
    // c2 = -127
    c2 = c1 + 1;
    toBin8(c2);
    // Char ohne Vorzeichen
    unsigned char c3 = 0x80;
    // c2 = -16 in allen Fällen
    c2 = 0xf0;
    toBin8(c2);
    c2 = -16;
    toBin8(c2);
    c2 = 240;
    toBin8(c2);
    // c3 = 240 in allen Fällen
    c3 = 0xf0;
    toBin8(c3);
    c3 = -16;
    toBin8(c3);
    c3 = 240;
    toBin8(c3);
    // c2 = 127
    c2 = 0x7f;
    toBin8(c2);
    // c2 springt ins Negative (Vorzeichenbit nicht gesetzt) => c2 = -128
    c2 = c2 + 1;
    toBin8(c2);
    // Besonderheiten von Char ausnutzen
    c2 = 'A';
    toBin8(c2);
    printf("c2: %c\n", c2);
    printf("c2: %d\n", c2);
    c2 = 66;
    toBin8(c2);
    printf("c2: %c\n", c2);
    printf("c2: %d\n", c2);
    c2 = c2 + 1;
    toBin8(c2);
    printf("c2: %c\n", c2);
    printf("c2: %d\n", c2);
    c2 = 'B' - 1;
    toBin8(c2);
    printf("c2: %c\n", c2);
    printf("c2: %d\n", c2);
    // s1 = 378
    short s1 = 0x017a;
    toBin16(s1);
    // s1 (4 Byte) wird auf c4 Länge (2 Byte) zusammengekürzt (niedrigste 2 Byte) => c4 = 122
    char c4 = s1;
    toBin8(c4);
    // Niederwertigen 4 Byte (faff) werden in den Short geschoben
    int i1 = 0x0001faff;
    toBin32(i1);
    s1 = i1;
    toBin16(s1);
    // Auslesen der Speicheraddresse auf einem 64 Bit-System mit eiem 64-Bit Long
    long l1 = 0;
    scanf("%d", &i1);
    l1 = (long) &i1;
    printf("%ld\n", l1);
    // Größe in Byte mit sizeof ermitteln
    printf("Char: %lu\n", sizeof(c1));
    printf("Char: %lu\n", sizeof(char));
    printf("Short: %lu\n", sizeof(s1));
    printf("Int: %lu\n", sizeof(i1));
    printf("Long: %lu\n", sizeof(l1));
    // Jedes normale Literal hat den Speicherbedarf eines Integers (4 Byte)
    printf("sizeof(0x71): %lu\n", sizeof(0x71));
    printf("sizeof(1): %lu\n", sizeof(1));
    // Sonderfall mit einem Long-Literal (8 Byte)
    printf("sizeof(1l): %lu\n", sizeof(1L));
    return 0;
}