#include <stdio.h>
#define N 100

int main() {
    int v[N];
    int quanti;
    printf("quanti numeri?");
    scanf("%d",&quanti);
    for(int i=0;i<quanti;i++){
        scanf("%d",&v[i]);
    }
    for(int i=0;i<quanti;i++) {
        if (v[i] % 2 == 0) {
            printf("%d\n", v[i]);
        }
    }
        for(int i=0;i<quanti;i++){
            if(v[i]%2!=0){
                printf("%d\n",v[i]);
            }
        }

    return 0;
}
