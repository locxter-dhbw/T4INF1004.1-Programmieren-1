/*#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char stadt[32];
    int plz;
} Adresse;

typedef struct {
    char name[32];
    int alter;
    Adresse adresse;
} Person;

int main12(void) {
    int size = 0;
    scanf("%d", &size);
    if (size <= 0) return -1;
    Person *people = calloc(size, sizeof(Person));
    for (int i = 0; i < size; ++i) {
        (people + i)->alter = 100 - i;
    }
    for (int i = 0; i < size; ++i) {
        printf("%d\n", people[i].alter);
    }
    free(people);
    return 0;
}
*/