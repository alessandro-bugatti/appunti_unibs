#include <stdio.h>
int contacifre(int n) {
    int conta = 0;
    while( n > 0 ) {
        n = n / 10;
        conta++;
    }
    return conta;
}
int cifra(int n, int k) {
    if(k <= 0) {
        return -1;
    }
    if( k > contacifre(n)) {
        return -1;
    }
    for(int i = 0; i < k - 1; i++) {
        n = n / 10;
    }
    return n%10;
}
int main(void) {
    printf("%d \n",cifra (145, 2));
    printf("%d \n",cifra (1, 2));
    return 0;
}
