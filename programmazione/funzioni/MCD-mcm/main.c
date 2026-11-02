#include <stdio.h>

int minore(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}

int MCD(int a, int b) {
    /* Prima versione a forza bruta
    int div = minore(a, b);
    while (1) {
        if (a % div == 0 && b % div == 0) {
            return div;
        }
        div--;
    }*/
    int resto = a % b;
    while (resto != 0) {
        a = b;
        b = resto;
        resto = a % b;
    }
    return b;
}

int mcm(int a, int b) {
    return a * b / MCD (a, b);
}

int main(void) {
    printf("%d\n", MCD (28, 7));
    printf("%d\n", MCD (29, 7));
    printf("%d\n", MCD (35, 21));
    printf("%d\n", mcm (35, 21));

    return 0;
}
