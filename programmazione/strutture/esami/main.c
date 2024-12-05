#include <stdio.h>

typedef struct {
    int g;
    int m;
    int a;
}Data;

#define MAX 200

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

void aggiungiEsame(Studente *s, Esame e) {
    s->esami[s->n_esami] = e;
    s->n_esami++;
}

void stampa(Studente s) {
    printf("%s %s matricola: %s\n",
        s.cognome, s.nome, s.matricola);
    if (s.n_esami == 0) {
        printf("Nessn esame presente\n");
    }
    else {
        printf("NUmero esami sostenuti: %d\n",
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

int main(void) {

    return 0;
}