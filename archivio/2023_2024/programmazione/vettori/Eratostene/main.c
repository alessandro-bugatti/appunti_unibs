#include <stdio.h>
#define N 100
int main() {
    int crivello[N];
    for (int i = 0; i < N; ++i) {
        crivello[i]=1;
    }
    for (int i = 2; i <N/2 ; ++i) {
        if(crivello[i]==1){
            for (int j = 2*i; j <N ; j=j+i) {
                crivello[j]=0;

            }

        }

    }
    for (int i = 2; i <N ; ++i) {
        if(crivello[i]==1){
            printf("%d\n",i);

        }

    }
    return 0;
}
