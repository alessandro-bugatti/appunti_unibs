#include <math.h>
#include <stdio.h>

int main(void) {
    double x, coseno = 0;
    int n;
    double potenza = 1;
    int numeratore = 1;
    int denominatore = 1;
    printf("Inserisci l'angolo: ");
    scanf("%lf", &x);
    printf("Inserisci il numero di termini della sommatoria: ");
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        coseno = coseno + (float)numeratore / denominatore * potenza;
        potenza = potenza * x * x;
        numeratore = -numeratore;
        denominatore = denominatore * (2*i + 1) * (2*i + 2);

    }
    printf("Il coseno di %lf è %lf\n", x, coseno);
    printf("Il coseno di %lf calcolato con la funzione di libreria è %lf\n", x, cos(x));
    return 0;
}
