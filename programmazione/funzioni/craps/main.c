#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int MAX = 10000000;

/*

Il gioco del craps è un gioco che si gioca con due dadi seguendo le seguenti regole:

se al primo tiro il giocatore fa 7 o 11 ha vinto
se al primo tiro il giocatore fa 2, 3 o 12 ha perso
qualsiasi altro punteggio viene definito "target" e si continua a tirare finchè
il giocatore realizza nuovamente il target, in quel caso vince
il giocatore realizza un 7, in quel caso perde

Si scrivano due funzioni, la prima che simula il lancio di un dado e la seconda che simula il lancio di due dadi.
*/

/**
 * Produce un valore intero casuale compreso nell'intervallo [a, b]
 * @param a Estremo inferiore dell'intervallo di valori(incluso)
 * @param b Estremo superiore dell'intervallo di valori(incluso)
 * @return Un numero pseudocasuale
 */
int casuale(int a, int b) {
    return rand()% (b - a + 1) + a;
}

int un_dado(void) {
    return casuale(1, 6);
}

int due_dadi(void) {
    return un_dado() + un_dado();
}

//Non è realistica
void pausa(void) {
    double s = 0;
    for (int i = 0; i < MAX; ++i) {
        s += sqrt(rand());
    }
}

void pausa_t(int p) {
    time_t attuale = time(NULL);
    while (time(NULL) - attuale < p);
}

int main(void) {
    srand(time(NULL));
    int target;
    printf("Gioco del craps\n");
    target = due_dadi();
    printf("Al primo tiro è uscito %d\n", target);
    if (target == 7 || target == 11) {
        printf("Ha vinto il giocatore.\n");
    }
    else if (target == 2 || target == 3 || target == 12) {
        printf("Ha vinto il banco\n");
    }else {
        pausa_t(3);
        int tiro = due_dadi();
        printf("Stavolta hai lanciato %d\n", tiro);
        while (tiro != target && tiro != 7) {
            pausa_t(3);
            tiro = due_dadi();
            printf("Stavolta hai lanciato %d\n", tiro);
        }
        if (tiro == target) {
            printf("Ha vinto il giocatore\n");
        }
        else {
            printf("Ha vinto il banco\n");
        }
    }
    return 0;
}