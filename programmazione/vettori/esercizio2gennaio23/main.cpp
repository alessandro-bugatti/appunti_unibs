#include <stdio.h>
#include <cstdlib>

#define DIM 64
void componi(int A[][DIM],int B[][DIM],int R[][DIM])
{
    for (int i = 0; i <DIM ; ++i) {
        for (int j = 0; j <DIM ; ++j) {
            R[i][j]=A[i][j]-B[i][j];
            if(R[i][j]<0)
                R[i][j]=-R[i][j];
        }

    }
}
int main() {
    int M[100][DIM][DIM];
    int R[DIM][DIM];
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < DIM; ++j) {
            for (int k = 0; k < DIM; ++k) {
                M[i][j][k]=rand()%1000+1;
            }

        }
    }
    componi(M[0],M[1],R);
    for (int i = 2; i < 100 ; ++i) {
        componi(R,M[i],R);
    }
    return 0;
}
