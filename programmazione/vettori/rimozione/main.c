#include <stdio.h>

/**
 *
 * @param v vettore
 * @param n elementi del vettore
 * @param pos la posizione da cui voglio rimuovere un elemento
 * @return
 */
int rimozione(int v[], int n, int pos) {
    if (pos < 0 || pos >= n) {
        return n;
    }
    for (int i = pos; i < n - 1; ++i) {
        v[i] = v[i+1];
    }
    return n - 1;
}

int main(void) {
    int v[] = {14,25,33,24,15,62,57,58,97};
    int n = 9;
    n = rimozione(v, n, 4);

    for (int i = 0; i < n; ++i) {
        printf("%d ", v[i]);
    }

    for (int i = 0; i < 20; ++i) {
        n = rimozione(v, n, 0);
    }
    return 0;
}