#include <stdio.h>
#include <stdlib.h>

int primo(int n) {
    for (int i = 2; i < n/2; ++i) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int quanti_primi(int n) {
    int n_primi = 0;
    for (int i = 2; i <= n; ++i) {
        if (primo(i)) {
            n_primi++;
        }
    }
    return n_primi;
}

int main(void) {
    int n;
    printf("Inserisci il numero limite per vedere quanti primi ci sono da 2 a quel numero: ");
    scanf("%d", &n);
    printf("Ci sono %d numeri primi minori o uguali a %d\n",
        quanti_primi(n), n);
    int a, b;
    printf("Inserisci un intervallo e ti dirò quanti sono i numeri primi compresi in quell'intervallo:");
    scanf("%d", &a);
    scanf("%d", &b);
    printf("I numeri primi compresi tra %d e %d sono %d",
        a, b, quanti_primi(b) - quanti_primi(a));
    return 0;
}
