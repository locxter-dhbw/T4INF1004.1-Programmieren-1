#include <stdio.h>

#define NULL 0

void swapNotWorking(int i, int j) {
    int tmp = j;
    j = i;
    i = tmp;
    printf("%d %d\n", i, j);
}

void swap(int *i, int *j) {
    int tmp = *j;
    *j = *i;
    *i = tmp;
    printf("%d %d\n", *i, *j);
}

int main3(void) {
    // In y liegt die Adresse eines Integers, hat folglich sizeof 8 (= 64 Bit) wegen 64 Bit System
    int *py;
    // In c liegt die Adresse eines Char, hat folglich sizeof 8 (= 64 Bit) wegen 64 Bit System
    char *pc;
    int y = 0xab;
    char c = 'a';
    // Addressen in der Pointenr ablegen
    py = &y;
    pc = &c;
    // Paar Sachen ausgeben
    printf("Länge von py: %d\n", sizeof(py));
    printf("Adresse von y: %p\n", py);
    printf("Wert von y über den Pointer: %#x\n", *py);
    printf("Länge von pc: %d\n", sizeof(pc));
    printf("Adresse von c: %p\n", pc);
    printf("Wert von c über den Pointer: %c\n", *pc);
    // Werte von c manipulieren
    *pc = 'b';
    printf("Wert von c: %c\n", c);
    printf("Wert von c über den Pointer: %c\n", *pc);
    // Grenzen von Call by Value
    int x = 20;
    y = 10;
    swapNotWorking(x, y);
    printf("%d %d\n", x, y);
    // Pointer für Call by Reference
    swap(&x, &y);
    printf("%d %d\n", x, y);
    // Arrays sind auch Pointer (und andersrum), da folgender Code valide ist
    char wort[] = "Hallo Welt";
    pc = wort;
    pc[4] = 'a'; // = *(pc + 4)
    printf("%s\n", wort);
    // Zeiger incrementieren
    pc = wort;
    pc = pc + 3;
    *pc = 'c';
    printf("%s\n", wort);
    // NULL-Pointer
    py = NULL;
    return 0;
}