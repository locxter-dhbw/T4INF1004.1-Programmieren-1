#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Variablen erstellen
    int i = 12345; // Dez
    int j = 0xaabbccdd; // Hex
    int k = 01234; // Oktal
    float f = 3.1418f; // Float
    // Ausgabe mit printf
    printf("Ausgabe i: %d\n", i); // Dez
    printf("Ausgabe j: %o\n", i); // Octal
    printf("Ausgabe k: %x\n", i); // Hex klein
    printf("Ausgabe k: %X\n", i); // Hex groß
    printf("Ausgabe i: %d\n", j); // Dez
    printf("Ausgabe j: %o\n", j); // Octal
    printf("Ausgabe k: %x\n", j); // Hex klein
    printf("Ausgabe k: %X\n", j); // Hex groß
    // Mehrere Werte in einer Zeile
    printf("Ausgabe j: 0x%X ud Ausgabe i: %d und Ausgabe f: %f\n", j, i, f);
    // Formatierung von Ausgaben
    printf("float f:%07.3f\n", 1234.56789);
    printf("float f:%07.6f\n", 1234.56789);
    printf("float f:%02.3f\n", 1234.5); // Wert vor dem Komma priorisiert vor Nachkommastellen vor Gesamtlänge
    // Einlesen mit scanf (über die Adresse der Variable, daher das Prozentzeichen)
    scanf("%d", &i);
    printf("Ausgabe i: %d\n", i);
    scanf("%d %d", &i, &j);
    printf("Ausgabe i: %d\n", i);
    printf("Ausgabe j: %d\n", j);
    return 0;
}