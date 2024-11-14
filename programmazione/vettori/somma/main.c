#include <stdio.h>
#include <stdlib.h>

#define N 100

int somma(int v[], int n) {
    int s = 0;
    for (int i = 0; i < n; ++i) {
        s += v[i];
    }
    return s;
}

int main(void) {
    int v[N];
    for (int i = 0; i < N; ++i) {
        v[i] = rand() % 100;
    }
    int s = somma(v, N); // somma(&v[0], N);
    printf("%d\n", s);
    return 0;
}
