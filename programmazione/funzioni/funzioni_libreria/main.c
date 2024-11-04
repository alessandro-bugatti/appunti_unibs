#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int a = -2;
    int b = abs(a);
    printf("Il valore assoluto di %d è %d\n", a, b);
    double c = 65;
    double d = sqrt(c);
    printf("La radice di %lf è %lf\n", c, d);
    //Funzioni per la generazione di numeri pseudocasuali
    srand(time(NULL));
    int r = rand();
    printf("IL numero casuale prodotto è %d\n", r);
    for (int i = 0; i < 10; ++i) {
        //srand(time(NULL)); ASSOLUTAMENTE NO
        r = rand() % 6 + 1;
        printf("%d\n", r);
    }

    return 0;
}
