#include <stdio.h>

void floyd(int n){
    int contatore=1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i+1 ; ++j) {
          printf(" %d ", contatore);
          contatore++;
        }
        printf("\n");
    }
}

int main() {
    floyd(5);
    return 0;
}
