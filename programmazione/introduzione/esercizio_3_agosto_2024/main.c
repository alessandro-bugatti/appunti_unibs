#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int corretto, contatore = 0, temp;
    int n;
    do {
        n = rand() % 1000 + 1;
        corretto = 0;
        temp = n;
        while (n > 0) {
            int cifra = n % 10;
            if (cifra % 2 == 0) {
                corretto = 1;
            }
            n = n / 10;
        }
        if (corretto == 1) {
            printf("%d ", temp);
            contatore++;
        }
    }while(corretto == 1);
    printf("Sono stati generati %d numeri corretti consecutivi\n", contatore);
    printf("Il numero non corretto era %d\n", temp);
    return 0;
}
