#include <stdio.h>
#include <stdlib.h>

#define N 100

void inizializza(int m[][N], int r, int c) {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            m[i][j] = rand()%10;
        }
    }
}

void stampa(int m[][N], int r, int c) {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            printf("%10d", m[i][j]);
        }
        printf("\n");
    }
}

void prodotto(int a[][N], int b[][N], int c[][N],int m, int n, int p) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j) {
            c[i][j] = 0;
            for(int k = 0; k < n; ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main(void) {
    int a[N][N], b[N][N], c[N][N];
    int m, n, p;
    printf("Dimmi il numero di righe della prima matrice: ");
    scanf("%d", &m);
    printf("Dimmi il numero di colonne della prima matrice: ");
    scanf("%d", &n);
    printf("Dimmi il numero di colonne della seconda matrice: ");
    scanf("%d", &p);
    inizializza(a, m, n);
    stampa(a,m,n);
    inizializza(b, n, p);
    stampa(b, n, p);
    prodotto(a, b, c, m, n, p);
    stampa(c, m, p);

    return 0;
}
