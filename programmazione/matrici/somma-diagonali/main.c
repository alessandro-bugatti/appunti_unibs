#include <stdio.h>

#define N 3

int main(void) {
    int m[N][N], somma = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            m[i][j] = i * N + j;
        }
    }
    //Elementi della diagonale maggiore
    for (int i = 0; i < N; ++i) {
        somma += m[i][i];
    }
    //Elementi della diagonale maggiore
    for (int i = 0; i < N; ++i) {
        somma += m[N - i - 1][i];
    }
    printf("%d\n", somma);
    return 0;
}
