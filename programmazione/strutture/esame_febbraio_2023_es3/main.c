#include <stdio.h>
#include <string.h>

typedef struct {
    char ID[21];
    char g1[30];
    char g2[30];
    int griglia[3][3];
    int stato; //0 pareggio, 1 vinto il giocatore 1,
                //2 vinto il giocatore 2, 3 partita in corso
} Partita;

typedef struct {
    Partita partite[100];
    int n_partite;
} Torneo;

int fai_mossa(Torneo *t, char ID[], int r, int c, int g){
    if (r < 0 || r > 2)
        return -1;
    if (c < 0 || c > 2)
        return -1;
    for (int i = 0; i < t->n_partite; ++i) {
        if (strncmp(t->partite[i].ID, ID, 20) == 0){
            //verifico se la cella è già occupata
            if (t->partite[i].griglia[r][c] != 0){
                return -1;
            }
            t->partite[i].griglia[r][c] = g;
            return g;
        }
    }
    return -1;
}

//Modificata rispetto alla richiesta del tema d'esame
int calcola_punteggio(Torneo t, char cognome[]){
    int punteggio = 0;
    int trovato = 0;
    for (int i = 0; i < t.n_partite; ++i) {
        if (strncmp(t.partite[i].g1, cognome, 30) == 0){
            if (t.partite[i].stato == 1){
                punteggio += 3;
            }
            if (t.partite[i].stato == 0){
                punteggio += 1;
            }
            trovato = 1;
        }
        if (strncmp(t.partite[i].g2, cognome, 30) == 0){
            if(t.partite[i].stato == 2){
                punteggio += 3;
            }
            if(t.partite[i].stato == 0){
                punteggio += 1;
            }
            trovato = 1;
        }
    }
    if (trovato == 1)
        return punteggio;
    return -1;
}

int main() {

    return 0;
}
