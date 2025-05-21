#include <stdio.h>

int main1(void) {
    char wort1[] = {'H', 'a', 'l', 'l', 'o'};
    // Strings werden immer mit einem zusätzlichen NULL-Character beendet
    char wort2[] = "Hallo";
    int l1 = sizeof(wort1);
    int l2 = sizeof(wort2);
    printf("%d\n", l1);
    printf("%d\n", l2);
    // Printf gibt nur bis zum ersten NULL-Character aus
    printf("%s\n", "Bla\0Bli Blup");
    // Hier kann man es besser sehen
    char wort3[] = "Bla\0Bli Blup";
    for (int i = 0; i < sizeof(wort3) / sizeof(char); i++) {
        putchar(wort3[i]);
    }
    // Streams (Input, Output) können manuell geleert werden, um ungewünschtes Verhalten zu verhindernd
    fflush(stdout);
    return 0;
}