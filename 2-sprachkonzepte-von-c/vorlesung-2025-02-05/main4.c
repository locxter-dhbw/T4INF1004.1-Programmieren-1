#include <stdio.h>

// **************************************************************
// HIER MAL WAS NEUES (FUNCTION POINTER + ENTSPRECHENDE TYPEDEFS)
// **************************************************************

typedef struct OptionAusfuehren {
    char name[10];
    // Pointer auf eine Funktion (Pointer auf eine void-Funktion mit int-Parameter)
    void (*f0)(int);
    // Reminder: Pointer auf ein mehrdimensionales int-Array
    // int (*f1)[3];
} OptionAusfuehren;

// Typedef erkennt FP als Funktionsnamen
typedef void (*FP)(int);

typedef enum Tasten {
    Taste1,
    Taste2,
    Taste3,
} Tasten;

void option1(int i);

void option2(int i);

void option3(int i);

int dummy(float a, int b[2]);

int main4(void) {
    // Funktion "aus der Struct" ausführen
    OptionAusfuehren oa;
    oa.f0 = option1;
    oa.f0(2);
    // Kann man auch ohne Structs nehmen
    void (*fx)(int);
    fx = option3;
    fx(2);
    fx = option2;
    fx(2);
    fx = option1;
    fx(2);
    // Etwas komplizierter Function Pointer
    int (*fy)(float, int[3]);
    fy = dummy;
    int bla[] = {1, 2,3};
    int y = fy(3.0, bla);
    // Anwendungsbeispiel (Per Taste ausgeführte Optionen können einfach im Array fernbedienung geswitcht werden)
    FP fernbedienung[] = {option1, option2, option3};
    Tasten taste = 1;
    int wert = 10;
    switch (taste) {
        case Taste1:
                fernbedienung[Taste1](wert);
            break;
        case Taste2:
                fernbedienung[Taste2](wert);
            break;
        case Taste3:
                fernbedienung[Taste3](wert);
            break;
    }
    // ODER noch kürzer
    fernbedienung[taste](wert);
    return 0;
}

void option1(int i) {
    printf("o1 i = %d\n", i);
}

void option2(int i) {
    printf("o2 i = %d\n", i);
}

void option3(int i) {
    printf("o3 i = %d\n", i);
}

int dummy(float a, int b[2]) {
    return 0;
}