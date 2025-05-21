#include <stdio.h>
#include <stdlib.h>

int main3(void) {
    // Oder noch besser mit SWITCH CASE
    int i;
    printf("Wert eingeben:\n");
    scanf("%d", &i);
    switch (i) {
        case 10:
            printf("i = 10\n");
            // Hier wird nicht standardmäßig abgebrochen, sondern die restlichen Möglichkeiten auch noch ausgeführt!
        case 20:
            printf("i = 20\n");
            // Um abzubrechen, muss break verwendet werden
            break;
        case 30:
            printf("i = 30\n");
            break;
        default:
            printf("i = irgendwas anderes\n");
            break;
    }
    return 0;
}
