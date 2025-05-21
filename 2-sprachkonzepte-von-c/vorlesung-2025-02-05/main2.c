#include <stdio.h>

// Perverse Kacke mit übereinander gelegtem Speicher
union Ui {
    int i;
    char c;
    double d;
};

// Dafür sind enums wunderschön hi hi
enum Zahl {
    _NULL,
    EINS,
    ZWEI,
    DREI,
    VIER
};

enum Farben {
    rot, // = 0
    gelb = 6,
    blau, // = 7
    gruen = 1
};

typedef struct {
    int plz;
    int hausnummer;
    char strasse[20];
    char ort[20];
} Adresse, *PAdresse;

int main2(void) {
    // Unions
    union Ui u1;
    u1.i = 0xabbccdd;
    printf("%d\n", u1.i);
    printf("%c\n", u1.c);
    printf("%lf\n", u1.d);
    u1.c = 123;
    printf("%d\n", u1.i);
    printf("%c\n", u1.c);
    printf("%lf\n", u1.d);
    u1.d = 123.0;
    printf("%d\n", u1.i);
    printf("%c\n", u1.c);
    printf("%lf\n", u1.d);
    // Enums
    enum Zahl zahl = ZWEI;
    printf("%d\n", zahl);
    printf("%d\n", gruen);
    return 0;
}
