#include <stdio.h>

#define DIM 3
#define RIGHE 10

int massimo (int m[][DIM], int r)
{
    int max=m[0][0];
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < DIM; ++j) {
            if (m[i][j]>max)
            {
                max=m[i][j];
            }
        }
    }
    return max;
}


int main() {
    int m[RIGHE][DIM];
    for (int i = 0; i < RIGHE; ++i) {
        for (int j = 0; j < DIM; ++j) {
            m[i][j]=i*DIM+j;
        }
    }
    int max=massimo(m,RIGHE);
    printf ("Massimo: %d", max);
    return 0;
}
