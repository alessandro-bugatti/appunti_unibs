#include <stdio.h>

#define N 3

void inizializza(int t[][N], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < N; ++j) {
            t[i][j] = 0;
        }
    }
}

char simboli(int n) {
    if (n == 0) {
        return ' ';
    }
    if (n == 1) {
        return 'x';
    }
    return 'o';
}

void stampa(int t[][N], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%c", simboli(t[i][0]));
        for (int j = 1; j < N; ++j) {
            printf(" | %c", simboli(t[i][j]));
        }
        printf("\n");
        //Per evitare la stampa della terza riga orizzontale
        if ( i < n - 1) {
            printf("------------\n");
        }
    }
}

/**
 *
 * @param t matrice del tris
 * @param n numero di righe
 * @return 0 se il gioco non è finito
 * 1 se ha vinto il giocatore 1
 * 2 se ha vinto il giocatore 2
 * 3 se patta
 */
int vittoria(int t[][N], int n) {
    //Controllo delle righe
    for (int i = 0; i < n; ++i) {
        if (t[i][0] == t[i][1] && t[i][1] == t[i][2]
            && t[i][0] != 0) {
            return t[i][0];
        }
    }
    //Controllo delle colonne
    for (int i = 0; i < n; ++i) {
        if (t[0][i] == t[1][i] && t[1][i] == t[2][i]
            && t[0][i] != 0) {
                return t[0][i];
            }
    }
    //Controllo della prima diagonale
    if (t[0][0] == t[1][1] && t[1][1] == t[2][2]
            && t[0][0] != 0) {
                return t[0][0];
            }
    //Controllo della seconda diagonale
    if (t[0][2] == t[1][1] && t[1][1] == t[2][0]
            && t[0][2] != 0) {
        return t[0][2];
            }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < N; ++j) {
            if (t[i][j] == 0) {
                return 0;
            }
        }
    }
    return 3;
}

int mossa_valida(int t[][N], int n, int r, int c) {
    if (r < 0 || r >= n) {
        return 0;
    }
    if (c < 0 || c >= N) {
        return 0;
    }
    if (t[r][c] != 0) {
        return 0;
    }
    return 1;
}

int main(void) {
    int tris[N][N], giocatore = 1;
    inizializza(tris, N);
    while (!vittoria(tris, N)) {
        int r, c;
        stampa(tris, N);
        printf("Turno del giocatore %d\n", giocatore);
        printf("Inserisci la casella su cui vuoi mettere il segno: ");
        scanf("%d", &r);
        scanf("%d", &c);
        while (!mossa_valida(tris, N, r - 1, c - 1)) {
            printf("Mossa non valida\n");
            printf("Inserisci la casella su cui vuoi mettere il segno: ");
            scanf("%d", &r);
            scanf("%d", &c);
        }
        //Si suppone che il giocatore veda le caselle a partire da 1
        tris[r - 1][c - 1] = giocatore;
        if (giocatore == 1) {
            giocatore = 2;
        }else {
            giocatore = 1;
        }
    }
    stampa(tris, N);
    // if di controllo della vittoria
    int risultato = vittoria(tris, N);
    if (risultato == 3) {
        printf("Patta\n");
    }
    else {
        printf("Ha vinto il giocatore %d\n", risultato);
    }
    return 0;
}
