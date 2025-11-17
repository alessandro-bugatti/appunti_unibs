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


int massimo(int v[], int a, int b) {
    int m = v[0];
    for (int i = a; i <= b; ++i) {
        if (v[i] > m) {
            m = v[i];
        }
    }
    return m;
}

void istogramma(int v[], int a, int b, int max_asterischi) {
    int m = massimo(v, a, b);
    for (int i = a; i <= b; ++i) {
        printf("%4d %10d -> ", i, v[i]);
        for (int j = 0; j < v[i] * max_asterischi / m; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main(void) {
    int v[MAX];
    esperimento_lancio_dadi(v, 4, 10000000);
    istogramma(v, 4, 24, 30);
    return 0;
}