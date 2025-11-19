#include <stdio.h>
#include <stdlib.h>
#define RIGHE 3
#define COLONNE 4

int massimo(int m[][COLONNE], int n) {
    int max = m[0][0];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < COLONNE; ++j) {
            if (m[i][j] > max) {
                max = m[i][j];
            }
        }
    }
    return max;
}

void inizializza(int m[][COLONNE], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < COLONNE; ++j) {
            m[i][j] = rand() % 100;
        }
    }
}

void stampa(int m[][COLONNE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < COLONNE; ++j) {
            printf("%12d", m[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    int m[RIGHE][COLONNE];
    inizializza(m, RIGHE);
    stampa(m, RIGHE);
    int max = massimo(m, RIGHE);
    printf("Il massimo elemento della matrice è %d\n",
        max);
    return 0;
}