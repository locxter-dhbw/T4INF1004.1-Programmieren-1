#include <stdio.h>

// Symbolische Konstanten definieren
#define INT int
#define FUNKTION bar()
#define KLAMMER_AUF {
#define KLAMMER_ZU }
// Define-Makro
#define print(a) printf(#a)

// Funktion deklarieren
void FUNKTION;

int main1(void) {
    // Variablen deklarieren
    int x;
    float y, z;
    // Variable initialisieren
    x = 1;
    // Variable überschreiben (32 Bit in Hex)
    x = 0xaabbccdd;
    // Einfaches Zeichenliteral (char)
    'g';
    // Zeichenkettenliteral (char-Array)
    "gog";
    // Symbolische Konstante benutzen
    INT foo = 5;
    FUNKTION;
    print(Functional\n);
    // Sample code
    printf("Hello, World!\n");
    return 0;
}

// Funktion implementieren
void FUNKTION KLAMMER_AUF
    printf("Cursed\n");
KLAMMER_ZU