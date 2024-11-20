#include <stdio.h>

#define N 3

/**
 *
 * @param tris
 * @param r da 1 a 3
 * @param c da 1 a 3
 * @return
 */
int coordinate_valide(int tris[][N], int r, int c) {
    if (r < 1 || r > 3) {
        return 0;
    }
    if (c < 1 || c > 3) {
        return 0;
    }
    //Controllo se la casella è già occupata
    if (tris[r-1][c-1] != 0) {
        return 0;
    }
    return 1;
}

/*
 * ritorna:
 * 0 se il gioco può continuare
 * 1 se ha vinto il giocatore 1
 * 2 se ha vinto il giocatore 2
 * 3 se c'è pareggio
 */
int controlla(int tris[][N]) {
    //Controllo delle righe
    for (int i = 0; i < 3; ++i) {
        if (tris[i][0] == tris[i][1] &&
            tris[i][1] == tris[i][2] &&
            tris[i][0] != 0) {
            return tris[i][0];
        }
    }
    //Controllo delle colonne
    for (int i = 0; i < 3; ++i) {
        if (tris[0][i] == tris[1][i] &&
            tris[1][i] == tris[2][i] &&
            tris[0][i] != 0) {
            return tris[0][i];
            }
    }
    if (tris[0][0] == tris[1][1] &&
        tris[1][1] == tris[2][2] &&
        tris[0][0] != 0) {
        return tris[0][0];
    }
    //Altra diagonale
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (tris[i][j] == 0) {
                return 0;
            }
        }
    }
    return 3;


}

int main(void)
{
    int tris[N][N];
    return 0;
}
