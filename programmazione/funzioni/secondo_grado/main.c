#include <stdio.h>
#include <tgmath.h>

float delta(float a, float b, float c) {
    return b*b - 4*a*c;
}

void secondo_grado(float a, float b, float c,
                float *x1, float *x2) {
    *x1 = (-b + sqrt(delta(a, b, c))) / (2*a);
    *x2 = (-b - sqrt(delta(a, b, c))) / (2*a);
}

int main(void) {
    float x1, x2;
    printf("%f %f \n", x1, x2);
    secondo_grado(4, 128, 4, &x1, &x2);
    printf("%f %f \n", x1, x2);
    return 0;
}
