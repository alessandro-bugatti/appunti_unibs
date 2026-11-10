#include <stdio.h>

#define R 3
#define C 3

int main(void) {
    int m[R][C];
    /*Inserimento dei valori
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            printf("Inserisci il valore della cella %d %d: ",
                i + 1, j + 1);
            scanf("%d", &m[i][j]);
        }
    }*/
    //Inserimento automatico di valori
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            m[i][j] = i * 3 + j;
        }
    }
    //Calcolo della trasposta
    for (int i = 0; i < R; ++i) {
        for (int j = 0 ; j < i; ++j) {
            int temp = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = temp;
        }
    }
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            printf("%3d", m[i][j]);
        }
        printf("\n");
    }
    return 0;
}
