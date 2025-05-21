#include <stdio.h>
#include <stdlib.h>

int main4(void) {
    int i = 0;
    // Einfache Schleife
    while (i < 10) {
        printf("%d ", i);
        if (i % 2) {
            printf("ist ungerade\n");
        } else {
            printf("ist gerade\n");
        }
        i = i + 1;
    }
    // Endlosschleife
    i = 0;
    while (1) {
        printf("%d\n", i);
        i++;
        if (i > 10) {
            break;
        }
    }
    float f = 0.0f;
    // NIEMALS FLOATS DIREKT VERGLEICHEN (f == 10.0f ist kriminell)
    while (f > 10.0f && 0) {
        printf("f = %f\n", f);
        f += 0.00000002;
    }
    // Bleibt bei 0.500000 stehen
    // DO WHILE (fußgesteuert, läuft immer mindestens einmal)
    i = 10;
    do {
        printf("i = %d\n", i);
        i = i + 1;
    } while (i < 10);
    return 0;
}