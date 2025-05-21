/*#include <stdio.h>

typedef struct {
    char stadt[32];
    int plz;
} Adresse;

typedef struct {
    char *name;
    int alter;
    Adresse adresse;
} Person;

int main9(void) {
    Person people[3] = {
        {"Max", 18, "Musterstadt", 12345},
        {"Louis", 19, "Musterstadt", 54321},
        {"Bernd", 51, "Musterstadt", 12345},
    };
    for (int i = 0; i < sizeof(people) / sizeof(people[0]); ++i) {
        printf("%s %d, %d %s\n", people[i].name, people[i].alter, people[i].adresse.plz, people[i].adresse.stadt);
    }
    printf("\n");
    Person *peoplePointer = people;
    for (int i = 0; i < sizeof(people) / sizeof(people[0]); ++i) {
        Person person = *(peoplePointer + i);
        printf("%s %d, %d %s\n", person.name, person.alter, person.adresse.plz, person.adresse.stadt);
    }
    return 0;
}*/