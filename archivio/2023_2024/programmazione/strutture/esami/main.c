#include <stdio.h>
#include <string.h>

typedef struct {
    int g;
    int m;
    int a;
}Data;

typedef struct {
    char nome[100];
    Data data_registrazione;
    int voto;
}Esame;

typedef struct {
    char nome[50];
    char cognome[50];
    char matricola[20];
    Esame esami[50];
    int n_esami;
} Studente;

typedef struct {
    Studente studenti[100];
    int n_studenti;
} Registro;

void aggiungi_studente(Registro *r, Studente s){
    r->studenti[r->n_studenti] = s;
    r->n_studenti++;
}

void stampa_studenti(Registro r){
    printf("Numero di studenti: %d\n", r.n_studenti);
    for (int i = 0; i < r.n_studenti; ++i) {
        printf("%s : %s %s\n", r.studenti[i].matricola,
               r.studenti[i].cognome, r.studenti[i].nome);
        printf("Numero di esami passati: %d\n",
               r.studenti[i].n_esami);
    }
}


int aggiungi_voto(Registro *r, Esame e, char matricola[]){
    for (int i = 0; i < r->n_studenti; ++i) {
        if (strncmp(r->studenti[i].matricola, matricola,20) == 0){
            int numero_esami = r->studenti[i].n_esami;
            r->studenti[i].esami[numero_esami] = e;
            r->studenti[i].n_esami++;
            return 0;
        }
    }
    return -1;
}

void stampa_esami(Registro r, char matricola[]) {
    for (int i = 0; i < r.n_studenti; ++i) {
        if (strncmp(r.studenti[i].matricola, matricola, 20) == 0) {
            int numero_esami = r.studenti[i].n_esami;
            for (int j = 0; j < numero_esami; ++j) {
                Esame e = r.studenti[i].esami[j];
                Data d = e.data_registrazione;
                printf("%s voto: %d registrato in data %d-%d-%d\n", e.nome, e.voto,
                       d.g, d.m, d.a);
            }
        }
    }
}

void stampa_passati(Registro r, char nome_esame[]){
    int trovati = 0;
    for (int i = 0; i < r.n_studenti; ++i) {
        //Numero degli esami dello studente i-esimo
        int numero_esami = r.studenti[i].n_esami;
        for (int j = 0; j < numero_esami; ++j) {
            if (strncmp(r.studenti[i].esami[j].nome,
                        nome_esame, 50) == 0){
                printf("%s %s\n", r.studenti[i].cognome,
                       r.studenti[i].nome);
                trovati++;
            }
        }
    }
    if (trovati == 0){
        printf("Nessuno studente ha passato %s\n", nome_esame);
    }
}

void menu(){
    printf("Gestione esami\n");
    printf("1) Inserisci un nuovo studente.\n");
    printf("2) Inserisci un voto a uno studente.\n");
    printf("3) Stampa gli esami di un certo studente.\n");
    printf("4) Stampa degli studenti che hanno passato un certo esame.\n");
    printf("5) Stampa l'elenco di tutti gli studenti\n");
    printf("0) Esci.\n");
}

int main() {
    Registro registro;
    registro.n_studenti = 0;
    int scelta;
    menu();
    scanf("%d", &scelta);
    while(scelta != 0){
        switch (scelta) {
            case 1:
                {
                    Studente studente;
                    printf("Inserisci il nome: ");
                    scanf("%s", studente.nome);
                    printf("Inserisci il cognome: ");
                    scanf("%s", studente.cognome);
                    printf("Inserisci la matricola: ");
                    scanf("%s", studente.matricola);
                    studente.n_esami = 0;
                    aggiungi_studente(&registro, studente);
                }
                break;
            case 2:
                {
                    Esame esame;
                    char matricola[20];
                    printf("Inserisci il nome dell'esame: ");
                    scanf("%s", esame.nome);
                    printf("Inserisci il voto: ");
                    scanf("%d", &esame.voto);
                    printf("Inserisci la data\n");
                    printf("Inserisci il giorno: ");
                    scanf("%d", &esame.data_registrazione.g);
                    printf("Inserisci il mese: ");
                    scanf("%d", &esame.data_registrazione.m);
                    printf("Inserisci l'anno: ");
                    scanf("%d", &esame.data_registrazione.a);
                    printf("Inserisci la matricola: ");
                    scanf("%s", matricola);
                    int esito = aggiungi_voto(&registro, esame, matricola);
                    if (esito == -1){
                        printf("Inserimento fallito\n");
                    }
                }
                break;
            case 3:
            {
                char matricola[50];
                printf("Inserisci la matricola dello studente: ");
                scanf("%s", matricola);
                stampa_esami(registro, matricola);
            }
                break;
            case 4:
                {
                    char nome[50];
                    printf("Inserisci il nome dell'esame: ");
                    scanf("%s", nome);
                    stampa_passati(registro, nome);
                }
                break;
            case 5:
                stampa_studenti(registro);
                break;
            default:
                printf("Valore selezionato non corretto\n");
        }
        menu();
        scanf("%d", &scelta);
    }


    return 0;
}
