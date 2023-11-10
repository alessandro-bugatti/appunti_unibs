#include <stdio.h>

#define N 3

int main() {
    int matrice[N][N];
    //input, inizializzazione
    int somma = 0;

    for (int i = 0; i < 3; ++i) {
        somma += matrice[i][i];
    }

    return 0;
}
