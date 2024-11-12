#include <stdio.h>

void scambio(int *a, int *b) {
    //Una variabile o parametro dichiarato come int *a implica che:
    // a è un puntatore a intero, quindi contiene un indirizzo
    // *a è un intero, contiene il valore della variabile il cui indirizzo è contenuto in a
    printf("Ingresso nella funzione scambio\n");
    printf("valori passati *a = %d e *b = %d\n", *a, *b);
    printf("Valori contenuti in a = %p b = %p\n", a, b);
    int temp = *a;
    *a = *b;
    *b = temp;
    printf("valori passati *a = %d e *b = %d\n", *a, *b);
    printf("Valori contenuti in a = %p b = %p\n", a, b);
    printf("Uscita dalla funzione");

}

int main(void) {
    int a, b;
    a = 5;
    b = 7;
    printf("I valori contenuti in a = %d e b = %d\n", a, b);
    printf("Gli indirizzi di a = %p e b = %p\n", &a, &b);
    scambio(&a, &b);
    printf("I valori contenuti in a = %d e b = %d\n", a, b);
    printf("Gli indirizzi di a = %p e b = %p\n", &a, &b);


    return 0;
}
