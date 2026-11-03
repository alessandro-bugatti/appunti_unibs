#include <stdio.h>
#include <math.h>

float delta(float a, float b, float c) {
    return b*b - 4*a*c;
}

void secondo_grado(float a, float b, float c,
                    float *x1, float *x2) {

    *x1 = (-b + sqrt(delta(a, b, c))) / (2 * a);
    *x2 = (-b - sqrt(delta(a, b, c))) / (2 * a);
}

int main(void) {
    float a, b, c, xa, xb;
    a = 4;
    b = 120;
    c = 7;
    secondo_grado(a, b, c, &xa, &xb);
    printf("x1 = %f x2 = %f\n", xa, xb);
    return 0;
}
