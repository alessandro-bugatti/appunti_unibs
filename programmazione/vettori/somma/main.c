#include <stdio.h>
#include <stdlib.h>

#define N 100

/**
 *
 * @param v l'indirizzo iniziale del vettore
 * @param n numero di elementi che verranno elaborati
 * @return la somma dei primi n elementi del vettore v
 */
int somma (int v[], int n) {
    int s = 0;
    for (int i = 0; i < n; ++i) {
        s += v[i];
    }
    return s;
}

int main(void) {
    int n;
    int v[N];
    printf("Quanti elementi vuoi inserire? (la massimo 100): ");
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        v[i] = rand() % 10;
    }
    printf("La somma dei primi %d elementi del vettore è %d\n",
        n, somma(v, n));
    return 0;
}
