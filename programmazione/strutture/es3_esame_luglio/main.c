#include <stdio.h>
#include <string.h>

#define LUNGHEZZA 50

typedef struct
{
    char nome[LUNGHEZZA];
    int forza;
    int vita;
}Personaggio;

typedef struct
{
    Personaggio personaggi[5];
}Squadra;

void scontro(Squadra *s1, Squadra *s2) {
    Personaggio *p1, *p2;
    p1 = &s1->personaggi[0];
    for (int i = 1; i < 5; ++i) {
        if (s1->personaggi[i].forza > p1->forza) {
            p1 = &s1->personaggi[i];
        }
    }
    p2 = &s2->personaggi[0];
    for (int i = 1; i < 5; ++i) {
        if (s2->personaggi[i].forza > p2->forza) {
            p2 = &s2->personaggi[i];
        }
    }
    if (p1->forza > p2->forza) {
        p1->vita += 5;
        p2->vita = 0;
    }
    if (p1->forza < p2->forza) {
        p1->vita = 0;
        p2->vita += 5;
    }
}

void sostituisci_personaggio(Squadra *S, const Personaggio *P, char N[]) {
    //Verifico se esiste già un personaggio di nome uguale a quello di P
    for (int i = 0; i < 5; ++i) {
        Personaggio p = S->personaggi[i];
        if (strncmp(P->nome, p.nome, LUNGHEZZA) == 0) {
            return;
        }
    }
    //Verifico se esiste un personaggio che si chiama N
    int trovato = -1;
    for (int i = 0; i < 5; ++i) {
        Personaggio p = S->personaggi[i];
        if (strncmp(p.nome, N, LUNGHEZZA) == 0) {
            trovato = i;
        }
    }
    if (trovato == -1) {
        return;
    }
    S->personaggi[trovato] = *P;
}

int main(void) {
    printf("Hello, World!\n");
    return 0;
}