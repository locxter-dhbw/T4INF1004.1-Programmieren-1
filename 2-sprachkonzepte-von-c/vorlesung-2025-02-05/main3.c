#include <stdio.h>

void swapValues(int *p1, int *p2);

void swapPointers(int *p1, int *p2);

void swapPointersOfPointers(int **pp1, int **pp2);

int main3(void) {
    int x1 = 1;
    int x2 = 2;
    int *p1 = &x1;
    int *p2 = &x2;
    printf("%d\n", x1);
    printf("%d\n", x2);
    printf("%d\n", *p1);
    printf("%d\n\n", *p2);
    swapValues(p1, p2);
    printf("%d\n", x1);
    printf("%d\n", x2);
    printf("%d\n", *p1);
    printf("%d\n\n", *p2);
    // Geht nicht, da Zeiger selbst als Call by Value
    swapPointers(p1, p2);
    printf("%d\n", x1);
    printf("%d\n", x2);
    printf("%d\n", *p1);
    printf("%d\n\n", *p2);
    // Lösung zum Zeigervertauschen: Zeiger auf Zeiger
    swapPointersOfPointers(&p1, &p2);
    printf("%d\n", x1);
    printf("%d\n", x2);
    printf("%d\n", *p1);
    printf("%d\n", *p2);

    return 0;
}

// Werte der Pointer tauschen
void swapValues(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

// Versuchen die im Pointer gespeicherte Adresse zu ändern (geht nicht, da Pointer selbst Call by Value sind)
void swapPointers(int *p1, int *p2) {
    int *temp = p1;
    p1 = p2;
    p2 = temp;
}

// In den Pointer gespeicherte Adresse tauschen durch Pointer auf Pointer (Call by Reference)
void swapPointersOfPointers(int **pp1, int **pp2) {
    int *temp = *pp1;
    *pp1 = *pp2;
    *pp2 = temp;
}