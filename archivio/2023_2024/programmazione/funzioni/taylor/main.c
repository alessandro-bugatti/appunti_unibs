#include <stdio.h>
#include <math.h>

double potenza(double b, int e){
    double p = 1;
    for (int i = 0; i < e ; ++i) {
        p = p * b;
    }
    return p;
}

int fattoriale(int n){
    int f = 1;
    for (int i = 1; i <= n ; ++i) {
        f = f * i;
    }
    return f;
}

double seno(double x, int n){
    double s = 0;
    for (int i = 0; i < n; ++i) {
        s = s + potenza(-1,i) / fattoriale(2 * i + 1) *
                        potenza(x,2 * i + 1);
    }
    return s;
}

int main() {
    printf("%lf", seno(M_PI / 4, 10));
    return 0;
}
