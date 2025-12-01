#include <math.h>
#include <stdio.h>

//da completare per gestire quando il delta è < 0

//Versione nuova aggiunta utilizzando le strutture

typedef struct
{
    double s1;
    double s2;
} Soluzioni;

void sol_secondo_grado(double a, double b, double c,
                        double *s1, double *s2) {
    double delta = b * b - 4 * a * c;
    *s1 = (- b + sqrt(delta)) / (2 * a);
    *s2 = (- b - sqrt(delta)) / (2 * a);
}

Soluzioni sol_secondo_grado_nuova(double a, double b, double c) {
    Soluzioni s;
    double delta = b * b - 4 * a * c;
    s.s1 = (- b + sqrt(delta)) / (2 * a);
    s.s2 = (- b - sqrt(delta)) / (2 * a);
    return s;
}

int main(void) {
    double a = 1000, b = 10, c = 2;
    double sol1, sol2;
    sol_secondo_grado(a, b, c, &sol1, &sol2);
    printf("s1: %lf, s2: %lf\n", sol1, sol2);
    Soluzioni s = sol_secondo_grado_nuova(a, b, c);
    printf("s1: %lf, s2: %lf\n", s.s1, s.s2);

    return 0;
}