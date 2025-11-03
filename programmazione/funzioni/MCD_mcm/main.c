#include <stdio.h>

int MCD(int a, int b) {
    int div;
    if (a < b) {
        div = a;
    }
    else {
        div = b;
    }
    for (int i = div; i > 0; --i) {
        if (a % i == 0 && b % i == 0) {
            return i;
        }
    }
}

int MCD_EUCLIDE(int a, int b) {
    while (b != 0) {
        int n = a % b;
        a = b;
        b = n;
    }
    return a;
}

int mcm(int a, int b) {
    int m = (a * b) / MCD(a, b);
    return m;
}

int main(void) {
    int a = 20, b = 25;
    int M = MCD(a, b);
    int m = mcm(a, b);
    printf("Il MCD tra %d e %d è %d\n", a, b, M);
    printf("Il MCD calcolato con Euclide tra %d e %d è %d\n",
        a, b, MCD_EUCLIDE(a, b));
    printf("Il mcm tra %d e %d è %d\n", a, b, m);

    return 0;
}