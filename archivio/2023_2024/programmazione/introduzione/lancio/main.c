#include <stdio.h>
#include <math.h>

int main() {
    float v0, angolo, tempo=0;
    float v0x, v0y, x, y;
    x = 0;
    y = 0;
    printf("inserire la velocità: ");
    scanf("%f", &v0);
    printf("inserire l'angolo: ");
    scanf("%f",&angolo);
    v0x = v0 * cos(angolo);
    v0y = v0 * sin(angolo);
    do{
       tempo += 0.1;
       printf("x: %f y: %f\n", x, y);
       x = v0x * tempo;
       y = v0y * tempo -0.5*9.81*tempo*tempo;
    } while (y>0);
    return 0;
}
