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

int main(void) {
    int tris[DIM][DIM], giocatore = 1;
    inizializza(tris, DIM, 0);

    stampa(tris, DIM);

    while (1) {
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

    return 0;
}