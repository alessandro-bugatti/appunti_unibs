#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int segreto, primaS, secondaS, numero, primaN, secondaN,
        contatore = 0, indovinato = 0;
    segreto = rand()%90 + 10;
    primaS = segreto / 10;
    secondaS = segreto % 10;
    do {
        printf("Inserisci il numero:");
        scanf("%d", &numero);
        primaN = numero / 10;
        secondaN = numero % 10;
        if (segreto == numero ||
            primaN == secondaS && secondaN == primaS) {
            indovinato = 1;
        }
        else if(primaN == primaS || secondaN == secondaS
            || primaN == secondaS || secondaN == primaS) {
            printf("Una cifra è corretta e una è sbagliata\n");
        }
        else {
            printf("Entrambe sono sbagliate\n");
        }
        contatore++;
    }while(indovinato == 0);
    printf("Corretto, il numero scelto da computer era %d\n",
        segreto);
    printf("Hai usato %d tentativi per indovinare\n", contatore);
    return 0;
}
