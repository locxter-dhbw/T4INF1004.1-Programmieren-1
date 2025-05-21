#include <stdio.h>

void someFunc(int ia[][3]);

void someFuncCompiler(int (*ia)[3]);

int main(void) {
    int ia[] = {0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff};
    int *pi = ia;
    char *pc = 0;
    short *ps = 0;
    // Integer halbschrittig durch Short-Pointer durchgehen
    for (int i = 0; i < sizeof(ia) / sizeof(int); ++i) {
        printf("%#x\n", *pi);
        ps = pi;
        // 8899 in die niederen 4 Bit schreiben
        *ps = 0x8899;
        printf("%#x\n", *pi);
        // Um Short-Größe erhöhen (halbes Integer)
        ps++;
        // 1122 in die höheren 4 Bit schreiben
        *ps = 0x1122;
        printf("Short Pointer: %p\n", ps);
        printf("Int Pointer: %p\n", pi);
        printf("%#x\n", *pi);
        pi++;
    }
    // Pointer um 1 Byte durch explizite Typkonvertierung inkrementieren
    // (normale Datentypen werden einfach inkrementiert, für Speicher ist Byte die kleinste Einehit)
    printf("Pointer: %p\n", pi);
    printf("Wert: %#x\n", *pi);
    long l = (long) pi;
    l++;
    pi = (int*) l;
    printf("Pointer: %p\n", pi);
    printf("Wert: %#x\n", *pi);
    // Void-Pointer - kann auf jeden Datentyp zeigen (wird immer um 1 Byte inkrementiert)
    // void v; Gibt es nicht
    void *vp;
    vp = pc;
    // Pointer auf Pointer
    int ia2[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    someFunc(ia2);
    someFuncCompiler(ia2);
    return 0;
}

void someFunc(int ia[][3]) {
    printf("ia[0][0]: %d\n", ia[0][0]);
}

void someFuncCompiler(int (*ia)[3]) {
    printf("ia[0][0]: %d\n", *ia[0]); // Erste Zeile
    printf("ia[1][0]: %d\n", *ia[1]); // Zweite Zeile
    printf("ia[2][0]: %d\n", *ia[2]); // Dritte Zeile
}