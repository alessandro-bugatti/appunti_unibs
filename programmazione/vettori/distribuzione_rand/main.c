#include <stdio.h>
#include <stdlib.h>

const int MAX = 100;

int lancio_dadi(int n_dadi) {
    int totale = 0;
    for (int i = 0; i < n_dadi; ++i) {
        totale += (rand() % 6 + 1);
    }
    return totale;
}

/**
 * Simula l'esperimento di lancio n_dadi a 6 facce
 * @param v contatori dell'uscita dei vari valori
 * @param n_dadi quanti dadi vengono lanciati ad ogni tiro
 * @param n_lanci numero di lanci dell'esperimento
 */
void esperimento_lancio_dadi(int v[], int n_dadi, int n_lanci) {
    //Azzero i contatori
    for (int i = n_dadi; i <= 6 * n_dadi; ++i) {
        v[i] = 0;
    }
    //Facciamo i nostri n_lanci
    for (int i = 0; i < n_lanci; ++i) {
        int numero_uscito;
        numero_uscito = lancio_dadi(n_dadi);
        v[numero_uscito]++;
    }
}

int main(void) {
    int contatori[MAX], n_dadi = 2, n_lanci = 10000000;

    esperimento_lancio_dadi(contatori, n_dadi, n_lanci);
    for (int i = n_dadi; i <= n_dadi * 6; ++i) {
        printf("%d: %d volte (%f \%)\n",
            i, contatori[i], contatori[i] * 100.0 / n_lanci);//(float)contatori[i] / n_lanci * 100)
    }
    return 0;
}