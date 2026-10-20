#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int N;
    printf("Inserisci un numero: ");
    scanf("%d", &N);
    //Stampa il valore assoluto di N
    printf("Valore assoluto del numero: %d\n", abs(N));
    //Modifica N e la rende sicuramente positiva
    N = abs(N);
    printf("%d\n", N);
    //Elevamento a potenza
    printf("12 elevato alla 3.45 è : %lf", pow(12, 3.45));
    return 0;
}
