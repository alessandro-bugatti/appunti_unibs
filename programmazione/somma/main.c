#include <stdio.h>

int main(void) {
    int a, b, somma;
    printf("Inserisci il primo numero: ");
    scanf("%d", &a);
    printf("Inserisci il secondo numero: ");
    scanf("%d", &b);
    somma = a + b;
    printf("Il risultato della somma tra %d e %d è %d\n",
            a, b, somma);
    return 0;
}
