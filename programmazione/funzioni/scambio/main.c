#include <stdio.h>

void scambio(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

void scambio_vero(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a = 7, b = 5;
    printf("Valori iniziali, a = %d, b = %d\n", a, b);
    //Qua non avviene nulla, passaggio per valore
    scambio(a, b);
    printf("a = %d, b = %d\n", a, b);
    //Qua avviene lo scambio, passaggio per indirizzo
    scambio_vero(&a, &b);
    printf("a = %d, b = %d\n", a, b);
    printf("&a = %p, &b = %p\n", &a, &b);
    int *c, *d;
    c = &a;
    d = &b;
    *c = 15;
    printf("a = %d, b = %d\n", a, b);
    printf("*c = %d, *d = %d\n", *c, *d);
    printf("c = %p, d = %p\n", c, d);
    printf("&c = %p, &d = %p\n", &c, &d);
    c = 0;
    a = *c + b;


    return 0;
}