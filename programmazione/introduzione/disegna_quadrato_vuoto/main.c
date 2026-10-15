#include <stdio.h>

int main(void) {
    int N;
    printf("Inserisci il lato del quadrato: ");
    scanf("%d", &N);
    //Stampa la prima linea
    for (int i = 0; i < N; ++i) {
        printf("*");
    }
    printf("\n");
    //Stampa le linee che presentano dei "buchi"
    for (int i = 0; i < N - 2; ++i) {
        printf("*");
        for (int j = 0; j < N - 2; ++j) {
            printf(" ");
        }
        printf("*\n");
    }

    //Stampa l'ultima linea
    for (int i = 0; i < N; ++i) {
        printf("*");
    }
    printf("\n");
    return 0;
}
