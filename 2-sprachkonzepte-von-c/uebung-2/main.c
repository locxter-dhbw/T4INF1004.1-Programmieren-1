#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "helper.h"

void mirrorArray(int *arr, int len);

void printArray(int *arr, int len);

void findPrimes(int *arr, int len);

void printBinary(int num);

void randomArray(int *arr, int len);

void swapNums(int *a, int *b);

void bubbleSort(int *arr, int len);

void selectionSort(int *arr, int len);

void readNum(int *num);

int isPrime(int num);

void integerFactorization(int num);

void printToBase64(unsigned char *str, int len);

int stairProblem(int n);

int palin(char c[], int first, int last);

double squareRoot(int n, double x);

int ackermann(int m, int n);

void fibonacci(int lastlast, int last, int cur, int n);

int printPyramid(int a, int n);

int commonDivisor(int n, int m);

int main(void) {
    /*
    int arr[] = {1, 2, 3, 4, 5};
    printArray(arr, sizeof(arr) / sizeof(int));
    mirrorArray(arr, sizeof(arr) / sizeof(int));
    printArray(arr, sizeof(arr) / sizeof(int));
    */
    /*
    int nums[99];
    for (int i = 0; i < 99; ++i) {
        nums[i] = i + 2;
    }
    printArray(nums, sizeof(nums) / sizeof(int));
    findPrimes(nums, sizeof(nums) / sizeof(int));
    printArray(nums, sizeof(nums) / sizeof(int));
    */
    /*
    int num = 0;
    //scanf("%d", &num);
    num = 0b10101011;
    printBinary(num);
    */
    /*
    int arr[10];
    randomArray(arr, sizeof(arr) / sizeof(int));
    printArray(arr, sizeof(arr) / sizeof(int));
    bubbleSort(arr, sizeof(arr) / sizeof(int));
    printArray(arr, sizeof(arr) / sizeof(int));
    */
    /*
    int arr[10];
    randomArray(arr, sizeof(arr) / sizeof(int));
    printArray(arr, sizeof(arr) / sizeof(int));
    selectionSort(arr, sizeof(arr) / sizeof(int));
    printArray(arr, sizeof(arr) / sizeof(int));
    */
    /*
    int num;
    readNum(&num);
    integerFactorization(num);
    */
    /*
    printf("%d\n", stairProblem(25));
    */
    unsigned char str[] = "Hello World!";
    printf("ASCII:\t%s\n", str);
    printf("BASE64:\t");
    printToBase64(str, sizeof(str) / sizeof(char));
    printf("\n");
    /*
    printf("%d\n", palin("anna", 0, 3));
    printf("%d\n", palin("anana", 0, 4));
    printf("%d\n", palin("luca", 0, 3));
    printf("%d\n", palin("lucas", 0, 4));
    */
    /*
    printf("%lf\n", squareRoot(10, 8.0));
    printf("%lf\n", sqrt(8.0));
    */
    /*
    printf("%d\n", ackermann(3, 8));
    */
    /*
    fibonacci(0, 1, 1, 10);
    */
    /*
    printPyramid(4, 4);
    printPyramid(8, 8);
    */
    /*
    printf("%d\n", commonDivisor(54, 24));
    */
    return 0;
}

void mirrorArray(int *arr, int len) {
    for (int i = 0; i < len / 2; i++) {
        int buf = arr[i];
        arr[i] = arr[len - 1 - i];
        arr[len - 1 - i] = buf;
    }
}

void printArray(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void findPrimes(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        if (arr[i] != 0) {
            printf("%d\n", arr[i]);
            for (int j = i + 1; j < len; j++) {
                if (arr[j] % arr[i] == 0) {
                    arr[j] = 0;
                }
            }
        }
    }
}

void printBinary(int num) {
    num & 0b10000000 ? printf("1") : printf("0");
    num & 0b01000000 ? printf("1") : printf("0");
    num & 0b00100000 ? printf("1") : printf("0");
    num & 0b00010000 ? printf("1") : printf("0");
    num & 0b00001000 ? printf("1") : printf("0");
    num & 0b00000100 ? printf("1") : printf("0");
    num & 0b00000010 ? printf("1") : printf("0");
    num & 0b00000001 ? printf("1") : printf("0");
    printf("\n");
}

void randomArray(int *arr, int len) {
    srand(time(NULL));
    for (int i = 0; i < len; ++i) {
        arr[i] = rand() % len;
    }
}

void swapNums(int *a, int *b) {
    int x = *a;
    *a = *b;
    *b = x;
}

