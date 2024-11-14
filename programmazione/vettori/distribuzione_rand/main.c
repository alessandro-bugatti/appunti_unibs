#include <stdio.h>
#include <stdlib.h>

#define N 100
#define N_LANCI 100000

int lanciadado(void) {
    return rand()%6+1;
}

int lancio2dadi(void) {
    return lanciadado()+lanciadado();
}

void azzera(int v[], int n) {
    for (int i = 0; i < n; ++i)
        v[i] = 0;
}

void stampa_distribuzione(int v[], int l, int r, int n_lanci) {
    for(int i = l; i <= r; ++i) {
        printf("%d : %d volte (%f \%)\n",
                i, v[i], ((float)v[i])/n_lanci*100);
    }
}

int main(void) {
    int contatori[N];
    azzera(contatori, N);
    //Lancio di un dado
    for (int i = 0; i < N_LANCI; ++i) {
        contatori[lanciadado()]++;
    }
    stampa_distribuzione(contatori, 1, 6, N_LANCI);
    azzera(contatori, N);
    //Lancio di due dadi
    for (int i = 0; i < N_LANCI; ++i) {
        int l = lancio2dadi();
        contatori[l] = contatori[l] + 1;
        //contatori[lancio2dadi()]++;
    }
    stampa_distribuzione(contatori, 2, 12, N_LANCI);
    return 0;
}
