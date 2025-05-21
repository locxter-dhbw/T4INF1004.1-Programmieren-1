#include <stdio.h>
#include <stdlib.h>

int main2(void) {
    // Einfache Bedingung (hier immer true)
    if (10) {
        printf("Immer TRUE\n");
    }
    // Mit nur einer Anweisung auch so möglich
    if (10)
        printf("Immer TRUE\n");
    // Das hier ist zwar syntaktisch richtig, aber die if hat keine Auswirkung (das leere Semikolon wird ausgeführt)
    if (0);
    printf("Immer FALSE\n");
    // Hier wird tatsächlich das if überprüft (ist aber natürlich auch immer false)
    if (0)
        printf("Immer FALSE\n");
    // Erste sinnhafte Bedingung
    int i = 1;
    int x = 0;
    scanf("%d", &x);
    if (i - x) {
        printf("Ausdruck ist ungleich 0\n");
    }
    if (i - x > 10 && i) {
        printf("Ausdruck ist größer 10 und i größer 0\n");
    }
    // Gleichzeitige Zuweisungen und Überprüfungen sind möglich, aber muss nicht
    int z = 0;
    if (z = x - 1) {
        printf("Ausdruck ist ungleich 0\n");
    }
    // SONST Fall
    if (x - 1) {
        printf("Ausdruck ist ungleich 0\n");
    } else {
        printf("Ausdruck ist gleich 0\n");
    }
    // Ampel, aber hässlich (r = red, g = green, y = yellow)
    char f = 'r';
    if (f == 'r') {
        printf("HALT STOP\n");
    } else {
        if (f == 'y') {
            printf("NICHT SO TIEF RÜDIGER\n");
        } else {
            printf("LINKE SPUR, ROTER BLITZ\n");
        }
    }
    // Besser mit ELSE IF (beliebig viele)
    if (f == 'r') {
        printf("HALT STOP\n");
    } else if (f == 'y') {
        printf("NICHT SO TIEF RÜDIGER\n");
    } else {
        printf("LINKE SPUR, ROTER BLITZ\n");
    }
    return 0;
}
