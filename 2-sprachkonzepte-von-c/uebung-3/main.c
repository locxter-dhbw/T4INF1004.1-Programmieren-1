#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "helper.h"

void swapNums(int *a, int *b);

void multiplyMatrices(int *a, int *b, int *out, int size);

void printMatrix(int *a, int rows, int cols);

int dotP(int *a, int *b, int size);

void transposeMatrix(int *a, int *out, int rows, int cols);

int det2x2(int *a);

void reverseString(char *a, int size);

int countWords(char *a, int size);

void replaceChar(char *str, char a, char b, int size);

int findSubstring(char *str, int strSize, char *sub, int subSize);

int compareStrings(char *s1, char *s2);

void removeDoublets(char *str, int size);

int findFirstDoublet(char *str);

void removeDoubletAtPos(char *str, int doubletPos, int size);

void randomArray(int *arr, int size);

void printArray(int *arr, int size);

void bubbleSort(int *arr, int size);

void printMatrixDouble(double *a, int rows, int cols);

void printArrayDouble(double *arr, int size);

void solve3x3LinearSystem(double coefficientsAndConstants[3][4], double *unknowns);

int main(void) {
    /*
    int a = 5;
    int b = 10;
    printf("%d %d\n", a, b);
    swapNums(&a, &b);
    printf("%d %d\n", a, b);
    */
    /*
    int a[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    int b[3][3] = {
        {-3, 2, -1},
        {8, 3, 2},
        {0, 9, 5},
    };
    int out[3][3];
    multiplyMatrices(a, b, out, 3);
    printMatrix(out, 3, 3);
    */
    /*
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {-6, -7, -8, -9, -10};
    printf("%d\n", dotP(a, b, 5));
    */
    /*
    int a[2][3] = {
        {-3, 2, -1},
        {8, 3, 2},
    };
    int out[3][2];
    printMatrix(a, 2, 3);
    transposeMatrix(a, out, 2, 3);
    printMatrix(out, 3, 2);
    */
    /*
    int a[2][2] = {
        {-3, 2},
        {8, 3},
    };
    printMatrix(a, 2, 2);
    printf("%d\n", det2x2(a));
    */
    /*
    char a[] = "ABCDEF";
    printf("%s\n", a);
    reverseString(a, sizeof(a) / sizeof(char));
    printf("%s\n", a);
    */
    /*
    char a[] = "The quick brown fox jumps over the lazy dog.";
    printf("%d\n", countWords(a, sizeof(a) / sizeof(char)));
    */
    /*
    char a[] = "The quick brown fox jumps over the lazy dog.";
    printf("%s\n", a);
    replaceChar(a, 'o', '!', sizeof(a) / sizeof(char));
    printf("%s\n", a);
    */
    /*
    char a[] = "The quick brown fox jumps over the lazy dog.";
    char b[] = "brown"; //"dog.."
    printf("%s\n", a);
    printf("%s\n", b);
    printf("%d\n", findSubstring(a, sizeof(a) / sizeof(char), b, sizeof(b) / sizeof(char)));
    */
    /*
    char a[] = "Hello";
    char b[] = "Hello";
    printf("%d\n", compareStrings(a, b));
    */
    /*
    char a[11] = "Hellloanna";
    //Hellloanna
    //Heloanna
    //Heloana
    removeDoublets(a, sizeof(a) / sizeof(char));
    for (int i = 0; i < sizeof(a) / sizeof(char); ++i) {
        printf("%c", a[i]);
    }
    printf("\n%s\n", a);
    */
    /*
    int arr[10];
    randomArray(arr, sizeof(arr) / sizeof(int));
    printArray(arr, sizeof(arr) / sizeof(int));
    bubbleSort(arr, sizeof(arr) / sizeof(int));
    printArray(arr, sizeof(arr) / sizeof(int));
    */
    double coefficientsAndConstants[3][4] = {
        //{1.0, 3.0, -2.0, 5.0},
        //{3.0, 5.0, 6.0, 7.0},
        //{2.0, 4.0, 3.0, 8.0}
        {3, 2, -1, 1},
        {2, -2, 4, -2},
        {-1, .5, -1, 0}
    };
    double unknowns[3];
    // x = -15, y = 8, z = 2
    // x = 1, y = -2, z = -2
    printMatrixDouble(coefficientsAndConstants, 3, 4);
    printf("\n");
    solve3x3LinearSystem(coefficientsAndConstants, unknowns);
    printArrayDouble(unknowns, 3);
    return 0;
}

void swapNums(int *a, int *b) {
    int x = *a;
    *a = *b;
    *b = x;
}

void multiplyMatrices(int *a, int *b, int *out, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            int dotP = 0;
            for (int k = 0; k < size; ++k) {
                dotP += *(a + size * i + k) * *(b + size * k + j);
            }
            *(out + size * i + j) = dotP;
        }
    }
}

void printMatrix(int *a, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d\t", *(a + cols * i + j));
        }
        printf("\n");
    }
}

int dotP(int *a, int *b, int size) {
    int dotP = 0;
    for (int i = 0; i < size; ++i) {
        dotP += *(a + i) * *(b + i);
    }
    return dotP;
}

void transposeMatrix(int *a, int *out, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            *(out + rows * j + i) = *(a + cols * i + j);
        }
    }
}

int det2x2(int *a) {
    return *a * *(a + 3) - *(a + 2) * *(a + 1);
}

// Assumes a NULL terminated string
void reverseString(char *a, int size) {
    if (size <= 1) return;
    for (int i = 0, j = size - 2; i <= j; i++, j--) {
        char buf = *(a + i);
        *(a + i) = *(a + j);
        *(a + j) = buf;
    }
}

