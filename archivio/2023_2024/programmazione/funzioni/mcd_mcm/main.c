#include <stdio.h>

int MCD_lento (int a, int b){
    int divisore;
    if (a<b){
        divisore = a;
    } else {
        divisore = b;
    }
    for (int i = divisore; i > 0; --i) {
        if (a%i == 0 && b%i == 0){
            return i;
        }

    }

}

int MCD (int a, int b) {
    while (a%b != 0) {
        int resto = a%b;
        a = b;
        b = resto;
    }
    return b;
}

int mcm (int a, int b) {
    return a*b/MCD(a,b);
}

int main() {
    printf("%d", MCD(15,17));
    return 0;
}
