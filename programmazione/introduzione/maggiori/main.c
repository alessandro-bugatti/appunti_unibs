#include <stdio.h>
/*
 * Scrivere un programma che dati in input N numeri interi
 * trovi i due numeri maggiori
 */


int main(void) {
    int N, numero, max, max2;
    printf("Quanti numeri vuoi inserire? ");
    scanf("%d", &N);
    printf("Inserisci un numero: ");
    scanf("%d", &numero);
    max = numero;
    printf("Inserisci un numero: ");
    scanf("%d", &numero);
    max2 = numero;
    if (max2 > max) {
        int temp = max;
        max = max2;
        max2 = temp;
    }

    for (int i = 2; i < N; ++i) {
        printf("Inserisci un numero: ");
        scanf("%d", &numero);
        if (numero > max) {
            max2 = max;
            max = numero;
        }else if (numero > max2) {
            max2 = numero;
        }

    }
    printf("Il massimo è %d e il secondo più grande è %d", max, max2);
    return 0;
}