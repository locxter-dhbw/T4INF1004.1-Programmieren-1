#include <stdio.h>
#include <stdlib.h>

int main1(void) {
    int i = 12;
    float f = 2.0f;
    // Einfache Anweisungen
    f = i * f;
    ; // Leere Anweisung
    // Einfache Anweisungsblöcke
    {
        double d = 2.0;
        d = f * d;
        // Auch geschachtelt
        {
            // Variablen können überdeckt werden
            double d = 12.0;
            printf("%lf\n", d);
            // Verwendet d = 12, auf d = f * d besteht kein Zugriff mehr
            double g = d * f;
            printf("%lf\n", g);
        }
        printf("%lf\n", d);
    }
    return 0;
}