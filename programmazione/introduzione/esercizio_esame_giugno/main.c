#include <stdbool.h>
#include <stdio.h>

int main(void) {
    int N, conta_uno, corretto;
    printf("Inserisci un numero N: ");
    scanf("%d", &N);
    while ( N >= 0) {
        conta_uno = 0;
        corretto = 1;
        while (N > 0 && corretto) {
            if (N % 10 == 1) {
                conta_uno++;
            }
            if (N % 10 != 0 && N % 10 != 1) {
                corretto = 0;
            }
            N = N / 10;
        }
        if (!corretto) {
            printf("Numero non valido\n");
        }
        else if (conta_uno % 2 == 0) {
            printf("Parità pari\n");
        }
        else {
            printf("Parità dispari\n");
        }
        printf("Inserisci un numero N: ");
        scanf("%d", &N);
    }
    printf("Programma terminato");
    return 0;
}