#include <stdio.h>
#include <stdlib.h>

#define M_PI 3.14159265358979323846

void aufgabe1();
void aufgabe2();
void aufgabe3();
void aufgabe31();
void aufgabe32();
void aufgabe33();


int main1(void) {
    //aufgabe1();
    //aufgabe2();
    aufgabe3();
    //aufgabe31();
    //aufgabe32();
    //aufgabe33();
    return 0;
}

void aufgabe1() {
    double r = 0;
    scanf("%lf", &r);
    double u = 2 * M_PI * r;
    double f = M_PI * r * r;
    double v = (4.0 / 3) * M_PI * r * r * r;
    printf("Radius: %lf\n", r);
    printf("Umfang: %lf\n", u);
    printf("Fläche: %lf\n", f);
    printf("Volumen: %lf\n", v);
}

void aufgabe2() {
    double celsius = 0;
    scanf("%lf", &celsius);
    double fahrenheit = ((9.0 / 5) * celsius) + 32;
    printf("Celsius: %lf\n", celsius);
    printf("Fahrenheit: %lf\n", fahrenheit);
}

void aufgabe3() {
    double l = 1.0;
    double d = 0.001;
    double a = M_PI * (d / 2) * (d / 2);
    double p_c = 1.78e-8;
    double p_s = 2300.0;
    double r_c = p_c  * (l / a);
    double r_s = p_s  * (l / a);
    double i = 25;
    double u_c = r_c * i;
    double u_s = r_s * i;
    printf("Spannung Kupfer: %lf\n", u_c);
    printf("Spannung Silizium: %lf\n", u_s);
}

void aufgabe31() {
    double a, b;
    scanf("%lf", &a);
    scanf("%lf", &b);
    printf("Summe: %lf\n", a + b);
    printf("Differenz: %lf\n", a - b);
    printf("Produkt: %lf\n", a * b);
    printf("Quotient: %lf\n", a / b);
}

void aufgabe32() {
    char c;
    scanf("%c", &c);
    printf("%c\n", c);
    printf("%d\n", c);
    printf("%#x\n", c);
}

void aufgabe33() {
    int num;
    scanf("%d", &num);
    printf("Zahl: %d\n", num);
    printf("Letzte Ziffer: %d\n", num % 10);
}