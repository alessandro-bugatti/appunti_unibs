#include <stdio.h>

int main(void) {
    int N, numero, max, min;
    printf("Quanti numeri vuoi inserire? ");
    scanf("%d", &N);
    printf("Inserisci un numero: ");
    scanf("%d", &numero);
    max = numero;
    min = numero;
    for (int i = 1; i < N; ++i) {
        printf("Inserisci un numero: ");
        scanf("%d", &numero);
        if (numero > max) {
            max = numero;
        }
        if (numero < min) {
            min = numero;
        }
    }
    printf("Il massimo è %d e il minimo è %d", max, min);
    return 0;
}