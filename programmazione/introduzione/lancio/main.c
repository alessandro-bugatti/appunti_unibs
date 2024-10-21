#include <stdio.h>
#include <math.h>

int main(void) {
    const float G = 9.81;
    float alfa, v0, v0x, v0y, x, y, t;

    printf("Inserisci l'angolo di lancio: ");
    scanf("%f", &alfa);
    printf("Inserisci la velocità iniziale: ");
    scanf("%f", &v0);
    x = 0;
    y = 0;
    t = 0;
    v0x = cos(alfa) * v0;
    v0y = sin(alfa) * v0;

    while(y > -0.001) {
        printf("x: %.4f y: %.2f\n", x, y);
        x = v0x * t;
        y = v0y*t - 0.5*G*t*t;
        t = t + 0.1;
    }
    return 0;
}
