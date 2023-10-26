#include <stdio.h>
#include <math.h>

float delta(float a, float b, float c){
    return b*b - 4*a*c;
}

void secondo_grado(float a, float b, float c,
                   float *x1, float *x2){
    float d = delta(a, b, c);
    *x1 = (-b - sqrt(d))/(2*a);
    *x2 = (-b + sqrt(d))/(2*a);
}

int main() {
    float x1, x2, a = 1, b = 10, c = 1;
    scanf("%f", a);
    secondo_grado(a, b, c, &x1, &x2);
    printf("%f %f", x1, x2);
    return 0;
}
