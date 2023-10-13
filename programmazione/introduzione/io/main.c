#include <stdio.h>

/*
 * Questo è un primo programma
 * che calcola il perimetro e l'area di un rettangolo
 * Per le formule vedi
 * https://www.youmath.it/formulari/formulari-di-geometria-piana/337-tutte-le-formule-sul-rettangolo.html
 */

int main() {
    //Dichiarazioni
    float base, altezza;
    float perimetro, area;
    //Input
    printf("Inserisci la base: ");//dico all'utente cosa inserire
    scanf("%f", &base);
    printf("Inserisci l'altezza: ");
    scanf("%f", &altezza);
    //Elaborazione
    perimetro = (base + altezza) * 2;
    area = base * altezza;
    //Output
    printf("Perimetro: %f\n", perimetro);
    printf("Area: %f\n", area);
    //Riscritta in modo più articolato
    //La notazione è posizionale, nel senso che le variabili
    //vengono inserite nei segnaposti a seconda della loro posizione
    printf("Il perimetro è di %f metri, mentre l'area è di %f metri quadrati.\n",
           perimetro, area);

    return 0;
}
