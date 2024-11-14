#include <stdio.h>

#define N 10

int rimuovi(int v[], int n, int pos) {
    if (pos < 0 || pos >= n) {
        return -1;
    }
    for (int i = pos; i < n - 1; ++i) {
        v[i] = v[i+1];
    }
    return n - 1;

}

void stampa(int v[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main(void)
{
    int v[N];
    int n_elementi = N;
    for (int i = 0; i < 10; ++i) {
        v[i] = i + 1;
    }
    stampa(v, n_elementi);
    n_elementi = rimuovi(v, n_elementi, 3);
    stampa(v, n_elementi);
    return 0;
}
