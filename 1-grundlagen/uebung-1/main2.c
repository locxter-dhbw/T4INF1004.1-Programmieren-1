#include <stdio.h>
#include <stdlib.h>

// Geben alle Inverse aus
void printBinary(int num);

void printOctal(int num);

void printHex(int num);

double faculty(int n);

double eulersNum1(int n);

double eulersNum2(double minDelta);

void printPyramid(int n);

void mentalExercise();

double wallisProduct(int n);

void printEinMalEins();

void printDayOfWeek(int day, int month, int year);

void pythagoreanTriple(int n);

void printPrimeNums(int max);

int main(void) {
    //printBinary(42);
    //printOctal(10);
    //printHex(703710);
    //printf("%lf\n", eulersNum1(100));
    //printf("%lf\n", eulersNum2(0.00000001));
    printPyramid(5);
    //mentalExercise();
    //printf("%lf\n", wallisProduct(1000));
    //printEinMalEins();
    /*
    printDayOfWeek(23,4,1916);
    printDayOfWeek(8,4,2007);
    printDayOfWeek(4,4,2010);
    printDayOfWeek(1,3,2006);
    printDayOfWeek(21,2,2007);
    printDayOfWeek(17,2,2010);
    printDayOfWeek(23,5,1949);
    */
    //pythagoreanTriple(1000);
    printPrimeNums(1000);
    return 0;
}

void printBinary(int num) {
    while (num > 0) {
        printf("%d", num % 2);
        num /= 2;
    }
    printf("\n");
}

void printOctal(int num) {
    while (num > 0) {
        printf("%d", num % 8);
        num /= 8;
    }
    printf("\n");
}

void printHex(int num) {
    while (num > 0) {
        int digit = num % 16;
        if (digit > 9) {
            printf("%c", 55 + digit);
        } else {
            printf("%d", digit);
        }
        num /= 16;
    }
    printf("\n");
}

double faculty(int n) {
    if (n == 0) return 1.0;
    double result = 1.0;
    for (int i = n; i > 1; i--) {
        result *= i;
    }
    return result;
}

double eulersNum1(int n) {
    double result = 0.0;
    for (int i = 0; i < n; i++) {
        result += 1.0 / faculty(i);
    }
    return result;
}


double eulersNum2(double minDelta) {
    double result = 0.0;
    double delta = 1.0;
    int i = 1;
    while (delta > minDelta) {
        result += delta;
        delta = 1.0 / faculty(i);
        i++;
    }
    return result;
}

void printPyramid(int n) {
    for (int i = 1; i <= n; i++) {
        // Linke Leerzeichen
        for (int j = 0; j < n - i; j++) {
            printf(" ");
        }
        // Zahlen ausgeben
        for (int j = 0; j < i; j++) {
            printf("* ", i);
        }
        printf("\n");
    }
}

void mentalExercise() {
    int x, o, l, t;
    for (x = 0; x < 10; x++) {
        for (o = 0; o < 10; o++) {
            for (l = 0; l < 10; l++) {
                for (t = 0; t < 10; t++) {
                    if ((x * 100 + o * 10 + l) + (l * 100 + x * 10 + x) == (t * 100 + l * 10 + t)) {
                        printf("x = %d, o = %d, l = %d, t = %d\n", x, o, l, t);
                    }
                }
            }
        }
    }
}

double wallisProduct(int n) {
    double pi = 1.0;
    for (int i = 1; i < n / 2; i++) {
        pi *= ((2 * i) / ((2 * i) - 1.0)) * ((2 * i) / ((2 * i) + 1.0));
    }
    return pi * 2;
}

void printEinMalEins() {
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; ++j) {
            printf("%d\t", i * j);
        }
        printf("\n");
    }
}

void printDayOfWeek(int day, int month, int year) {
    // Ungültige Bereiche abfangen
    if (day < 1 || day > 31 || month < 0 || month > 12 || year < 1900 || year > 2100) return;
    if ((month < 3 && year <= 1900) || (month > 2 && year >= 2100)) return;
    // Tatsächliche Berechnung
    int weekDays = (year - 1900) * 365;
    weekDays += (year - 1900) / 4;
    if (year / 4 == 0) weekDays--;
    for (int i = 1; i < month; i++) {
        switch (i) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                weekDays += 31;
                break;
            case 2:
                weekDays += 28;
                break;
            default:
                weekDays += 30;
                break;;
        }
    }
    weekDays += day;
    printf("Day of week (0 = Sunday): %d\n", weekDays % 7);
}

void pythagoreanTriple(int n) {
    for (int a = 0; a < 1000; a++) {
        for (int b = 0; b < 1000; b++) {
            for (int c = 0; c < 1000; c++) {
                if (a < b & b < c && (a*a) + (b*b) == c*c && a + b + c == 1000) {
                    printf("a = %d, b = %d, c = %d\n", a, b, c);
                    printf("Product: %d", a*b*c);
                }
            }
        }
    }
}

void printPrimeNums(int max) {
    for (int i = 2; i <= max; i++) {
        int isPrime = 1;
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime) {
            printf("%d\n", i);
        }
    }
}