#include <stdio.h>

#define N 100

int main() {
    int v[N], n;
    printf("Quanti numeri vuoi inserire? (massimo 100): ");
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        printf("Inserisci un dato: ");
        scanf("%d", &v[i]);
    }
    //Stampa gli elementi di valore pari
    for (int i = 0; i < n; i++) {
        if (v[i] % 2 == 0) {
            printf("%d\n", v[i]);
        }
    }
    //Stampa gli elementi di valore dispari
    for (int i = 0; i < n; i++) {
        if (v[i] % 2 != 0) {
            printf("%d\n", v[i]);
        }
    }


    return 0;
}
