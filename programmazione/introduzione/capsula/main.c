#include <stdio.h>

int main(void) {
    int N, n_spazi_inizio, n_spazi_centro;
    printf("Inserisci il lato della capsula: ");
    scanf("%d", &N);
    n_spazi_inizio = N;
    n_spazi_centro = N;
    //Lato superiore
    for (int i = 0; i < n_spazi_inizio; ++i) {
        printf(" ");
    }
    for (int i = 0; i < N; ++i) {
        printf("_");
    }
    printf("\n");
    n_spazi_inizio--;
    //Lati superiori
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < n_spazi_inizio; ++j) {
            printf(" ");
        }
        printf("/");
        for (int j = 0; j < n_spazi_centro; ++j) {
            printf(" ");
        }
        printf("\\\n");
        n_spazi_inizio--;
        n_spazi_centro += 2;

    }
    //Parte centrale della capsula
    for (int i = 0; i < N; ++i) {
        printf("|");
        for (int j = 0; j < 2 * N + 2; ++j) {
            printf(" ");
        }
        printf("|\n");
    }

    return 0;
}
