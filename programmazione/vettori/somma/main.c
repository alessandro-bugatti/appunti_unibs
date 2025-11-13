#include <stdio.h>

const int MAX = 100;

/**
 * Fa la somma dei primi n elementi di un vettore
 * @param v il vettore
 * @param n il numero di elementi
 * @return la somma dei primi n elementi
 */
int somma(int v[], int n) {
    int s = 0;
    for (int i = 0; i < n; ++i) {
        s += v[i];
    }
    return s;
}

int main(void) {
    int v[MAX];
    int n;
    printf("Quanti elementi vuoi inserire?");
    scanf("%d", &n);
    //input

    int s = somma(v, n);
    printf("%p\n", v);
    printf("%p\n", &v[0]);
    return 0;
}