int countWords(char *a, int size) {
    int spaces = 1;
    for (int i = 0; i < size; ++i) {
        if (*(a + i) == 32) {
            spaces++;
        }
    }
    return spaces;
}

void replaceChar(char *str, char a, char b, int size) {
    for (int i = 0; i < size; ++i) {
        if (*(str + i) == a) {
            *(str + i) = b;
        }
    }
}

// Assumes a NULL terminated string
int findSubstring(char *str, int strSize, char *sub, int subSize) {
    int start = -1;
    strSize--;
    subSize--;
    for (int i = 0; i < strSize; ++i) {
        if (start == -1 && str[i] == sub[0]) {
            start = i;
        }
        if (start > -1 && i - start < subSize && str[i] != sub[i - start]) {
            start = -1;
        }
    }
    if (start > -1 && start > strSize - subSize) start = -1;
    return start;
}

// Assumes a NULL terminated string
int compareStrings(char *s1, char *s2) {
    int same = 1;
    int i = 0;
    while (*(s1 + i) != '\0' && *(s2 + i) != '\0') {
        if (*(s1 + i) != *(s2 + i)) {
            same = 0;
            break;
        }
        i++;
    }
    return same;
}

// Assumes a NULL terminated string
void removeDoublets(char *str, int size) {
    int doubletPos;
    while ((doubletPos = findFirstDoublet(str)) != -1) {
        removeDoubletAtPos(str, doubletPos, size);
    }
}

// Assumes a NULL terminated string
int findFirstDoublet(char *str) {
    int i = 0;
    while (*(str + i) != '\0') {
        if (i > 0 && *(str + i) == *(str + i - 1))
            return i - 1;
        i++;
    }
    return -1;
}

// Assumes a NULL terminated string
void removeDoubletAtPos(char *str, int doubletPos, int size) {
    // Länge des Doublets bestimmen
    int doubletSize = 2;
    for (int i = doubletPos + 2; i < size; ++i) {
        if (*(str + i) == *(str + doubletPos)) {
            doubletSize++;
        }
    }
    // Nachfolgenden String bis zum NULL vorziehen
    int i = doubletPos + 1;
    while (*(str + i + doubletSize - 1) != '\0') {
        *(str + i) = *(str + i + doubletSize - 1);
        i++;
    }
    // Restliche Elemente mit NULL füllen
    while (i < size - 1) {
        *(str + i) = '\0';
        i++;
    }
}

void randomArray(int *arr, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; ++i) {
        *(arr + i) = rand() % size;
    }
}

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

void bubbleSort(int *arr, int size) {
    for (int i = size - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (*(arr + j) > *(arr + j + 1)) {
                swapNums((arr + j), (arr + j + 1));
            }
        }
    }
}

void printMatrixDouble(double *a, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%lf\t", *(a + cols * i + j));
        }
        printf("\n");
    }
}

void printArrayDouble(double *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%lf ", *(arr + i));
    }
    printf("\n");
}

// Assumes all elements are non-zero
void solve3x3LinearSystem(double coefficientsAndConstants[3][4], double *unknowns) {
    // Untere Dreiecksform durch Subtraktion/Addition der auf 1 gebrachten ersten und zweiten Zeile
    for (int i = 3; i >= 0; i--) {
        coefficientsAndConstants[0][i] /= coefficientsAndConstants[0][0];
    }
    printMatrixDouble(coefficientsAndConstants, 3, 4);
    printf("\n");
    for (int i = 3; i >= 0; i--) {
        coefficientsAndConstants[1][i] -= coefficientsAndConstants[1][0] * coefficientsAndConstants[0][i];
        coefficientsAndConstants[2][i] -= coefficientsAndConstants[2][0] * coefficientsAndConstants[0][i];
    }
    printMatrixDouble(coefficientsAndConstants, 3, 4);
    printf("\n");
    for (int i = 3; i >= 0; i--) {
        coefficientsAndConstants[1][i] /= coefficientsAndConstants[1][1];
    }
    printMatrixDouble(coefficientsAndConstants, 3, 4);
    printf("\n");
    for (int i = 3; i >= 1; i--) {
        coefficientsAndConstants[2][i] -= coefficientsAndConstants[2][1] * coefficientsAndConstants[1][i];
    }
    printMatrixDouble(coefficientsAndConstants, 3, 4);
    printf("\n");
    for (int i = 3; i >= 1; i--) {
        coefficientsAndConstants[2][i] /= coefficientsAndConstants[2][2];
    }
    printMatrixDouble(coefficientsAndConstants, 3, 4);
    printf("\n");
    // Obere Dreiecksform durch Subtraktion/Addition der auf 1 gebrachten letzten Zeile
    for (int i = 3; i >= 2; i--) {
        coefficientsAndConstants[0][i] -= coefficientsAndConstants[0][2] * coefficientsAndConstants[2][i];
        coefficientsAndConstants[1][i] -= coefficientsAndConstants[1][2] * coefficientsAndConstants[2][i];
    }
    printMatrixDouble(coefficientsAndConstants, 3, 4);
    printf("\n");
    for (int i = 3; i >= 1; i--) {
        coefficientsAndConstants[0][i] -= coefficientsAndConstants[0][1] * coefficientsAndConstants[1][i];
    }
    printMatrixDouble(coefficientsAndConstants, 3, 4);
    printf("\n");
    // Ergebnisse zurückgeben
    for (int i = 0; i < 3; ++i) {
        unknowns[i] = coefficientsAndConstants[i][3];
    }
}