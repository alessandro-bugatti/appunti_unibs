#include <stdio.h>

int main(void) {
    int N, num;
    int max = 0, min = 0;
    printf("Inserisci qualsiasi quantità dei numeri: ");
    scanf("%d", &N);
    printf("Inserisci ul numero: ");
    scanf("%d", &num);
    max = min = num;
    for ( int i=0; i < N-1; ++i) {
        printf("Inserisci ul numero: ");
        scanf("%d", &num);
        if ( num > max ) {
            max = num;
        }
        if ( num < min) {
            min = num;
        }
    }
    printf("Il numero max è %d e il min è %d", max, min);
    return 0;
}
