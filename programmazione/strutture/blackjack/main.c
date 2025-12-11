#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Numero di carte presenti in un mazzo di carte francesi
#define CARTE_MAZZO 52
#define TESTO 30

char Seme[][TESTO] ={
    "Cuori",
    "Quadri",
    "Fiori",
    "Picche"
};

char Figure[][TESTO] = {
    "JACK",
    "QUEEN",
    "KING"
};

typedef struct
{
    char seme[TESTO];
    char numero; //il numero sulla carta, 11 - Jack, 12 - Queen, 13 - King
    char valore; //per Jack, Queen e King è sempre 10
} Carta;

typedef struct
{
    Carta carte[CARTE_MAZZO];
    int corrente; //indica quale carta deve essere data
} Mazzo;

typedef struct
{
    Carta carte[15];
    int quante; //indica quante carte ho in mano
} Mano;

void inizializza_mazzo(Mazzo *m) {
    for (int i = 0; i < 4; ++i)  { //Semi
        for (int j = 0; j < 13; ++j) { //Valori
            int posizione = i * 13 + j;
            m->carte[posizione].numero = j + 1;
            m->carte[posizione].valore = j + 1;
            strncpy(m->carte[posizione].seme, Seme[i], TESTO);
        }
    }
    //Ciclo per modificare i valori delle figure
    for (int i = 0; i < 4; ++i) {
        for (int j = 10; j < 13; ++j) {
            int posizione = i * 13 + j;
            m->carte[posizione].valore = 10;
        }
    }
    m->corrente = 0;
}

void mescola_mazzo(Mazzo *m) {
    for (int i = 0; i < CARTE_MAZZO; ++i) {
        int pos_casuale = rand() % (CARTE_MAZZO - i) + i;
        Carta temp = m->carte[i];
        m->carte[i] = m->carte[pos_casuale];
        m->carte[pos_casuale] = temp;
    }
}

void stampa_carta(const Carta *c) {
    if (c->numero <= 10) {
        printf("%d di %s ", c->numero, c->seme);
    } else {
        printf("%s di %s", Figure[c->numero - 11] , c->seme);
    }
}

void stampa_mazzo(const Mazzo *m) {
    for (int i = 0; i < CARTE_MAZZO; ++i) {
        stampa_carta(&m->carte[i]);
    }
}

void stampa_mano(const Mano *m) {
    for (int i = 0; i < m->quante; ++i) {
        stampa_carta(&m->carte[i]);
    }
    printf("\n");
}

Carta dai_carta(Mazzo *m) {
    Carta c = m->carte[m->corrente];
    m->corrente++;
    return c;
}

void pesca_carta(Mano *m, const Carta *c) {
    m->carte[m->quante] = *c;
    m->quante++;
}

int calcola_valore(const Mano *m) {
    int somma = 0;
    for (int i = 0; i < m->quante; ++i) {
        somma += m->carte[i].valore;
    }
    //Verifico se può essere vantaggioso trasformare il valore di un asso in 10
    for (int i = 0; i < m->quante; ++i) {
        if (m->carte[i].numero == 1 && somma + 9 <= 21) {
            somma += 9;
        }
    }
    return somma;
}

int main(void) {
    srand(time(NULL));
    Mazzo mazzo;
    inizializza_mazzo(&mazzo);

    //Verifica di correttezza della creazione del mazzo
    //stampa_mazzo(&mazzo);

    mescola_mazzo(&mazzo);

    //Verifica del mescolamento
    //printf("\n");
    //stampa_mazzo(&mazzo);

    Mano umano, computer;
    umano.quante = 0;
    computer.quante = 0;
    //Inizialmente il giocatore e il banco pescano una carta
    Carta c = dai_carta(&mazzo);
    pesca_carta(&umano, &c);
    c = dai_carta(&mazzo);
    pesca_carta(&computer, &c);
    printf("Mano del giocatore valore: %d\n", calcola_valore(&umano));
    stampa_mano(&umano);
    printf("\nMano del banco valore: %d\n", calcola_valore(&computer));
    stampa_mano(&computer);
    int scelta;
    printf("Vuoi continuare o fermarti? 1 - pesca, 2 - stai\n");
    scanf("%d", &scelta);
    while (scelta == 1 && calcola_valore(&umano) <= 21) {
        c = dai_carta(&mazzo);
        pesca_carta(&umano, &c);
        printf("Mano del giocatore valore: %d\n", calcola_valore(&umano));
        stampa_mano(&umano);
        if (calcola_valore(&umano) <= 21) {
            printf("Vuoi continuare o fermarti? 1 - pesca 2 - stai\n");
            scanf("%d", &scelta);
        }
    }
    if (calcola_valore(&umano) > 21) {
        printf("Hai perso perchè hai fatto %d", calcola_valore(&umano));
        return 0;
    }
    while (calcola_valore(&computer) < calcola_valore(&umano)) {
        c = dai_carta(&mazzo);
        pesca_carta(&computer, &c);
        stampa_mano(&computer);
    }
    if (calcola_valore(&computer) > 21) {
        printf("Ha vinto il giocatore");
    } else if (calcola_valore(&umano) > calcola_valore(&computer)) {
        printf("Ha vinto il giocatore");
    } else {
        printf("Ha vinto il banco");
    }
    return 0;
}