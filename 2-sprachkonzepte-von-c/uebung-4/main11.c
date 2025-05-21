/*#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void initHead(Node *head, int data);

void appendAtTail(Node *head, int data);

void removeWithData(Node *head, int data);

void deleteLast(Node *head);

void deleteList(Node *head);

void printList(Node *head);

int main11(void) {
    // Liste erstellen
    Node *head = malloc(sizeof(Node));
    if (head == NULL) return -1;
    initHead(head, 31);
    printList(head);
    printf("\n");
    // Liste auffüllen
    appendAtTail(head, 42);
    appendAtTail(head, 53);
    appendAtTail(head, 64);
    printList(head);
    printf("\n");
    // Bestimmtes Element entfernen (53)
    removeWithData(head, 64);
    printList(head);
    printf("\n");
    // Speicher wieder freigeben (bis auf manuell gemanagtes erstes Element)
    deleteList(head);
    printList(head);
    free(head);
    return 0;
}

// Memory for head must be managed by the programmer
void initHead(Node *head, int data) {
    head->data = data;
    head->next = NULL;
}

void appendAtTail(Node *head, int data) {
    // Liste bis zum Ende durchlaufen
    while (head->next != NULL) {
        head = head->next;
    }
    // Neues Element erstellen
    Node *new = malloc(sizeof(Node));
    if (new == NULL) return;
    new->data = data;
    new->next == NULL;
    // Neues Element anhängen
    head->next = new;
}

// Delete a specific element with data (not possible for the first)
void removeWithData(Node *head, int data) {
    if (head->next == NULL || data == head->data) return;
    // Liste bis zum Element vorm gesuchten Wert oder Ende durchlaufen
    while (head->next->data != data && head->next->next != NULL) {
        head = head->next;
    }
    // Element löschen
    if (head->next->data == data) {
        Node *delete = head->next;
        head->next = head->next->next;
        free(delete);
    }
}

// Delete the last element (not possible for the first)
void deleteLast(Node *head) {
    if (head->next == NULL) return;
    // Bis zum vorletzten Element durchlaufen
    while (head->next->next != NULL) {
        head = head->next;
    }
    // Letztes Element löschen
    free(head->next);
    head->next = NULL;
}

// Delete all elements until head
void deleteList(Node *head) {
    while (head->next != NULL) {
        deleteLast(head);
    }
}

void printList(Node *head) {
    while (head != NULL) {
        printf("%d\n", head->data);
        head = head->next;
    }
}*/