/*#include <stdio.h>

typedef struct Rechner {
    int a;
    int b;
    int (*add)(int, int);
    int (*mult)(int, int);
} Rechner;

int add(int a, int b);
int mult(int a, int b);

const Rechner RechnerDefault = {0, 0, add, mult};

int main13(void) {
    Rechner foo = RechnerDefault;
    foo.a = 5;
    foo.b = 3;
    printf("%d\n", foo.add(foo.a, foo.b));
    printf("%d\n", foo.mult(foo.a, foo.b));
    return 0;
}

int add(int a, int b) {
    return a + b;
}

int mult(int a, int b) {
    return a * b;
}*/
