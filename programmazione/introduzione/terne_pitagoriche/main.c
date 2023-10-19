#include <stdio.h>

int main() {
    int N;
    printf("inserisci un numero: ");
    scanf("%d", &N);
    for (int i = 1; i <=N ; ++i) {
        for (int j = i; j <=N ; ++j) {
            for (int k = j; k <=N ; ++k) {
                if(i*i+j*j==k*k)
                    printf("%d %d %d\n", i, j, k);
            }
        }
    }
    return 0;
}
