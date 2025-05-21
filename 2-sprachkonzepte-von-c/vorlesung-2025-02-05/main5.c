#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int size = 0;
    scanf("%d", &size);
    // Speicher reservieren
    char *p = calloc(size, sizeof(char)); // hier gleich malloc(size)
    // Gültige Speicheradresse prüfen
    if (p == NULL) return -1;
    // Speicher wieder freigeben
    free(p);
    return 0;
}
