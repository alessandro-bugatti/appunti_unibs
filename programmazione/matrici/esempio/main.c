#include <stdio.h>
#include <stdlib.h>

const int RIGHE = 3;
const int COLONNE = 3;

int main(void) {
    int m[RIGHE][COLONNE];
    int t[COLONNE][RIGHE];
    //SUpponiamo di voler riempire completamente la matrici di
    //interi causali
    for (int i = 0; i < RIGHE; ++i) {
        for (int j = 0; j < COLONNE; ++j) {
            m[i][j] = rand()%100;
        }
    }

    for (int i = 0; i < RIGHE; ++i) {
        for (int j = 0; j < COLONNE; ++j) {
            printf("%3d", m[i][j]);
        }
        printf("\n");
    }
    //Calcolo della trasposta di m

    for (int i = 0; i < RIGHE; ++i) {
        for (int j = 0; j < COLONNE; ++j) {
            t[j][i] = m[i][j];
        }
    }

    for (int i = 0; i < COLONNE; ++i) {
        for (int j = 0; j < RIGHE; ++j) {
            printf("%3d", t[i][j]);
        }
        printf("\n");
    }

    //Calcolo della somma degli elementi sulla diagonale di m
    int somma = 0;
    for (int i = 0; i < RIGHE; ++i) {
        somma += m[i][i];
    }
    printf("Somma: %d\n", somma);
    return 0;
}