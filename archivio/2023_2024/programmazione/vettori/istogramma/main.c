#include <stdio.h>

int massimo(int v[],int n)
{
    int max=v[0];
    for(int i=0; i<n; i++)
    {
        if(v[i]>max)
        {
            max=v[i];
        }
    }
    return max;
}

void istogramma(int v[], int n, int max)
{
    int m=massimo(v,n);

    for (int i = 0; i < n; ++i) {
        int n_asterischi;
        n_asterischi=(v[i]*max)/m;
        for (int j = 0; j < n_asterischi; ++j) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int vettore[]={23,18,34,5,23};
    istogramma(vettore,5,30);

    return 0;
}
