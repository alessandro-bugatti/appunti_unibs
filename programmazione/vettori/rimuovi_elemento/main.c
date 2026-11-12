#include <stdio.h>

#define N 100

/**
 *
 * @param v
 * @param n
 * @param indice
 * @return ritorna n -1 se l'elemento è stato rimosso, -1 se l'indice non è valido
 */
int rimuovi_elemento(int v[], int n, int indice) {
    if (indice < 0 || indice >= n) {
        return -1;
    }
    for (int i = indice; i < n - 1; ++i) {
        v[i] = v[i+1];
    }
    return n - 1;
}

int main(void) {
    int v[N];
    int n = 10;
    for (int i = 0; i < n; ++i) {
        v[i] = i + 1;
    }
    n = rimuovi_elemento(v, n, 4);
    n = rimuovi_elemento(v, n, 7);
    for (int i = 0; i < n; ++i) {
        printf("%d  ", v[i]);
    }
    return 0;
}
