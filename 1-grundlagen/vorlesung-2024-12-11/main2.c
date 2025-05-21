#include <stdio.h>
#include <stdlib.h>

int main2(void) {
    // Float nur auf die ersten 6 Stellen genau
    float f1 = 1234.12345f;
    printf("%lu\n", sizeof(1234.12345f));
    printf("%lu\n", sizeof(f1));
    // Ausgabe f1 = 1234.123413 unterscheidet sich von der Eingabe
    printf("%f\n", f1);
    // Geringe Genauigkeit wird bei Division sichtbar
    f1 = 10.0f / 3.0f;
    printf("%f\n", f1);
    f1 = 10.0 / 3.0;
    printf("%f\n", f1);
    // Daher Gleichheit sollte bei Floats/Doubles nicht direkt verglichen werden
    // Nur übers Interval prüfen (Werte unterscheiden sich höchstens um Ungenauigkeit)
    return 0;
}