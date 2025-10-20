#include <stdio.h>

int main(void) {
    float b, h, Vmax = 0, V, lato_max = 0, lato = 1;
    printf("Inserisci la base della lastra: ");
    scanf("%f", &b);
    printf("Inserisci l'altezza della lastra: ");
    scanf("%f", &h);
    //Procede a simulare tutte le pieghe possibili
    //a intervalli di un centimetro
    while (h - 2 * lato > 0) {
        V = (b - 2*lato)*(h - 2*lato)*lato;
        if (V > Vmax) {
            Vmax = V;
            lato_max = lato;
        }
        lato += 1;
    }
    printf("Il volume migliore possibile è %f e la lunghezza di taglio per ottenerlo è %f",
        Vmax, lato_max);
    return 0;
}