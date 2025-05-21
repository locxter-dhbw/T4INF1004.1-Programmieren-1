#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Analoge WHILE Schleife
    int i = 0;
    while (i < 10) {
        printf("%d\n", i);
        i++;
    }
    // FOR Schleife (Zählschleife)
    for (int i = 0; i < 10; i++) {
        printf("%d\n", i);
    }
    // Anwendungsbeispiel
    for (int x = 0, y = 10; x <= 10; x++, y--) {
        printf("x = %d, y = %d\n", x, y);
    }
    return 0;
}
