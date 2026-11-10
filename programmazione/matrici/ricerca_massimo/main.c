#include <stdio.h>

#define R 4
#define C 6

/**
 *
 * @param m matrice
 * @param n numero di righe utili
 * @return
 */
int massimo(int m[][C], int n) {
    int max = m[0][0];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < C; j++) {
            if (m[i][j] > max) {
                max = m[i][j];
            }
        }
    }
    return max;
}

int main(void) {
    int m[R][C];

    printf("%d", massimo(m, R));

    return 0;
}

