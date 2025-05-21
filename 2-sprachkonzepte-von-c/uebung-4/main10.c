/*#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

int main10(void) {
    // Liste manuell erstellen
    Node *head = malloc(sizeof(Node));
    if (head == NULL) return -1;
    head->data = 31;
    head->next = NULL;
    Node n1 = {.data = 42, .next = NULL};
    head->next = &n1;
    Node n2 = {.data = 53, .next = NULL};
    n1.next = &n2;
    Node n3 = {.data = 64, .next = NULL};
    n2.next = &n3;
    // Beziehungsweise als Array
    Node list[4] = {
        {.data = 31, .next = NULL},
        {.data = 42, .next = NULL},
        {.data = 53, .next = NULL},
        {.data = 64, .next = NULL},
    };
    list[0].next = &list[1];
    list[1].next = &list[2];
    list[2].next = &list[3];
    // Liste durchiterieren
    while (head != NULL) {
        printf("%d\n", head->data);
        head = head->next;
    }
    free(head);
    return 0;
}*/