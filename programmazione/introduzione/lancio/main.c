#include <math.h>
#include <stdio.h>

int main(void) {
    float alfa, v0, x, y, v0x, v0y, t, prec = -1;
    int salita = 1;
    printf("Inserisci l'angolo di lancio: ");
    scanf("%f", &alfa);
    printf("Inserisci la velocità iniziale: ");
    scanf("%f", &v0);
    v0x = cos(alfa) * v0;
    v0y = sin(alfa) * v0;
    x = 0;
    y = 0;
    t = 0;
    prec = 0;
    while (y >= 0 && salita == 1) {
        printf("Al tempo %f l'oggetto di trova alle coordinate %f, %f\n",
            t, x, y);
        t += 0.001;
        x = v0x * t;
        y = v0y * t - 0.5 * 9.81 * t * t;
        if (prec > y) {
            salita = 0;
        }
        prec = y;
    }
    return 0;
}
