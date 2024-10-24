#include <stdio.h>

int main(void) {
    int N, spazi_prima, spazi_dopo;
    printf("Inserisci N:");
    scanf("%d", &N);
    spazi_prima = 1;
    spazi_dopo = N - 4;
    for(int i = 0; i < N; ++i) {
        printf("*");
    }
    printf("\n");
    //Stampa le righe centrali
    for(int i = 0; i < N / 2 - 1; ++i) {
        for(int j = 0; j < spazi_prima; ++j) {
            printf(" ");
        }
        printf("*");
        for(int j = 0; j < spazi_dopo; ++j) {
            printf(" ");
        }
        printf("*\n");
        spazi_prima++;
        spazi_dopo -= 2;
    }
    for(int i = 0; i < spazi_prima; ++i) {
        printf(" ");
    }
    printf("*\n");
    return 0;
}
