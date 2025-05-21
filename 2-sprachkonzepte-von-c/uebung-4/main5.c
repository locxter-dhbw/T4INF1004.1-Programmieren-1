/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[32];
    int alter;
} Person;

void printPersonPointer(Person *p);

int main5(void) {
    Person *max = malloc(sizeof(Person));
    strcpy(max->name, "Max");
    max->alter = 18;
    printPersonPointer(max);
    free(max);
    return 0;
}

void printPersonPointer(Person *p) {
    printf("%s, %d\n", p->name, p->alter);
}*/