#include <stdio.h>

#define N 10000

int main(void) {
    int crivello[N];
    for (int i = 2; i < N; ++i) {
        crivello[i] = 1;
    }
    for(int i = 2; i < N / 2; ++i) {
        int posizione = i;
        if (crivello[posizione] == 1) {
            for (int j = posizione + i; j < N; j = j + i) {
                crivello[j] = 0;
            }
        }
    }
    printf("Lista dei numeri primi minori di %d\n", N);
    for(int i = 2; i < N; ++i) {
        if(crivello[i] == 1) {
            printf("%d\n", i);
        }
    }
    return 0;
}
