#include <stdio.h>

const int DIM = 3;

char converti(int n) {
    if (n == 0) {
        return ' ';
    }
    if (n == 1) {
        return 'x';
    }
    return 'o';
}

void stampa(int m[][DIM], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%c", converti(m[i][0]));
        for (int j = 0; j < 2; ++j) {
            printf(" | %c", converti(m[i][j + 1]));
        }
        printf("\n");
        if (i < 2) {
            printf("----------\n");
        }
    }
}

void inizializza (int m[][DIM], int n, int valore) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < DIM; ++j) {
            m[i][j] = valore;
        }
    }
}

int mossa_valida(int m[][DIM], int r, int c) {
    if (r < 0 || r > 2) {
        return 0;
    }
    if (c < 0 || c > 2) {
        return 0;
    }
    if (m[r][c] != 0) {
        return 0;
    }
    return 1;
}

/**
 *
 * @param m la matrice delle mosse
 * @param r il numero di righe
 * @return  0 se il gioco è in corso
 *          1 se ha vinto il giocatore 1
 *          2 se ha vinto il giocatore 2
 *          3 se è finita in parità
 */
int controllo(int m[][DIM], int r) {
    //Controllo delle righe
    for (int i = 0; i < r; ++i) {
        if (m[i][0] == m[i][1] && m[i][1] == m[i][2] &&
            m[i][0] != 0) {
            return m[i][0];
        }
    }
    //Controllo delle colonne
    for (int i = 0; i < DIM; ++i) {
        if (m[0][i] == m[1][i] && m[1][i] == m[2][i] &&
            m[0][i] != 0) {
            return m[0][i];
        }
    }
    //Controllo della prima diagonale
    if (m[0][0] == m[1][1] && m[1][1] == m[2][2] &&
        m[0][0] != 0) {
        return m[0][0];
    }
    //Controllo della seconda diagonale
    if (m[0][2] == m[1][1] && m[1][1] == m[2][0] &&
        m[0][2] != 0) {
        return m[0][2];
    }
    //Verifica se ci sono ancora posizioni disponibili
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < DIM; ++j) {
            if (m[i][j] == 0) {
                return 0;
            }
        }
    }
    return 3;
}

int main(void) {
    int tris[DIM][DIM], giocatore = 1;
    inizializza(tris, DIM, 0);

    stampa(tris, DIM);

    while (controllo(tris, DIM) == 0) {
        int riga, colonna;
        printf("Inserisci la riga: ");
        scanf("%d", &riga);
        printf("Inserisci al colonna: ");
        scanf("%d", &colonna);
        while (mossa_valida(tris, riga - 1, colonna - 1) == 0) {
            printf("ERRORE\nInserisci la riga: ");
            scanf("%d", &riga);
            printf("Inserisci al colonna: ");
            scanf("%d", &colonna);
        }
        tris[riga - 1][colonna - 1] = giocatore;
        if (giocatore == 1) {
            giocatore = 2;
        }else {
            giocatore = 1;
        }
        stampa(tris, DIM);
    }
    int risultato = controllo(tris, DIM);
    if (risultato == 1) {
        printf("Ha vinto il giocatore 1");
    }
    else if (risultato == 2) {
        printf ("Ha vinto il giocatore 2");
    }
    else {
        printf("Parità");
    }

    return 0;
}