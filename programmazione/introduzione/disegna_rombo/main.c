#include <stdio.h>

int main(void) {
    int N, n_asterischi = 1, n_spazi;
    printf("Inserisci la dimensione del lato: ");
    scanf("%d", &N);
    n_spazi = N - 1;
    //Righe del "triangolo superiore"
    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < n_spazi; ++j) {
            printf(" ");
        }
        for (int j = 0; j < n_asterischi; ++j) {
            printf("*");
        }
        printf("\n");
        n_asterischi += 2;
        n_spazi--;
    }

    //Disegno della diagonale orizzontale
    for (int i = 0; i < 2*N - 1; ++i) {
        printf("*");
    }
    printf("\n");
    n_asterischi = 2 * N - 3;
    n_spazi = 1;
    //Righe del "triangolo superiore"
    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < n_spazi; ++j) {
            printf(" ");
        }
        for (int j = 0; j < n_asterischi; ++j) {
            printf("*");
        }
        printf("\n");
        n_asterischi -= 2;
        n_spazi++;
    }
    return 0;
}
