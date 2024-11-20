#include <stdio.h>

#define N 30

/**
 *
 * @param m matrice
 * @param r numero di righe della matrice e elementi del vettore
 * @param c numero di colonne utilizzate
 * @param v il vettore che conterrà i risultati
 * @param n il numero da cercare
 */
void valori_uguali(int m[][N], int r, int c, int v[], int n) {
    for (int i = 0; i < r; ++i) {
        int conta = 0;
        for (int j = 0; j < c; ++j) {
            if (m[i][j] == n) {
                conta++;
            }
            v[i] = conta;
        }
    }
}

int main(void) {
    int m[N][N], v[N];
    int r = 4, c = 6;
    valori_uguali(m, r, c, v, 2);
    for (int i = 0; i < r; ++i) {
        printf("%d\n", v[i]);
    }
    return 0;
}
