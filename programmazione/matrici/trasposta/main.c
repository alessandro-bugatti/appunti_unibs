#include <stdio.h>
#include <stdlib.h>

#define N 3
#define M 4


int main(void) {
    int m[N][M], t[M][N];
    for(int i = 0 ; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            m[i][j] = rand()%20;
        }
    }
    for(int i = 0; i < N; i++) {
        for (int j = 0; j < M; ++j) {
            printf("%4d", m[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            t[j][i] = m[i][j];
        }
    }

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%4d", t[i][j]);
        }
        printf("\n");
    }

    return 0;
}
