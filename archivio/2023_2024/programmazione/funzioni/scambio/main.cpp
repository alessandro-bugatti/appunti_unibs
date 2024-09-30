#include <stdio.h>

void scambio(int *a, int *b){
    printf("Indirizzi di a e b in scambio: in %p si trova il valore %d e in %p si trova il valore %d\n", a, *a, b, *b);
    int temp = *a; //Prendi il valore contenuto all'indirizzo che si trova in a e copialo in temp
    *a = *b;
    *b = temp;
    printf("Indirizzi di a e b in scambio: in %p si trova il valore %d e in %p si trova il valore %d\n", a, *a, b, *b);

}

int main() {
    int a = 7, b = 5;
    printf("Indirizzi di a e b del main: %p %p\n", &a, &b);
    scambio(&a, &b);
    printf("%d %d\n", a, b);
    return 0;
}
