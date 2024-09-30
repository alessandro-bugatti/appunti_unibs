#include <stdio.h>

int maggiore(int a, int b){
    if (a > b){
        return a;
    }
    else{
        return b;
    }
}

int main() {
    int c = 4;
    int d = 8;
    int m = maggiore(c, d);
    printf("%d\n", m);
    return 0;
}
