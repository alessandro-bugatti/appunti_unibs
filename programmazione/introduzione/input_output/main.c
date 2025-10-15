#include <stdio.h>

int main(void) {
    int a;
    float b;
    double c;
    //Input viene fatto utilizzando la funzione scanf, indicando come primo parametro una stringa contenente uno specificatore di formato e come secondo la variabile in cui deve essere letto il valore. La variabile deve essere preceduta dal simbolo &

    //Lo specificatore per gli interi è %d
    printf("Inserisci un numero intero: ");
    scanf("%d", &a);

    //Lo specificatore per gli float è %d
    printf("Inserisci un numero float: ");
    scanf("%f", &b);

    //Lo specificatore per gli double è %d
    printf("Inserisci un numero double: ");
    scanf("%lf", &c);

    //Per la scrittura si utilizza la funzione printf, utilizzando sempre degli specificatori di formato opportuni. Attenzione, il parametro nella printf non ha bisogno del simbolo &

    //Nel caso di variabili interi lo specificatore è %d
    printf("La variabile intera letta è %d\n", a);
    printf("La variabile float letta è %f\n", b);
    printf("La variabile double letta è %lf\n", c);
    /*
    Questo è un commento
    multilinea

     */
    return 0;
}