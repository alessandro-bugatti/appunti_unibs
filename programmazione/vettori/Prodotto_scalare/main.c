#include <stdio.h>

int prodotto_scalare(int v1[], int v2[],int n){
    int accumulatore = 0;
    for (int i = 0; i < n; ++i) {
        accumulatore += v1[i] * v2[i];
    }
    return accumulatore;
}

int main() {
    int a[] = {1,2,3};
    int b[] = {1,1,1};
    printf("%d ", prodotto_scalare(a, b, 3));
    return 0;
}
