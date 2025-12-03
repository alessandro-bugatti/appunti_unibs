#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTI 100

#define LUNGHEZZA  50

#define MAX_ESAMI 30

typedef struct
{
    int g;
    int m;
    int a;
} Data;

typedef struct
{
    char materia[LUNGHEZZA];
    Data data;
    int voto;
} Esame;

typedef struct
{
    char matricola[LUNGHEZZA];
    char nome[LUNGHEZZA];
    char cognome[LUNGHEZZA];
    Esame esami[MAX_ESAMI];
    int n_fatti;
} Studente;

typedef struct
{
    Studente studenti[MAX_STUDENTI];
    int n_studenti;
} Registro;

void menu()
{
    printf("\n 1) Stampa il registro");
    printf("\n 2) Aggiungi uno studente");
    printf("\n 3) Aggiungi un esame a uno studente");
    printf("\n 4) Stampa esami di uno studente");
    printf("\n 5) Studenti che hanno effettuato un esame");
    printf("\n 6) Stampa media voti di uno studente");
    printf("\n 0) Esci");
}

void stampa_studente(const Studente *studente) {
    printf("%s) %s %s. Esami dati: %d\n", studente->matricola,
        studente->cognome, studente->nome, studente->n_fatti);
}

void stampa_registro(const Registro *registro) {
    for (int i = 0; i < registro->n_studenti; ++i) {
        stampa_studente(&registro->studenti[i]);
    }
}

//Versione aggiungi_studente che verifica che la matricola non sia già presente
int matricola_ripetuta(const Registro *registro, char matricola[]) {
    for (int i = 0; i < registro->n_studenti; ++i) {
        if (strncmp(matricola, registro->studenti[i].matricola ,LUNGHEZZA) == 0)
            return 1;
    }
    return 0;
}

int aggiungi_studente(Registro *registro, const Studente *studente) {
    if (matricola_ripetuta(registro, studente->matricola) == 1) {
        return -1;
    }
    registro->studenti[registro->n_studenti] = *studente;
    registro->n_studenti++;
    return registro->n_studenti;
}

void aggiungi_esame(Studente *studente, const Esame *e) {
    studente->esami[studente->n_fatti] = *e;
    studente->n_fatti++;
}

int cerca_studente(const Registro *registro, char matricola[]) {
    for (int i = 0; i < registro->n_studenti; ++i) {
        if (strncmp(registro->studenti[i].matricola, matricola, LUNGHEZZA) == 0) {
            return i;
        }
    }
    return -1;
}

void stampa_esami(const Registro *registro, char matricola[]) {
    int posizione = cerca_studente(registro, matricola);
    if (posizione == -1) {
        printf("Studente non presente");
    }else {
        Studente *s = &registro->studenti[posizione];
        printf("Lo studente ha fatto %d esami.\n", s->n_fatti);
        for (int i = 0; i < s->n_fatti; ++i) {
            printf("%s in data %d/%d/%d con voto %d\n",
                s->esami[i].materia, s->esami[i].data.g,
                s->esami[i].data.m, s->esami[i].data.a,
                s->esami[i].voto);
        }
    }
}

void stampa_studenti_esame(const Registro *registro, char esame[]) {
    for (int i = 0; i < registro->n_studenti; ++i) {
        //Cerco se lo studente i-esimo ha dato l'esame indicato
        Studente *s = &registro->studenti[i];
        for (int j = 0; j < s->n_fatti; ++j) {
            if (strncmp(s->esami[j].materia, esame, LUNGHEZZA) == 0) {
                printf("%s %s\n", s->nome, s->cognome);
                break;
            }
        }
    }
}

float media_voti(const Studente *studente) {
    float somma = 0;
    for (int i = 0; i < studente->n_fatti; ++i) {
        somma += studente->esami[i].voto;
    }
    return somma / studente->n_fatti;
}

int main()
{
    int scelta;
    Registro registro;
    Studente temp = {
        "12345",
        "Arturo",
        "Rastolfi",
        {
            {
                "Algebra",
                {
                    12,12,2017
                },
                28
            },
            {
                "Informatica",
                {
                    04,12,2017
                },
                30
            }
        },
        2
    };
    registro.studenti[0] = temp;
    Studente temp2 = {
        "12346",
        "Ada",
        "Prestini",
        {
            {
                "Analisi",
                {
                    21,12,2017
                },
                30
            },
        },
        1
    };
    registro.studenti[1] = temp2;
    registro.n_studenti = 2;

    menu();
    printf("\nScegli cosa fare: ");
    scanf("%d", &scelta);
    while (scelta != 0){
        //Stampa il registro
        if (scelta == 1) {
            stampa_registro(&registro);
        }
        if (scelta == 2) {
            Studente s;
            printf("Inserisci la matricola: ");
            scanf("%s", s.matricola);
            printf("Inserisci il nome: ");
            scanf("%s", s.nome);
            printf("Inserisci il cognome: ");
            scanf("%s", s.cognome);
            s.n_fatti = 0;
            if (aggiungi_studente(&registro, &s) == -1) {
                printf("Matricola ripetuta, inserimento fallito\n");
            }
            else {
                printf("Inserimento riuscito\n");
            }
        }
        if (scelta == 3) {
            char matricola[LUNGHEZZA];
            Esame e;
            int posizione;
            printf("Inserisci la matricola dello studente: ");
            scanf("%s", matricola);
            posizione = cerca_studente(&registro, matricola);
            if (posizione == -1) {
                printf("Studente non presente");
            }
            else {
                printf("Inserisci il nome:");
                scanf("%s", e.materia);
                printf("Inserisci giorno, mese e anno: ");
                scanf("%d", &e.data.g);
                scanf("%d", &e.data.m);
                scanf("%d", &e.data.a);
                printf("Inserisci il voto: ");
                scanf("%d", &e.voto);
                aggiungi_esame(&registro.studenti[posizione], &e);
            }
        }
        if (scelta == 4) {
            char matricola[LUNGHEZZA];
            printf("Inserisci la matricola dello studente: ");
            scanf("%s", matricola);
            stampa_esami(&registro, matricola);
        }
        if (scelta == 5) {
            char esame[LUNGHEZZA];
            printf("Inserisci il nome dell'esame: ");
            scanf("%s", esame);
            stampa_studenti_esame(&registro, esame);
        }
        if (scelta == 6) {
            char matricola[LUNGHEZZA];
            printf("Inserisci la matricola: ");
            scanf("%s", matricola);
            int posizione = cerca_studente(&registro, matricola);
            if (posizione == -1) {
                printf("Studente non presente\n");
            }else {
                float media = media_voti(&registro.studenti[posizione]);
                printf("La media voti dello studente è %f", media);
            }
        }
        menu();
        printf("\nScegli cosa fare: ");
        scanf("%d", &scelta);
    }
    return 0;
}