#include <stdio.h>

int n_cifre(int n){
    int contatore = 0;
    while(n > 0){
        n = n / 10;
        contatore ++;
    }
    return contatore;
}

int digit(int n, int k){
    if(k<=0){
        return -1;
    };
    if(k > n_cifre(n)){
        return -1;
    };
    int cifra;
    while(k > 0){
        cifra = n % 10;
        n = n / 10;
        k--;
    }
    return cifra;
}

int main() {
    int n = 1234, k = 2;
    int c;
    c = digit(n,k);
    if(c == -1){
        printf("Valore di k sbagliato");
    }else{
        printf("La %d cifra di %d è: %d",k,n,c);
    }
    return 0;
}
