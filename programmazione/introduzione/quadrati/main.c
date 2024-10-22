#include <stdio.h>

/*
 * Dato in input un intero positivo N,
 * stampare un quadrato di lato N composto da x
 * N = 3
 * xxx
 * xxx
 * xxx
 */

int main(void) {
    int N;
    printf("Inserisci N: ");
    scanf("%d", &N);
    //Ciclo esterno per la ripetizione delle singole righe
    for (int i = 0; i < N; ++i) {
        //Stampa della singola riga
        for (int j = 0; j < N; ++j) {
            printf("x");
        }
        printf("\n");
    }
    return 0;
}
