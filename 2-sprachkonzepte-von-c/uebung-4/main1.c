#include <stdio.h>

typedef struct {
    char name[32];
    int alter;
} Person;

int main1(void) {
    Person max = {"Max", 18};
    // Aufgabe Modulo 11 mit Angelina
    // Nummer einlesen und Länge bestimmen
    char nummer[100];
    scanf("%s", &nummer);
    int laenge = 0;
    while (nummer[laenge] != '\0') {
        laenge++;
    }
    /* Am einfachsten zu verstehen (alle Elemente durchgehen, falls Ziffer ungleich 0 Länge erhöhen)
    laenge = 0;
    for (int i = 0; i < 100; ++i) {
        if (nummer[i] != 0) {
            laenge++;
    }
    }*/
    /* Etwas schneller, da unnötige Schleifendurchläufe verhindert werden (durch das break)
    laenge = 0;
    for (int i = 0; i < 100; ++i) {
        if (nummer[i] != 0) {
            laenge++;
        } else {
            break;
        }
    }
    */
    // Prüfziffer berechnen
    int summe = 0;
    // Für jede Ziffer: Ziffer raussuchen, Ziffer gewichten (mit 2, 3, 4, 5 usw. multiplizieren von rechts nach links), gewichtete Ziffer aufsummieren
    for (int i = laenge - 1; i >= 0; i--) { // Schleife zählt von rechts nach links RUNTER
        int ziffer = nummer[i] - 48; // Umrechnung ASCII-Zeichen zu tatsächlich gespeicherter Ziffer
        int gewicht = ((laenge - 1 - i) % 6) + 2; // (laenge - 1 - i) zählt von rechts nach links HOCH, % 6 + 2 zählt immer wieder von 2 bis 7 hoch (ohne +0 von 0 bis 5)
        int ziffer_gewichtet = ziffer * gewicht;
        summe = summe + ziffer_gewichtet;
    }
    // Rest, wenn man durch 11 dividiert: Rest = Summe % 11
    int rest = summe % 11;
    // Rest von 11 absziehen: Ergebnis = 11 - (Summe % 11)
    int ergebnis = 11 - rest;
    // Wenn Ergebnis == 10 oder 11, dann setzen wir es auf 0
    // if (ergebnis == 10 || ergebnis == 11) {
    if (ergebnis >= 10) {
        ergebnis = 0;
    }
    // Nummer mit Prüfziffer ausgeben
    printf("%s%d\n", nummer, ergebnis);
    return 0;
}