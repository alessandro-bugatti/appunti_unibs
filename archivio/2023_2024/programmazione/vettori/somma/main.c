#include <stdio.h>
#include <stdlib.h>

#define N 10

int somma(int v[], int n){
    int s = 0;
    for (int i = 0; i < n; ++i) {
        s += v[i];
    }
    return s;
}

int somma2(int *v, int n){
    int s = 0;
    for (int i = 0; i < n; ++i) {
        s += v[i];
    }
    return s;
}

int main() {
    int v[N];
    int *v2;
    v2 = v;
    for (int i = 0; i < N; ++i) {
        v[i] = rand() % 100;
    }
    printf("%d\n", somma(v, N));
    return 0;
}
