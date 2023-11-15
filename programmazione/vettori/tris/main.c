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
    printf("%c|%c|%c\n", simboli(tris[0][0]), simboli(tris[0][1]), simboli(tris[0][2]));
    printf("-----\n");
    printf("%c|%c|%c\n", simboli(tris[1][0]), simboli(tris[1][1]), simboli(tris[1][2]));
    printf("-----\n");
    printf("%c|%c|%c\n", simboli(tris[2][0]), simboli(tris[2][1]), simboli(tris[2][2]));
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

}

//Seconda soluzione, con passaggio per indirizzo
void cambia_turno(int *giocatore){

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
        int riga, colonna;
        printf ("Tocca al giocatore %d fare la sua mossa\n", turno);
        printf ("Inserisci la riga: ");
        scanf ("%d", &riga);
        printf ("Inserisci la colonna: ");
        scanf ("%d", &colonna);
        while(!mossa_valida(riga - 1, colonna - 1, griglia)){

        }
        griglia[riga - 1][colonna - 1] = turno;
        stato = controlla_stato(griglia);
        cambia_turno(&turno);
    }


    return 0;
}
