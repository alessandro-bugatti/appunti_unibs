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

int main(void) {
    Mazzo mazzo;
    inizializza(&mazzo);
    stampa_mazzo(mazzo);
    mescola_mazzo(&mazzo);
    stampa_mazzo(mazzo);
    printf("%s %s %s %s", semi[0], semi[1], semi[2], semi[3]);
    return 0;
}