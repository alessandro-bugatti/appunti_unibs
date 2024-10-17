#include <stdio.h>

int main(void) {
    float base, altezza;
    float perimetro, area;
    printf("Inserisci base: ");
    scanf("%f", &base);
    printf("Inserisci altezza: ");
    scanf("%f", &altezza);
    perimetro = (base + altezza) * 2;
    area = base * altezza;
    printf("Perimetro: %.2f\n", perimetro);
    printf("Area: %.2f\n", area);

    return 0;
}
