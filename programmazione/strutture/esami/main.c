#include <stdio.h>
#include <string.h>

#define L_NOME 100
#define L_MATRICOLA 20
#define MAX_ESAMI 50
#define MAX_STUDENTI 100

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

int ricerca_studente(Studente s[], int n, char matricola[]) {
    int pos = -1;
    for (int i = 0; i < n; ++i) {
        if (strncmp(s[i].matricola, matricola, L_MATRICOLA) == 0) {
            pos = i;
        }
    }
    if (pos == -1) {
        return -1;
    }
    return pos;
}

int aggiungi_esame(Studente s[], int n, Esame e, char matricola[]) {
    int pos = ricerca_studente(s, n, matricola);
    if (pos == -1) {
        return -1;
    }
    s[pos].esami[s[pos].n_esami] = e;
    s[pos].n_esami++;
    return 1;
}

void stampa_data(Data d) {
    printf("%d/%d/%d\n", d.g, d.m, d.a);
}

void stampa_esame(Esame e) {
    printf("Nome: %s\n", e.nome);
    printf("Data: ");
    stampa_data(e.data);
    printf("Voto %d\n", e.voto);
}

void stampa_studente(Studente s) {
    printf("Matricola: %s\nNome: %s\nCognome: %s\n",
        s.matricola, s.nome, s.cognome);
    if (s.n_esami == 0) {
        printf("Lo studente non ha ancora passato nessun esame.\n");
    }else {
        for (int i = 0; i < s.n_esami; ++i) {
            stampa_esame(s.esami[i]);
        }
    }
}

int esami_passati(Studente s[], int n, char matricola[]) {
    int pos = ricerca_studente(s, n, matricola);
    if (pos == -1) {
        return -1;
    }
    stampa_studente(s[pos]);
}

int passato_esame(Studente s, char nome_esame[]) {
    for (int i = 0; i < s.n_esami; ++i) {
        if (strncmp(s.esami[i].nome, nome_esame, L_NOME) == 0) {
            return 1;
        }
    }
    return 0;
}

void studenti_passato_esame(Studente s[], int n, char nome_esame[]) {
    for (int i = 0; i < n; ++i) {
        if (passato_esame(s[i], nome_esame) == 1) {
            printf("%s : %s %s\n", s[i].matricola,
                s[i].nome, s[i].cognome);
        }
    }
}

void menu() {
    printf("1 - Aggiungi uno studente\n");
    printf("2 - Aggiungi un esame\n");
    printf("3 - Stampa gli esami di uno studente\n");
    printf("4 - Stampa gli studenti che hanno passato un certo esame\n");
    printf("5 - Stampa tutti gli studenti\n");
    printf("0 - Esci\n");

}

int main(void) {
    Studente studenti[MAX_STUDENTI] =
    {
        { "S123456", "Marco",  "Rossi",   {0}, 0 },
        { "S234567", "Giulia", "Bianchi", {0}, 0 },
        { "S345678", "Luca",   "Verdi",   {0}, 0 }
    };
    int n_studenti = 3;
    // stampa_studente(studenti[1]);
    // aggiungi_studente(studenti, n_studenti);
    // n_studenti++;
    // aggiungi_studente(studenti, n_studenti);
    // n_studenti++;
    menu();
    int scelta;
    printf("Inserisci la tua scelta: ");
    scanf("%d", &scelta);
    while (scelta != 0) {
        switch (scelta) {
        case 1:
            aggiungi_studente(studenti, n_studenti);
            n_studenti++;
            break;
        case 2:
            Esame e;
            char matricola[L_MATRICOLA];
            printf("Inserisci la matricola dello studente: ");
            scanf("%s", matricola);
            printf("Inserisci il nome dell'esame: ");
            scanf("%s", e.nome);
            printf("Inserisci la data (giorno mese e anno)");
            scanf("%d", &e.data.g);
            scanf("%d", &e.data.m);
            scanf("%d", &e.data.a);
            printf("Inserisci il voto: ");
            scanf("%d", &e.voto);
            int risultato = aggiungi_esame(studenti, n_studenti, e, matricola);
            if (risultato == -1) {
                printf("Lo studente non è stato trovato.\n");
            } else {
                printf("Esame aggiunto correttamente.\n");
            }
            break;
        case 5:
            for (int i = 0; i < n_studenti; ++i) {
                stampa_studente(studenti[i]);
            }
            break;
        default:
            printf("Scelta non valida");
        }

        menu();
        printf("Inserisci la tua scelta: ");
        scanf("%d", &scelta);
    }

    return 0;
}
