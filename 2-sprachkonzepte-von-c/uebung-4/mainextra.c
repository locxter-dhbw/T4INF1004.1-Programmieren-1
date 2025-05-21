#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    char *orderno;
    char *name;
    float price;
    int count;
} Item, *PItem;

typedef struct Stock {
    PItem item;
    struct Order *next;
} Stock, *PStock;

typedef struct Order {
    PItem item;
    struct Order *next;
} Order, *POrder;

PItem newItem(char *orderno, char*name, float price, int count);

// TODO
void addItemToStock(PStock stock, PItem item);

// TODO
void addItemToOrder(POrder order, PItem item);

// TODO
void addOrderToOrder(POrder new, POrder target);

// TODO
void updateItemCountInOrder(POrder order);

// TODO
PItem searchItemByOrderno(PStock stock);

// TODO
void deleteItemFromOrder(POrder order, PItem item);

// TODO
void freeItem(PItem item);

void printStock(PStock stock);

void printOrder(POrder order);

// TODO
void deleteStock();

// TODO
void deleteOrder();

int main(void) {
    // Dummy Stock
    Item stock[] = {
        {"12345", "Produkt A", 1.99, 99},
        {"54321", "Produkt B", 4.99, 49},
        {"31416", "Produkt C", 9.99, 31},
    };
    Order bla = {newItem("123", "Test", 1.99, 45), NULL};
    printOrder(&bla);
    return 0;
}

// Neuen Artikel erstellen und Speicher allokieren (muss später manuell freigegeben werden)
PItem newItem(char *orderno, char*name, float price, int count) {
    PItem new = malloc(sizeof(Item));
    if (new == NULL) exit(-1);
    new->orderno = orderno;
    new->name = name;
    new->price = price;
    new->count = count;
    return new;
}

// Neuen Artikel zu Stock hinzufügen (muss später manuell freigegeben werden)
void addItemToStock(PStock stock, PItem item) {
    // Falls Bestand noch leer, erstes Element befüllen
    if (stock->item == NULL) {
        stock->item = item;
        return;
    }
    // Gesamten Bestand durchlaufen
    while (stock->next != NULL) {
        stock = stock->next;
    }
    PStock new = malloc(sizeof(Stock));
    if (new == NULL) exit(-1);
    new->item = item;
    new->next = NULL;
    stock->next = new;
}

// Bestand ausgeben
void printStock(PStock stock) {
    printf("Bestellnummer:\t\tName:                                                           \t\tEinzelpreis:\t\tMenge:\t\tGesamtpreis:\n");
    while (stock != NULL) {
        printf("%-14s\t\t%-64s\t\t%-12.2f\t\t%-6d\t\t%-12.2f\n", stock->item->orderno, stock->item->name, stock->item->price,
               stock->item->count, stock->item->price * stock->item->count);
        stock = stock->next;
    }
}

// Bestellung ausgeben
void printOrder(POrder order) {
    printf("Bestellnummer:\t\tName:                                                           \t\tEinzelpreis:\t\tMenge:\t\tGesamtpreis:\n");
    while (order != NULL) {
        printf("%-14s\t\t%-64s\t\t%-12.2f\t\t%-6d\t\t%-12.2f\n", order->item->orderno, order->item->name, order->item->price,
               order->item->count, order->item->price * order->item->count);
        order = order->next;
    }
}
