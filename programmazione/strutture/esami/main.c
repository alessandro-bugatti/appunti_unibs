#include <stdio.h>
#include <string.h>

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

//Ricerca studente e aggiunta di un esame

void aggiornaEsamiStudente(Registro *r, char matricola[], Esame e) {
    for (int i = 0; i < r->n_studenti; ++i) {
        if (strncmp(r->studenti[i].matricola,matricola,9) == 0) {
            aggiungiEsame(&r->studenti[i], e);
        }
    }
}

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

//Elenco di tutti gli studenti
void stampaRegistro(Registro r) {
    printf("Registro degli studenti\n");
    for (int i = 0; i < r.n_studenti; ++i) {
        stampa(r.studenti[i]);
    }
}

void stampaPassatiEsame(Registro r, char titolo) {
    //Scorre tutti gli studenti
    for (int i = 0; i < r.n_studenti; ++i) {
        int trovato = 0;
        for (int j = 0; j < r.studenti[i].n_esami; ++j) {
            if (strncmp(r.studenti[i].esami[j].nome,titolo, 199) == 0) {
                trovato = 1;
            }
        }
        if (trovato == 1) {
            printf("%s %s %s\n", r.studenti[i].matricola,
                r.studenti[i].cognome, r.studenti[i].nome);
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

void aggiungiStudente(Registro *r, Studente s) {
    r->studenti[r->n_studenti] = s;
    r->n_studenti++;
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
            Studente s;
            printf("Matricola: ");
            scanf("%s", s.matricola);
            printf("Cognome: ");
            scanf("%s", s.cognome);
            printf("Nome: ");
            scanf("%s", s.nome);
            s.n_esami = 0;
            aggiungiStudente(&registro, s);
        }
        else if (scelta == 2) {
            Esame e;
            char matricola[10];
            //Input del contenuto dell'esame
            printf("Inserisci il nome dell'esame: ");
            scanf("%s", e.nome);
            printf("Inserisci il voto: ");
            scanf("%d", &e.voto);
            printf("Inserisci la matricola: ");
            scanf("%s", matricola);
            aggiornaEsamiStudente(&registro, matricola, e);
        }
        else if (scelta == 3) {
            stampaRegistro(registro);
        }

        menu();
        scanf("%d", &scelta);

    }
    return 0;
}