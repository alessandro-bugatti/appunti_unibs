#include <stdio.h>

int main(void) {
    int n, fattoriale = 1;
    printf("Inserisci un numero positivo: ");
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        fattoriale = fattoriale * (i + 1);
    }
    printf("Il fattoriale di %d è %d", n, fattoriale);
    return 0;
}