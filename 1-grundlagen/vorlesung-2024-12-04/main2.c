#include <stdio.h>
#include <stdlib.h>

// Define-Makro
#define print(a) printf(#a) // a wird in Stringliteral gesetzt
#define printEx(a) printf(a) // a wird eins zu eins eingesetzt

int main2(void) {
    print("a");
    printf("\n");
    int x = 2;
    print("x");
    printf("\n");
    print(x); // Was wird hier ausgegeben? 2 oder x? => x
    printf("\n");
    //printEx(x);
    printf("\n");
    return 0;
}