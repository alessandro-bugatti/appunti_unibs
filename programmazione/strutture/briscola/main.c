#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char semi[][10] = {
    "🏆",
    "🪙",
    "🪵",
    "⚔️"
};

typedef struct
{
    int valore;
    char seme[10];
    int punteggio;
} Carta;

typedef struct
{
    Carta carte[40];
    int n_carte;
} Mazzo;

typedef struct
{
    Carta carte[3];
    int n_carte;
} Mano;



void inizializza(Mazzo *m) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 10; ++j) {
            m->carte[i*10 + j].valore = j + 1;
            //Il punteggio deve essere messo a posto
            m->carte[i*10 + j].punteggio = 0;
            strncpy(m->carte[i*10 + j].seme, semi[i], 10);
        }
    }
    m->n_carte = 40;
}

void stampa_carta(Carta c) {
    if (c.valore == 8) {
        printf("Fante di");
    }
    else if (c.valore == 9) {
        printf("Cavallo di");
    }
    else if (c.valore == 10) {
        printf("Re di");
    }
    else {
        printf("%d di", c.valore);
    }
    printf(" %s ", c.seme);
}

void stampa_mazzo(Mazzo m) {
    for (int i = 0; i < m.n_carte; ++i) {
        stampa_carta(m.carte[i]);
        printf("\n");
    }
}

void mescola_mazzo(Mazzo *m) {
    for (int i = 0; i < m->n_carte; ++i) {
        int n = rand() % m->n_carte;
        Carta c = m->carte[i];
        m->carte[i] = m->carte[n];
        m->carte[n] = c;
    }
}

//Funzione per il gioco
void stampa_mano(Mano mano){
    for (int i = 0; i < mano.n_carte; ++i) {
        stampa_carta(mano.carte[i]);
    }
    printf("\n");
}

//Serve per estrarre la successiva carta del mazzo
Carta dai_carta(Mazzo *mazzo){
    Carta c = mazzo->carte[mazzo->n_carte - 1];
    mazzo->n_carte--;
    return c;
}

//Serve per permettere a un giocatore di tirare
//una carta della propria mano
//n parte da 0
Carta tira_carta(Mano *mano, int n){
    for (int i = n; i < mano->n_carte - 1; ++i) {
        mano->carte[i] = mano->carte[i + 1];
    }
    mano->n_carte--;
}

//Inserisce una carta in una mano
void pesca_carta(Mano *mano, Carta carta){
    if (mano->n_carte == 3) {
        return;
    }
    mano->carte[mano->n_carte] = carta;
    mano->n_carte++;
}

//Serve ad aggiungere una carta nel mazzetto di un giocatore
void raccogli_carta(Carta carta, Mazzo *mazzo){
    mazzo->carte[mazzo->n_carte];
    mazzo->n_carte++;
}

//Serve a far tirare il computer
Carta scelta_AI(Mano *mano, Carta briscola, int turno, Carta giocata){
    return mano->carte[rand() % mano->n_carte];
}

//Verifica chi vince delle due carte tirate
int vince(Carta prima, Carta seconda, char seme_briscola[]){
    if (strncmp(prima.seme,seme_briscola, 10) == 0 &&
        strncmp(seconda.seme, seme_briscola, 10) != 0) {
        return 1;
        }
    if (strncmp(prima.seme,seme_briscola, 10) != 0 &&
            strncmp(seconda.seme, seme_briscola, 10) == 0) {
            return 2;
        }
    //Se le carte avessero un potere di presa pari al valore il codice sarebbe questo
    if (strncmp(prima.seme, seconda.seme, 10) == 0) {
        if (prima.valore > seconda.valore) {
            return 1;
        }
        return 2;
    }
    return 1;
}

//Qui la testa del mazzo è usata per sapere quante carte
//contiene, poichè si calcola il punteggio di un mazzetto
int calcola_punteggio(Mazzo *mazzo){
    int totale = 0;
    for (int i = 0; i < mazzo->n_carte; ++i) {
        totale += mazzo->carte[i].punteggio;
    }
}

int main(void) {
    Mazzo mazzo;
    inizializza(&mazzo);
    stampa_mazzo(mazzo);
    mescola_mazzo(&mazzo);
    stampa_mazzo(mazzo);
    printf("Test dai carta\n");
    stampa_carta(dai_carta(&mazzo));
    stampa_carta(dai_carta(&mazzo));
    printf("Test della mano\n");
    Mano giocatore, computer;
    giocatore.n_carte = 0;
    computer.n_carte = 0;
    Carta c = dai_carta(&mazzo);
    pesca_carta(&giocatore, c);
    pesca_carta(&giocatore, dai_carta(&mazzo));
    pesca_carta(&giocatore, dai_carta(&mazzo));
    stampa_mano(giocatore);
    tira_carta(&giocatore, 0);
    stampa_mano(giocatore);

    printf("\n%s %s %s %s", semi[0], semi[1], semi[2], semi[3]);
    return 0;
}