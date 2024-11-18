#include <stdio.h>
#include <stdlib.h>

#define N 3
#define M 4

void inizializza(int m[][M], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < M; ++j) {
            m[i][j] = rand()%1000;
        }
    }
}

void stampa(int m[][M], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < M; ++j) {
            printf("%6d", m[i][j]);
        }
        printf("\n");
    }
}

int massimo(int m[][M], int n) {
    int risultato = m[0][0];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < M; j++) {
            if (m[i][j] > risultato) {
                risultato = m[i][j];
            }
        }
    }
    return risultato;
}

void azzera_massimo(int m[][M], int n, int max) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < M; ++j) {
            if (m[i][j] == max) {
                m[i][j] = 0;
            }
        }
    }
}

int main(void) {
    int m[N][M];
    inizializza(m, N);
    stampa(m, N);
    int max = massimo(m, N);
    printf("Il valore massimo è %d\n", max);
    for(int i = 0; i < 3; ++i) {
        azzera_massimo(m, N, max);
        max = massimo(m, N);
    }
    stampa(m ,N);
    return 0;
}
