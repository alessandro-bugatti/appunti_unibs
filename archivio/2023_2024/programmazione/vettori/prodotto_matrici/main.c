#include <stdio.h>

#define N 3
#define M 4
#define O 5

int main() {
    int a[N][M], b[M][O], prodotto[N][O];

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < O; ++j) {
            int totale = 0;
            for (int k = 0; k < M; ++k) {
                totale += a[i][k] * b[k][j];
            }
            prodotto[i][j] = totale;
        }
    }

    return 0;
}