void bubbleSort(int *arr, int len) {
    for (int i = len - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                swapNums(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void selectionSort(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        int smallIndex = i;
        for (int j = i; j < len; ++j) {
            if (arr[j] < arr[smallIndex]) {
                smallIndex = j;
            }
        }
        swapNums(&arr[i], &arr[smallIndex]);
    }
}

void readNum(int *num) {
    scanf("%d", num);
}

int isPrime(int num) {
    int isPrime = 1;
    for (int j = 2; j < num; j++) {
        if (num % j == 0) {
            isPrime = 0;
            break;
        }
    }
    return isPrime;
}

void integerFactorization(int num) {
    while (!isPrime(num)) {
        for (int i = 2; i <= num; i++) {
            if (num % i == 0 && isPrime(i)) {
                printf("%d ", i);
                num /= i;
                break;
            }
        }
    }
    printf("%d\n", num);
}

int stairProblem(int n) {
    if (n < 3) return n;
    return stairProblem(n - 1) + stairProblem(n - 2);
}

// Base64 => 64 = 2^6 Zeichen (A-Z, a-z, 0-9, + und /) immer mit 6 Bitblöcken
// Ausgabe immer in 4 Zeichenblöcken, aufzufüllen mit =
// => Zeichen aufteilen in 6 Bitblöcke
// '?' = 8 Bit => 6 Bit + 2 Bit
// "??" = 16 Bit => 6 Bit + 6 Bit + 4 Bit
// Siehe https://en.wikipedia.org/wiki/Base64#Examples
// ACHTUNG: VERARBEITET NUR STRINGS MIT NULL-ZEICHEN AM ENDE KORREKT
void printToBase64(unsigned char *str, int len) {
    // Nur Strings mit Inhalt bearbeiten
    if (len <= 1) return;
    // Platz für abschließendes NULL Zeichen entfernen
    len--;
    // Base64 Länge berechnen
    int b64Len = (len * (int) sizeof(char) * 8) / 6;
    // Rest beachten und zusätzliches Zeichen reservieren
    b64Len += (len * (int) sizeof(char) * 8) % 6 ? 1 : 0;
    // Speicher reservieren (+1 für abschließendes NULL Zeichen)
    unsigned char *b64 = calloc(b64Len + 1, sizeof(char));
    unsigned char *out = calloc(b64Len + 1, sizeof(char));
    // Out of memory-Fehler behandeln
    if (b64 == NULL || out == NULL) return;
    // 6 Bitblöcke bilden
    int b64Index = 0;
    for (int i = 0; i < len; i++) {
        unsigned char c = str[i];
        // Jedes dritte Zeichen unterschiedlich behandlen, siehe https://en.wikipedia.org/wiki/Base64#Examples
        switch (i % 3) {
            case 0:
                //toBin8(c);
                b64[b64Index] = c >> 2;
                //toBin8(b64[b64Index]);
                b64Index++;
                b64[b64Index] = c << 6;
                b64[b64Index] >>= 2;
                //toBin8(b64[b64Index]);
                break;
            case 1:
                b64[b64Index] |= c >> 4;
                //toBin8(b64[b64Index]);
                b64Index++;
                b64[b64Index] = c << 4;
                b64[b64Index] >>= 2;
                //toBin8(b64[b64Index]);
                break;
            default:
                b64[b64Index] |= c >> 6;
                //toBin8(b64[b64Index]);
                b64Index++;
                b64[b64Index] = c << 2;
                b64[b64Index] >>= 2;
                //toBin8(b64[b64Index]);
                b64Index++;
                break;
        }
    }
    // Zurück in ASCII Zeichen umwandeln
    for (int i = 0; i < b64Len; i++) {
        unsigned char c = b64[i];
        if (c <= 25) {
            // A bis Z
            c += 65;
        } else if (c <= 51) {
            // a bis z
            // ASCII-Startposition - Base64-Startposition
            c += 97 - 26;
        } else if (c <= 61) {
            // 0 bis 9
            // ASCII-Startposition - Base64-Startposition
            c += 48 - 52;
        } else if (c == 62) {
            // Zeichen 63 nach Standard
            c = '+';
        } else {
            // Zeichen 64 nach Standard
            c = '/';
        }
        out[i] = c;
    }
    out[b64Len] = '\0';
    // Base64 ausgeben
    printf("%s", (char *) out);
    // Auffüllen mit = Zeichen
    for (int i = b64Len % 4 ? 0 : 4; i < 4 - (b64Len % 4); i++) {
        printf("=");
    }
    // Speicher aufräumen
    free(b64);
    free(out);
}

int palin(char c[], int first, int last) {
    if (c[first] != c[last]) return 0;
    if (last < first) return 1;
    return palin(c, first + 1, last - 1);
}

double squareRoot(int n, double x) {
    if (n < 1) return 1;
    return 0.5 * (squareRoot(n - 1, x) + (x / squareRoot(n - 1, x)));
}

int ackermann(int m, int n) {
    if (m == 0) return n + 1;
    if (n == 0) return ackermann(m - 1, 1);
    return ackermann(m - 1, ackermann(m, n - 1));
}

void fibonacci(int lastlast, int last, int cur, int n) {
    if (n <= cur) return;
    if (cur == 1) printf("%d %d ", lastlast, last);
    printf("%d ", lastlast + last);
    fibonacci(last, lastlast + last, cur + 1, n);
}

int printPyramid(int a, int n) {
    if (a < 0 || n < 0) return 0;
    for (int i = 0; i < a - n; ++i) {
        printf(" ");
    }
    for (int i = 0; i < 1 + n * 2; ++i) {
        printf("%d", n);
    }
    printf("\n");
    return printPyramid(a, n - 1);
}

int commonDivisor(int n, int m) {
    if (m < n) return commonDivisor(m, n - m);
    if (m > n) return commonDivisor(m - n, n);
    return m;
}
