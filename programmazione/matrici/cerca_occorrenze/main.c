#include <stdio.h>
#include <stdlib.h>

#define RIGHE 3
#define COLONNE 10

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
            printf("%5d", m[i][j]);
        }
        printf("\n");
    }
}

int quante(int v[], int n, int cercato) {
    int conta = 0;
    for (int i = 0; i < n; ++i) {
        if (v[i] == cercato) {
            conta++;
        }
    }
    return conta;
}

void cerca_occorrenze(int m[][COLONNE], int n, int cercato, int v[]) {
    for (int i = 0; i < n; ++i) {
        v[i] = quante(m[i], COLONNE, cercato);
    }
}


int main(void) {
    int valori[RIGHE][COLONNE];
    int occorrenze[RIGHE], n;
    inizializza(valori, RIGHE);
    stampa(valori, RIGHE);
    printf("Inserisci il valore che vuoi trovare: ");
    scanf("%d", &n);
    cerca_occorrenze(valori, RIGHE, n, occorrenze);
    for (int i = 0; i < RIGHE; ++i) {
        printf("%d in riga %d %d volte\n",
                    n, i + 1, occorrenze[i]);
    }
    return 0;
}