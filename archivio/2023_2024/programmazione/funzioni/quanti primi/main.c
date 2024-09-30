#include <stdio.h>
#include <math.h>

int primo(int n) {
    for (int i = 2; i < sqrt(n); ++i) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int n_primi(int a, int b){
    int conta=0;
    for (int i = a; i <=b ; ++i) {
        if(primo(i)==1)
            conta++;

    }
    return conta;
}

int main() {
    printf("%d\n", n_primi(2,100));
    return 0;
}
