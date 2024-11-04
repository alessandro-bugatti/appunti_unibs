#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Funzione per la produzione di un numero casuale compreso
//nell'intervallo chiuso [a, b]

int random(int a, int b) {
    int r;
    r = rand() % (b - a + 1) + a;
    return r;
}

int main(void) {
    srand(time(NULL));
    int a = 16, b = 20;
    printf("Numero casuale: %d", random(a, b));
    return 0;
}
