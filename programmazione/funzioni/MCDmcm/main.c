#include <stdio.h>
int MCD(int n1, int n2) {
    int divisore;
    for(int i = 1 ; i <= n1 ; i++ ) {
        if(n1%i == 0 && n2%i == 0) {
            divisore = i;
        }
    }
    return divisore;
}
int MCDE(int a, int b) {
    while(a%b != 0) {
        int resto;
        resto = a%b;
        a = b;
        b = resto;
    }
    return b;
}

int mcm(int n1, int n2) {
    return n1 * n2 / MCDE(n1, n2);
}

int main(void) {
    printf("divisore: %d\n", MCD(12, 50));
    printf("divisore euclide: %d\n", MCDE(12, 50));
    return 0;
}
