#include <stdio.h>
#include <stdlib.h>

/*
Erstellen Sie ein Programm um einen Text nach dem Playfair-Verfahren zu verschlüsseln.
Der zu verschlüsselnde Text und das Passwort soll fest im Hauptprogramm stehen.
Der verschlüsselte Text soll am Ende auf dem Bildschirm ausgegeben werden.

Im Bezug auf den Text gelten folgende Regeln:
• In dem Text dürfen nur Buchstaben (keine Umlaute oder ß) und Leerzeichen enthalten sein.
• Leerzeichen werden nicht verschlüsselt und vor der Verarbeitung entfernt.
• Entspricht der Text nicht den Regeln wird das Programm mit einer aussagekräftigen Fehlermeldung abgebrochen.

In Bezug auf das Passwort gelten folgende Regeln:
• Das Passwort darf keine Leerzeichen enthalten.
• Das Passwort darf nur aus Kleinbuchstaben (keine Umlaute oder ß) bestehen.
• Das Passwort muss mindestens 8 und maximal 12 Zeichen lang sein.
• Entspricht das Passwort nicht den Regeln wird das Programm mit einer aussagekräftigen Fehlermeldung abgebrochen.
*/

#define INPUT "L aboulaye ladywil lleadto C i bolatem plesofgold"
#define PASSWORD "deathjttj"

int isSpace(char c);

int isLowercaseLetter(char c);

int isLetter(char c);

int isValidTextChar(char c);

int isValidPasswordChar(char c);

int isValidText(char *text);

int isValidPassword(char *password);

char toUppercase(char c);

void prepareBigrams(char *text, int len, char (*bigrams)[2]);

void printTable(char table[5][5]);

void generatePlayfairTable(char *password, int len, char *table) ;

int getRowInPlayfairTable(char c, char table[5][5]);

int getColInPlayfairTable(char c, char table[5][5]);

void encrypt(char* text, int textLen, char *password, int passwordLen);

int main(void) {
    char input[] = INPUT;
    char password[] = PASSWORD;
    // Checken, ob Text den Regeln entspricht
    if (!isValidText(input)) {
        printf("Text entspricht nicht den gültigen Regeln - es dürfen nur Buchstaben und Leerzeichen enthalten sein\n");
        return 1;
    }
    printf("Klartext:\n%s\n", input);
    // Checken, ob Password den Regeln entspricht
    if (!isValidPassword(password)) {
        printf("Password entspricht nicht den gültigen Regeln - es dürfen nur Kleinbuchstaben enthalten sein, die Länge muss zwischen 8 und 12 Zeichen liegen\n");
        return 1;
    }
    printf("Passwort:\n%s\n", password);
    // Text verschlüsseln und ausgeben
    encrypt(input, sizeof(input) / sizeof(char), password, sizeof(password) / sizeof(char));
    return 0;
}

int isSpace(char c) {
    return c == ' ';
}

int isLowercaseLetter(char c) {
    return c >= 'a' && c <= 'z';
}

int isLetter(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

int isValidTextChar(char c) {
    return isLetter(c) || isSpace(c);
}

int isValidPasswordChar(char c) {
    return isLowercaseLetter(c);
}

// Expects a NULL terminated string
int isValidText(char *text) {
    if (text == NULL) return 0;
    while (*text != '\0') {
        if (!isValidTextChar(*text)) return 0;
        text++;
    }
    return 1;
}

// Expects a NULL terminated string
int isValidPassword(char *password) {
    if (password == NULL) return 0;
    int len = 0;
    while (*password != '\0') {
        if (!isValidPasswordChar(*password)) return 0;
        password++;
        len++;
    }
    return len >= 8 && len <= 12;
}

char toUppercase(char c) {
    if (c >= 'a' &&  c <= 'z') return c - 32;
    return c;
}

void prepareBigrams(char *text, int len, char (*bigrams)[2]) {
    if (text == NULL || bigrams == NULL) exit(1);
    int bigramIndex = 0;
    for (int i = 0; i < len; i += 2) {
        // Leerzeichen skippen
        char current = toUppercase(text[i]);
        while (current == ' ') {
            i++;
            current = toUppercase(text[i]);
        }
        char next = toUppercase(text[i + 1]);
        while (next == ' ') {
            i++;
            next = toUppercase(text[i + 1]);
        }
        // J zu I umwandeln
        if (current == 'J') current = 'I';
        if (next == 'J') next = 'I';
        bigrams[bigramIndex][0] = current;
        if (next == current) {
            // Gleicher Buchstabe mehrfach
            bigrams[bigramIndex][1] = 'X';
            i--;
        } else if (next == '\0') {
            // Ende des Textes
            bigrams[bigramIndex][1] = 'X';
        } else {
            // Normalfall
            bigrams[bigramIndex][1] = next;
        }
        bigramIndex++;
    }
}

void printTable(char table[5][5]) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            printf("%c ", table[i][j]);
        }
        printf("\n");
    }
}

