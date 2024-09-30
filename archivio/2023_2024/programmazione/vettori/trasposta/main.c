#include <stdio.h>
#include <stdlib.h>

#define N 4

int main() {
    int matrice[N][N];
    //Inizializziamo la matrice con valori casuali
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            matrice[i][j] = rand()%100;
        }
    }

    printf("Matrice originale\n");

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%3d", matrice[i][j]);
        }
        printf("\n");
    }

    //Trasposta
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            int temp = matrice[i][j];
            matrice[i][j] = matrice[j][i];
            matrice[j][i] = temp;
        }
    }

    printf("Matrice trasposta\n");

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%3d", matrice[i][j]);
        }
        printf("\n");
    }

    return 0;
}
