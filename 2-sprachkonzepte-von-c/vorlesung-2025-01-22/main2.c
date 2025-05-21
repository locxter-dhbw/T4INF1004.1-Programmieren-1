#include <stdio.h>

void printArrayContentSmartButWrong(int ia[]);

void printArrayContent(int ia[], int len);

int main2(void) {
    int i[] = {1, 2, 3, 4, 5, 6};
    int len = sizeof(i) / sizeof(int);
    printArrayContentSmartButWrong(i);
    printArrayContent(i, len);
    return 0;
}

// Geht nicht, da nur Speicheradresse übergeben wird
void printArrayContentSmartButWrong(int ia[]) {
    int len = sizeof(ia) / sizeof(int);
    printf("Größe Array: %d\n", sizeof(ia));
    printf("Größe Element: %d\n", sizeof(int));
    printf("Funktion bekommt nur Speicheradresse vom Array übergeben, die hier 64 Bit hat.\n");
    printf("Integers haben 32 Bit, daher ergeben sich 2 Elemente \"Länge des Arrays\".\n");
    for (int i = 0; i < len; ++i) {
        printf("%d ", ia[i]);
    }
    printf("\n");
}

void printArrayContent(int ia[], int len) {
    for (int i = 0; i < len; ++i) {
        printf("%d ", ia[i]);
    }
    printf("\n");
}