#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mainbinaer(void) {
    // 232 = 1110 1000
    // 345 = 0000 0001 0101 1001
    unsigned int num = 345;
    int size = sizeof(num) * 8;
    char *output = malloc(size);
    if (output == NULL) return 1;
    memset(output, '\0', size);
    for (int i = size - 1; i >= 0; i--) {
        // Schauen ob Stelle 2^i bei num gesetzt ist (gibt 2^i als Wert, daher nochmal nach rechts schiften)
        if ((num & (1 << i)) >> i) {
            output[size - i - 1] = '1';
        } else {
            output[size - i - 1] = '0';
        }
        // ODER NOCHT KÜRZER, aber Kündigung
        output[size - i - 1] = '0' + ((num & (1 << i)) >> i);
    }
    printf("%s\n", output);
    free(output);
    return 0;
}
