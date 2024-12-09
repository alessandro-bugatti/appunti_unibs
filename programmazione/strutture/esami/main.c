#include <stdio.h>

typedef struct {
    int g;
    int m;
    int a;
}Data;

#define MAX 200
#define MAX_STUDENTI 10

typedef struct {
    char nome[MAX];
    int voto;
    Data data;
}Esame;

typedef struct {
    char matricola[10];
    char nome[50];
    char cognome[50];
    Esame esami[50];
    int n_esami;
}Studente;

typedef struct {
    Studente studenti[MAX_STUDENTI];
    int n_studenti;
} Registro;

//Aggiungi esame
void aggiungiEsame(Studente *s, Esame e) {
    s->esami[s->n_esami] = e;
    s->n_esami++;
}

//Ricerca studente

//Aggiunta di un nuovo studente

//Elenco degli studenti che hanno passato un certo esame

void stampa(Studente s) {
    printf("%s %s matricola: %s\n",
        s.cognome, s.nome, s.matricola);
    if (s.n_esami == 0) {
        printf("Nessun esame presente\n");
    }
    else {
        printf("Numero esami sostenuti: %d\n",
            s.n_esami);
        for (int i = 0; i < s.n_esami; ++i) {
            printf("%d-%d-%d: %s voto: %d\n",
                s.esami[i].data.g,
                s.esami[i].data.m,
                s.esami[i].data.a,
                s.esami[i].nome,
                s.esami[i].voto
                );
        }
    }
}

void menu() {
    printf("1 - Inserisci un nuovo studente\n");
    printf("2 - Inserisci un nuovo esame\n");
    printf("3 - Stampa registro\n");
    printf("4 - Stampa dati studente\n");
    printf("5 - Stampa passaggio esame\n");
    printf("0 - Esci\n");
    printf("Scegli l'opzione: \n");

}

int main(void) {
    Registro registro = {
        {
            {
                "123456",
                "Rossi",
                "Adele",
                {},
                0
            },
            {
                "123457",
                "Bianchi",
                "Ottavio",
                {},
                0
        }
        },
        2
    };

    int scelta;
    menu();
    scanf("%d", &scelta);
    while (scelta != 0) {
        if (scelta == 1) {

        }

        menu();
        scanf("%d", &scelta);

    }
    return 0;
}