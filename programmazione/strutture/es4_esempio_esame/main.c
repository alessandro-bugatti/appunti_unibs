#include <stdio.h>

#define LUNGHEZZA 50

#define NUM_GIOCATRICI 12

typedef struct
{
    char nominativo[LUNGHEZZA];
    int numero;
    int ruolo; // 0 - centrale, 1 - ala, 2 - palleggiatrice, 3 - libero
    int schiacciate;
    int muri;
    int punti;
    int in_campo; //1 in campo, 0 in panchina
}Giocatrice;


typedef struct
{
    char stato[LUNGHEZZA];
    Giocatrice giocatrici[NUM_GIOCATRICI];
} Squadra;

//Volendo, per semplicità, si poteva passare per copia
int composizione_corretta(const Squadra *s) {
    //Controllo siano esattamente 6
    int quante = 0;
    for (int i = 0; i < NUM_GIOCATRICI; ++i) {
        if (s->giocatrici[i].in_campo == 1) {
            quante++;
        }
    }
    if (quante != 6) {
        return 0;
    }
    //Controllo la composizione
    int centrali = 0, ali = 0, palleggiatrici = 0, liberi = 0;
    for (int i = 0; i < NUM_GIOCATRICI; ++i) {
        //Se laa giocatrice è in campo
        if (s->giocatrici[i].in_campo == 1) {
            //Verifico che ruolo ha
            if (s->giocatrici[i].ruolo == 0) {
                centrali++;
            }
            if (s->giocatrici[i].ruolo == 1) {
                ali++;
            }
            if (s->giocatrici[i].ruolo == 2) {
                palleggiatrici++;
            }
            if (s->giocatrici[i].ruolo == 3) {
                liberi++;
            }
        }
    }
    if (centrali != 2 || ali != 2 || palleggiatrici != 1 ||
        liberi != 1) {
        return 0;
    }
    return 1;
}

/**
 *
 * @param giocatrici Vettore delle giocatrici con n_giocatrici
 * @param n_giocatrici numero di giocatrici presenti nel vettore
 * @param g giocatrice da inserire se non è già presente una giocatrice con lo stesso numero
 * @return 1 se presente, 0 se non presente
 */
int numero_presente(Giocatrice giocatrici[], int n_giocatrici, Giocatrice g) {
    for (int i = 0; i < n_giocatrici; ++i) {
        if (giocatrici[i].numero == g.numero) {
            return 1;
        }
    }
    return 0;
}

void aggiusta_numeri(Squadra *squadra) {
    Giocatrice giocatrici[NUM_GIOCATRICI]; //vettore d'appoggio
    for (int i = 0; i < NUM_GIOCATRICI; ++i) {
        //finchè la giocatrice i - esima della squadra ha un numero che
        //è già presente in una giocatrice del vettore d'appoggio
        //incremento il suo numero
        while (numero_presente(giocatrici, i, squadra->giocatrici[i]) == 1) {
            squadra->giocatrici[i].numero++;
        }
        giocatrici[i] = squadra->giocatrici[i];
    }
    for (int i = 0; i < NUM_GIOCATRICI; ++i) {
        squadra->giocatrici[i] = giocatrici[i];
    }
}

int main(void) {

    return 0;
}