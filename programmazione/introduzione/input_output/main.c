#include <stdio.h>

/*
  Primo esempio di programma con I/O
 */
int main(void) {
    int a, b;
    float c; //questa è una variabile floating point
    printf("Inserisci un numero intero: ");
    scanf("%d", &a);
    printf("Hai inserito il numero %d\n", a);
    b = a * 2;
    printf("Il doppio di %d è %d\n", a, b);
    printf("Inserisci un numero reale: ");
    scanf("%f", &c);
    printf("Il triplo di %f è %.2f\n", c, 3 * c);
    return 0;
}
