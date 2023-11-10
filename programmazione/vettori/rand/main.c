#include <stdio.h>
#include <stdlib.h>

#define N_LANCI 150

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

int un_dado(){
    return rand() % 6 +1;
}

int due_dadi(){
    return un_dado() + un_dado();
}
int main() {
    int v1[7], v2[13];
    for (int i = 0; i < 7; ++i) {
        v1[i] = 0;
    }
    for (int i = 0; i < 13; ++i) {
        v2[i] = 0;
    }
    // simulazione con un dado
    for (int i = 0; i < N_LANCI; ++i) {
        v1[un_dado()]++;
    }
    for (int i = 1; i <= 6; ++i) {
        float percentuale =(float)v1[i] / N_LANCI * 100;
        printf("%d : numero di volte %d (%f%%)\n",
               i, v1[i], percentuale);

    }
    istogramma(&v1[1], 6, 30);
    return 0;
}
