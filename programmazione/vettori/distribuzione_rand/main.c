#include <stdio.h>
#include <stdlib.h>

#define N 100

//Produce un numero casuale da 1 a n
int random_dado(int n) {
    return rand() % n + 1;
}
/**
 *
 * @param n_dadi numero di dadi da sei
 * @param v il vettore che misura il numero di volte che escono i vari lanci
 * @param tentativi il numero totale di lanci
 */
void distribuzione_rand(int n_dadi, int v[], int tentativi) {
    for (int i = 0; i < tentativi; ++i) {
        int somma = 0;
        for (int j = 0; j < n_dadi; ++j) {
            somma += random_dado(6);
        }
        v[somma]++;
    }
}

void inizializza(int v[], int n) {
    for (int i = 0; i < n; ++i) {
        v[i] = 0;
    }
}

void stampa(int v[], int a, int b) {
    for (int i = a; i <= b; ++i) {
       printf("%d - >%d volte\n", i, v[i]);
    }
}

int main(void) {
    int v[N], n_dadi = 1;
    inizializza(v, N);
    distribuzione_rand(n_dadi, v, 10000000);
    stampa(v, n_dadi, n_dadi * 6);
    return 0;
}
