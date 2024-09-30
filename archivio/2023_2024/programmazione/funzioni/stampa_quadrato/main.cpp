#include <stdio.h>

void stampa_quadrato(int n, char c){
    if(n==1){
        printf("%c\n",c);
        return;
    }
    for (int i = 0; i < n; ++i) {
        printf("%c", c);
    }
    printf("\n");
    for (int i = 0; i < n-2 ; ++i) {
        printf("%c", c);
        for (int j = 0; j < n-2 ; ++j) {
            printf(" ");
        }
        printf("%c\n",c);
    }
    for (int i = 0; i < n; ++i) {
        printf("%c", c);
    }
    printf("\n");
}


int main() {
    stampa_quadrato(4, '*');
    return 0;
}
