#include <stdio.h>
#include <stdlib.h>

#define DIM 3

char simboli(int n){
    if (n == 0)
        return ' ';
    if (n == 1)
        return 'X';
    if (n == 2)
        return 'O';
}

/**
 * \brief Verifica se una mossa è valida, cioè ricade nella griglia
 * e la casella non è già occupata
 * \param x posizione della riga, parte da 0
 * \param y posizione della colonna, parte da 0
 * \param tris matrice
 * \return 1 se la mossa è valida, 0 altrimenti
 */
int mossa_valida(int x, int y, int tris[][DIM]){
    if (x < 0 || x > 2)
        return 0;
    if (y < 0 || y > 2)
        return 0;
    if (tris[x][y] != 0)
        return 0;
    return 1;
}

void stampa_griglia(int tris[][DIM]){
    printf(" %c | %c | %c \n", simboli(tris[0][0]), simboli(tris[0][1]), simboli(tris[0][2]));
    printf("-----------\n");
    printf(" %c | %c | %c \n", simboli(tris[1][0]), simboli(tris[1][1]), simboli(tris[1][2]));
    printf("-----------\n");
    printf(" %c | %c | %c \n", simboli(tris[2][0]), simboli(tris[2][1]), simboli(tris[2][2]));
}

/**
 * \brief Controlla lo stato del gioco guardando i valori
 * che ci sono nella matrice
 * \param tris la matrice che contiene lo stato del gioco
 * \return
 * - 1 se ha vinto il giocatore 1
 * - 2 se ha vinto il giocatore 2
 * - 3 se la griglia è finita e quindi hanno pareggiato
 * - 0 se il gioco è in corso
 */
int controlla_stato(int tris[][DIM]){
    //Controllo delle righe
    for (int i = 0; i < DIM; ++i) {
        if (tris[i][0] == tris[i][1] &&
            tris[i][1] == tris[i][2] &&
            tris[i][0] != 0)
            return tris[i][0];
    }
    //Controllo per colonne
    for (int i = 0; i < DIM; ++i) {
        if (tris[0][i] == tris[1][i] &&
            tris[1][i] == tris[2][i] &&
            tris[0][i] != 0)
            return tris[0][i];
    }
    //prima diagonale
    if (tris[0][0] == tris[1][1] &&
        tris[1][1] == tris[2][2] &&
        tris[0][0] != 0)
        return tris[0][0];
    //seconda diagonale
    if (tris[0][2] == tris[1][1] &&
        tris[1][1] == tris[2][0] &&
        tris[0][2] != 0)
        return tris[0][2];
    for (int i = 0; i < DIM; ++i) {
        for (int j = 0; j < DIM; ++j) {
            if (tris[i][j] == 0)
                return 0;
        }
    }
    return 3;
}

//Con passaggio per indirizzo
void cambia_turno(int *giocatore){
    if (*giocatore == 1){
        *giocatore = 2;
    }
    else{
        *giocatore = 1;
    }
}

int main(){
    int griglia[DIM][DIM];
    int turno; // 1 o 2
    int stato;
    for (int i = 0; i < DIM; ++i) {
        for (int j = 0; j < DIM; ++j) {
            griglia[i][j] = 0;
        }
    }

    stato = controlla_stato(griglia);
    while(stato == 0){
        stampa_griglia(griglia);
        int riga, colonna;
        printf ("Tocca al giocatore %d fare la sua mossa\n", turno);
        printf ("Inserisci la riga: ");
        scanf ("%d", &riga);
        printf ("Inserisci la colonna: ");
        scanf ("%d", &colonna);
        while(!mossa_valida(riga - 1, colonna - 1, griglia)){
            printf("Attenzione, i valori di riga e colonna non sono corretti");
            printf ("Inserisci la riga: ");
            scanf ("%d", &riga);
            printf ("Inserisci la colonna: ");
            scanf ("%d", &colonna);
        }
        griglia[riga - 1][colonna - 1] = turno;
        stato = controlla_stato(griglia);
        cambia_turno(&turno);
    }
    stampa_griglia(griglia);
    if (stato == 3){
        printf("Pareggio");
    }
    else{
        printf("Ha vinto il giocatore %d.\n", stato);
    }


    return 0;
}