void generatePlayfairTable(char *password, int len, char *table) {
    if (password == NULL || table == NULL) exit(1);
    char openLetters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int tableIndex = 0;
    // Einzelne Buchstaben des Schlüsselwortes (außer J) oben in Tabelle eintragen
    for (int i = 0; i < len; ++i) {
        // Auf J folgende Indizes fixen
        int openLetterIndex = password[i] - 'a';
        if (password[i] - 'j' > 0) openLetterIndex--;
        if (openLetters[openLetterIndex] != '\0' && password[i] != 'j') {
            table[tableIndex] = openLetters[openLetterIndex];
            openLetters[openLetterIndex] = '\0';
            tableIndex++;
        }
    }
    // Restliche Buchstaben alphabetisch auffüllen
    int openLetterIndex = 0;
    for (int i = tableIndex; i < 25; ++i) {
        char current = openLetters[openLetterIndex];
        // Bereits verwendete Buchstaben überspringen
        while (current == '\0') {
            openLetterIndex++;
            current = openLetters[openLetterIndex];
        }
        table[i] = current;
        openLetterIndex++;
    }
}

int getRowInPlayfairTable(char c, char table[5][5]) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (table[i][j] == c) return i;
        }
    }
    return -1;
}

int getColInPlayfairTable(char c, char table[5][5]) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (table[i][j] == c) return j;
        }
    }
    return -1;
}

void encrypt(char* text, int textLen, char *password, int passwordLen) {
    if (text == NULL || password == NULL) exit(1);
    // Reserviert aktuell vorsichtshalber für jedes Zeichen ein eigenes Bigramm (worst case)
    char (*bigrams)[2] = calloc(textLen * 2, sizeof(char));
    if (bigrams == NULL) exit(1);
    // Bigramme mit 0en initialisieren
    for (int i = 0; i < textLen; ++i) {
        bigrams[i][0] = '\0';
        bigrams[i][1] = '\0';
    }
    // Text in Bigramme aufteilen und Anzahl der tatsächlich benutzten ermitteln
    prepareBigrams(text, textLen, bigrams);
    int bigramLen = textLen;
    for (int i = 0; i < textLen; ++i) {
        if (bigrams[i][0] == '\0' || bigrams[i][1] == '\0') {
            bigramLen = i;
            break;
        }
    }
    // Bigramme ausgeben
    printf("Bigramme:\n");
    for (int i = 0; i < bigramLen; ++i) {
        printf("%c%c ", bigrams[i][0], bigrams[i][1]);
    }
    printf("\n");
    // Playfair-Quadrat erstellen
    char table[5][5];
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            table[i][j] = '\0';
        }
    }
    generatePlayfairTable(password, passwordLen, table);
    // Playfair-Quadrat ausgeben
    printf("Playfair-Quadrat:\n");
    printTable(table);
    // Verschlüsseln und Geheimtext ausgeben
    printf("Geheimtext:\n");
    for (int i = 0; i < bigramLen; ++i) {
        char first = bigrams[i][0];
        char second = bigrams[i][1];
        int firstRow = getRowInPlayfairTable(first, table);
        int firstCol = getColInPlayfairTable(first, table);
        int secondRow = getRowInPlayfairTable(second, table);
        int secondCol = getColInPlayfairTable(second, table);
        if (firstCol == secondCol) {
            // Beide Buchstaben in der selben Spalte
            printf("%c%c ", table[(firstRow + 1) % 5][firstCol], table[(secondRow + 1) % 5][secondCol]);
        } else if (firstRow == secondRow) {
            // Beide Buchstaben in der selben Zeile
            printf("%c%c ", table[firstRow][(firstCol + 1) % 5], table[secondRow][(secondCol + 1) % 5]);
        } else {
            printf("%c%c ", table[firstRow][secondCol], table[secondRow][firstCol]);
        }

    }
    // Speicher aufräumen
    free(bigrams);
}
