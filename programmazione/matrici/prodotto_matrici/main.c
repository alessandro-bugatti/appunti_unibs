#include <stdio.h>

#define M 3
#define N 4
#define P 5

void prodotto_matrici(float a[][N], float b[][P], float c[][P]) {
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < P; ++j) {
            float somma = 0;
            for (int r = 0; r < N; ++r) {
                somma += a[i][r] * b[r][j];
            }
            c[i][j] = somma;
        }
    }
}

int main(void) {
    float a[M][N], b[N][P], c[M][P];
    //Inizializza le matrici a e b
    prodotto_matrici(a, b, c);
    return 0;
}
