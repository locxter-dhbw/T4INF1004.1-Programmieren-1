#include <stdio.h>
#include <stdlib.h>
#include "helper.h"

int max(int i1, int i2) {
    return i1 > i2 ? i1 : i2;
}

int main_2(void) {
    int z = 1, x = 2;
    int erg = max(2, 3);
    printf("%d\n", erg);
    return 0;
}