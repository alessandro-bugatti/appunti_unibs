#include <stdio.h>
#include <math.h>

typedef struct
{
    double a;
    double b;
} Complesso;

typedef struct
{
    double r;
    double phi;
}ComplessoExp;

double modulo(Complesso z) {
    return sqrt(z.a * z.a + z.b * z.b);
}

Complesso coniugato(Complesso c) {
    Complesso con;
    con = c;
    con.b = -con.b;
    //coniugato.a = c.a;
    //coniugato.b = -c.b;
    return con;
}

Complesso somma(Complesso z1, Complesso z2) {
    Complesso s;
    s.a = z1.a + z2.a;
    s.b = z1.b + z2.b;
    return s;
}

Complesso differenza(Complesso z1, Complesso z2) {
    z2.a = -z2.a;
    z2.b = -z2.b;
    return somma(z1, z2);
}

ComplessoExp converti_in_exp(Complesso c) {
    ComplessoExp x;
    x.r = modulo(c);
    x.phi = atan2(c.b, c.a);
    return x;
}

Complesso converti_in_cartesiano(ComplessoExp c) {
    Complesso cartesiano;
    cartesiano.a = c.r * sin(c.phi);
    cartesiano.b = c.r * cos(c.phi);
    return cartesiano;
}

Complesso prodotto(Complesso z1, Complesso z2) {
    ComplessoExp x1, x2, p;
    x1 = converti_in_exp(z1);
    x2 = converti_in_exp(z2);
    p.r = x1.r * x2.r;
    p.phi = x1.phi + x2.phi;
    return converti_in_cartesiano(p);
}

void stampa(Complesso c) {
    printf("%lf + %lfi", c.a, c.b);
}

int main(void) {
    Complesso c = {2, 4}, con, s;
    double m = modulo(c);
    con = coniugato(c);
    c = coniugato(c);
    s = somma(c, con);
    stampa(s);
    return 0;
}
