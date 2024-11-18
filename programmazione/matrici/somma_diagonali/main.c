#include <stdio.h>
#include <stdlib.h>

#define N 5

int main(void) {
    int m[N][N];
    int diag_principale = 0, diag_secondaria = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            m[i][j] = rand()%20;
        }
    }
    for (int i = 0; i < N; ++i) {
        diag_principale += m[i][i];
        diag_secondaria += m[i][N - i - 1];
    }
    //Modo alternativo per la diagonale secondaria
    int j = N - 1;
    for (int i = 0; i < N; ++i) {
        diag_secondaria += m[i][j];
        j--;
    }
    printf("%d\n", diag_principale);
    printf("%d\n", diag_secondaria);
    return 0;
}
