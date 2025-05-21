#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    // Datei öffnen
    FILE *file = fopen("someinput.txt", "r");
    // Checken, ob erfolgreich
    if (file == NULL) return 1;
    // Größe der Datei bestimmen
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);
    // Speicher für eingelsene Daten reservieren
    char *data = malloc(size);
    // Checken, ob erfolreich
    if (data == NULL) return 2;
    // Speicher auf 0 zurücksetzen
    memset(data, '\0', size);
    // Datei in Speicher einlesen
    size_t read = fread(data, sizeof(char), size, file);
    // Checken, ob alles gelesen
    if (read < size) return 3;
    // Datei schließen
    fclose(file);

    // Irgendetwas mit den Daten machen (hier ausgeben und jeden Buchstaben um eins erhöhen)
    printf("%s\n", data);
    for (int i = 0; i < size; ++i) {
        data[i]++;
    }
    printf("%s\n", data);

    // Neue Datei zum Schreiben anlegen (Daten werden binär geschrieben, aber da ASCII-Zeichen immer noch normal lesbar)
    FILE *writeFile = fopen("someoutput.txt", "wb");
    // Checken, ob erfolreich
    if (writeFile == NULL) return 4;
    // Alle Daten auf einmal rausschreiben
    fwrite(data, sizeof(char), size, writeFile);
    // Schreibdatei schließen
    fclose(writeFile);
    // Speicher wieder freigeben
    free(data);
    return 0;
}
