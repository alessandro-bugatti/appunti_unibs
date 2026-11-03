#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Produce un numero casuale da 1 a n
int random_dado(int n) {
    return rand() % n + 1;
}

int lancio() {
    return random_dado(6) + random_dado(6);
}

/**
 *
 * @param n_dadi numero di dadi da lanciare
 * @param n_facce numero delle facce di ogni dado
 * @return la somma delle facce uscite
 */
int lancio_dadi(int n_dadi, int n_facce) {
    int somma = 0;
    for (int i = 0; i < n_dadi; ++i) {
        somma += random_dado(n_facce);
    }
    return somma;
}

int main(void) {
    int tiro, target, finta;
    srand(time(NULL));
    printf("Gioco del craps\n");
    printf("Premi 1 e invio per lanciare un dato: ");
    scanf("%d", &finta);
    tiro = lancio(); //tiro = lancio_dadi(2, 6);
    if (tiro == 7 || tiro == 11) {
        printf("Hai vinto!\n");
        return 0; //Si può fare solo se ci gioca una volta e non si vuole permettere una ripetizione del gioco
    }
    if (tiro == 2 || tiro == 3 || tiro == 12) {
        printf("Hai perso!");
        return 0;
    }
    target = tiro;
    printf("Il tuo target è %d\n", target);
    do {
        printf("Premi 1 e invio per lanciare un dato: ");
        scanf("%d", &finta);
        tiro = lancio();
        printf("Hai lanciato %d\n", tiro);
    }while (tiro != target && tiro != 7);
    if (tiro == target) {
        printf("Hai vinto!");
    } else {
        printf("Hai perso!");
    }
    return 0;
}