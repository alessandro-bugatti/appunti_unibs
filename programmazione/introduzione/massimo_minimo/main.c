#include <stdio.h>

int main() {
    int N;
    int numero, massimo, minimo;
    printf("Dimmi N: ");
    scanf("%d", &N);
    printf("Inserisci un numero: ");
    scanf("%d", &numero);
    massimo = minimo = numero;
    for (int i = 0; i < N - 1; ++i) {
        printf("Inserisci un numero: ");
        scanf("%d", &numero);
        if (numero > massimo){
            massimo = numero;
        }
        if (numero < minimo){
            minimo = numero;
        }
    }
    printf("Massimo: %d, minimo: %d", massimo, minimo);
    return 0;
}
