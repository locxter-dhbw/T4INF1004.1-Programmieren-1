/*#include <stdio.h>

typedef struct {
    char stadt[32];
    int plz;
} Adresse;

typedef struct {
    char name[32];
    int alter;
    Adresse adresse;
} Person;

int main7(void) {
    Person people[3] = {
        {"Max", 18, "Musterstadt", 12345},
        {"Louis", 19, "Musterstadt", 54321},
        {"Bernd", 51, "Musterstadt", 12345},
    };
    for (int i = 0; i < sizeof(people) / sizeof(people[0]); ++i) {
        printf("%s %d, %d %s\n", people[i].name, people[i].alter, people[i].adresse.plz, people[i].adresse.stadt);
    }
    return 0;
}*/