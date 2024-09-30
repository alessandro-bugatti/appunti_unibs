#include <stdio.h>
#include <stdlib.h>

#define N 3

int main() {
    int matrice[N][N];
    //Inizializziamo la matrice con valori casuali
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            matrice[i][j] = rand()%100;
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }

    int somma = 0;
    printf("Somma della diagonale principale\n");
    for (int i = 0; i < N; ++i) {
        somma += matrice[i][i]; //
    }
    printf("Diagonale principale: %d", somma);

    somma = 0;
    printf("Somma della diagonale secondaria\n");
    for (int i = 0; i < N; ++i) {
        somma += matrice[i][N - 1 - i];
    }
    printf("Diagonale secondaria: %d", somma);

    return 0;
}
