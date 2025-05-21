#include <stdio.h>
#include <string.h>

#pragma pack(1)

struct Adresse {
    int plz;
    int hausnummer;
    char strasse[20];
    char ort[20];
};

// Einziger Weg default Werte festzulegen
/*
struct Something {
    int a;
    char b;
} SomethingDefault = {42, 'L'};

struct Something mySomething = SomethingDefault;
*/

// Direkt als neuen Datentypen festlegen
/*typedef struct Adresse {
    int plz;
    int hausnummer;
    char strasse[20];
    char ort[20];
} Adresse;
// BZW. noch kürzer plus entsprechenden Pointer
typedef struct {
    int plz;
    int hausnummer;
    char strasse[20];
    char ort[20];
} Adresse, *PAdresse;
*/
// ODER als Zusatz
typedef struct Adresse Adresse;

// Structs mit Variablen direkt definieren
/*
struct Something {
    int a;
} something1 = {1}, something2 = {2}, something3 = {3};
*/

void printAdresse(struct Adresse adr);

void initAdresse(Adresse *adr);

int main1(void) {
    // Einfaches Struct
    struct Adresse adr;
    adr.plz = 12345;
    adr.hausnummer = 123;
    strcpy(adr.strasse, "Teststrasse");
    strcpy(adr.ort, "Musterdorf");
    printAdresse(adr);
    // Struct in Arrays (hier mit typedef)
    Adresse adrArr[20];
    for (int i = 0; i < 20; ++i) {
        adrArr[i].plz = i * 100;
        adrArr[i].hausnummer = 100 - i;
        adrArr[i].strasse[0] = i + 65;
        adrArr[i].strasse[1] = 0;
        adrArr[i].ort[0] = i + 97;
        adrArr[i].ort[1] = 0;
        printAdresse(adrArr[i]);
    }
    // Schönes intialisieren
    Adresse bla = {
        12345, // Automatisch in plz
        .strasse = "Bla"
    };
    printAdresse(bla);
    // Anonyme structs
    struct {
        int seite;
        char titel[20];
    } libAnonym = {1, "Test"};
    libAnonym.seite = 12;
    // Pointer von structs
    Adresse *pAdr = &adr;
    printAdresse(adr);
    (*pAdr).hausnummer = 31;
    printAdresse(adr);
    pAdr->hausnummer = 20;
    printAdresse(adr);
    initAdresse(&adr);
    printAdresse(adr);
    // Größe von structs
    printf("%d\n", sizeof(Adresse)); // Sollte 48 sein (40 Chars * 1 Byte + 2 Ints * 4 Byte)
    struct Dummy {
        char c;
        short s;
    };
    printf("%d\n", sizeof(char));
    printf("%d\n", sizeof(short));
    printf("%d\n", sizeof(struct Dummy)); // Sollte 3 sein (1 Char * 1 Byte + 1 Short * 2 Byte)
    // Aber Compiler verwendet standardmäßig Vielfache von 4 als Speicherblockgröße (manchmal auch 2, änderbar über Zeile 4)
    // Pointer auf struct arrays
    printf("%d\n", pAdr);
    pAdr++; // Um 48 Byte nach hinten (gesamte Struct Breite)
    printf("%d\n", pAdr);
    return 0;
}

void printAdresse(Adresse adr) {
    printf("%s %d, %d %s \n", adr.strasse, adr.hausnummer, adr.plz, adr.ort);
}

void initAdresse(Adresse *adr) {
    adr->strasse[0] = 0;
    adr->hausnummer = 42;
}