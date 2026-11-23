#include <stdio.h>
#include <string.h>

#define L_NOME 100
#define L_MATRICOLA 20
#define MAX_ESAMI 50
#define MAX_STUDENTI 1000

typedef struct
{
    int g;
    int m;
    int a;
} Data;

typedef struct
{
    char nome[L_NOME];
    Data data;
    int voto;
} Esame;

typedef struct
{
    char matricola[L_MATRICOLA];
    char nome[L_NOME];
    char cognome[L_NOME];
    Esame esami[MAX_ESAMI];
    int n_esami;
} Studente;

/**
 *
 * @param s vettore degli studenti
 * @param n numero di studenti già presenti
 */
void aggiungi_studente(Studente s[], int n) {
    printf("Inserisci la matricola: ");
    scanf("%s", s[n].matricola);
    printf("Inserisci il nome: ");
    scanf("%s", s[n].nome);
    printf("Inserisci il cognome: ");
    scanf("%s", s[n].cognome);
    s[n].n_esami = 0;
}

int aggiungi_esame(Studente s[], int n, Esame e, char matricola[]) {
    int pos = -1;
    for (int i = 0; i < n; ++i) {
        if (strncmp(s[i].matricola, matricola, L_MATRICOLA) == 0) {
            pos = i;
        }
    }
    if (pos == -1) {
        return -1;
    }
    s[pos].esami[s[pos].n_esami] = e;
    s[pos].n_esami++;
}

int main(void) {
    Studente studenti[MAX_STUDENTI];
    int n_studenti = 0;
    aggiungi_studente(studenti, n_studenti);
    n_studenti++;
    aggiungi_studente(studenti, n_studenti);
    n_studenti++;
    return 0;
}
