#include <stdio.h>

void scambio_copia(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

void scambio(int *a, int *b) {
    printf("Indirizzo di a: %p\n", a);
    printf("Indirizzo di b: %p\n", b);
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    int a = 7, b = 5;
    scambio_copia(a, b);
    printf("%d %d\n", a, b);
    scambio(&a, &b);
    printf("Indirizzo di a: %p\n", &a);
    printf("Indirizzo di b: %p\n", &b);
    printf("%d %d\n", a, b);
    return 0;
}