#include <stdio.h>

int main(void) {
    int N, numero, massimo, minimo;
    printf("Dimmi quanti numeri vuoi inserire: ");
    scanf("%d", &N);
    printf("Inserisci un numero: ");
    scanf("%d", &numero);
    massimo = numero;
    minimo = numero;
    for (int i = 0; i < N - 1; ++i) {
        printf("Inserisci un numero: ");
        scanf("%d", &numero);
        if (numero > massimo) {
            massimo = numero;
        }
        if (numero < minimo) {
            minimo = numero;
        }
    }
    printf("Il massimo è %d e il minimo è %d\n",
        massimo, minimo);
    return 0;
}
