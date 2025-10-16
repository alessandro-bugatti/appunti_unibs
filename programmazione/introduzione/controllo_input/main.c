#include <ctype.h>
#include <stdio.h>

int main(void) {
    double n;
    do {
        printf("Inserisci un numero maggiore o uguale a 1: ");
        scanf("%lf", &n);
    }while (n < 1);
    printf("Il numero inserito è %lf\n", n);
    return 0;
}