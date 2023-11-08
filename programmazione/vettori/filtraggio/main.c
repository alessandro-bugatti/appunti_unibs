#include <stdio.h>
#include <stdlib.h>

#define N 100

int main() {
    int v[N], f[N];
    int k = 3;
    int media, contatore;
    printf("Prima del filtraggio\n");
    for (int i = 0; i < N; ++i)
    {
        v[i] = rand()%1000;
        printf("%4d", v[i]);
    }
    printf("\nDopo il filtraggio\n");
    for (int i = 0; i < N; ++i) {
        media = 0;
        contatore = 0;
        for (int j = i - k; j <= i + k; ++j) {
            if (j >= 0 && j < N) {
                media += v[j];
                contatore++;
            }
        }
        media /= contatore;
        f[i] = media;
    }
    for (int i = 0; i < N; ++i)
    {
        printf("%4d", f[i]);
    }
    return 0;
}
