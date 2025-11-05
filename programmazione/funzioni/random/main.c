#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Produce un valore intero casuale compreso nell'intervallo [a, b]
 * @param a Estremo inferiore dell'intervallo di valori(incluso)
 * @param b Estremo superiore dell'intervallo di valori(incluso)
 * @return Un numero pseudocasuale
 */
int casuale(int a, int b) {
    return rand()% (b - a + 1) + a;
}

int main(void) {
    //L'inizializzazione del generatore di numeri casuali
    //va fatta una sola volta all'inizio
    srand(time(NULL));
    int n = rand() % 6 + 1;
    printf("%d\n", n);
    for (int i = 0; i < 10; ++i) {
        printf("%d\n", casuale(18, 80));
    }
    return 0;
}
