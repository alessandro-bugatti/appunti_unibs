#include <stdio.h>

void encoding(char s[], char e[]) {
    int conta = 1, j = 0;
    for (int i = 0; s[i] != '\0' ; ++i) {
        if (s[i] == s[i+1]) {
            conta++;
        }else {
            if (conta == 1) {
                e[j] = s[i];
                j++;
            }else {
                e[j] = conta + '0';
                e[j+1] = s[i];
                j += 2;
            }
        }
    }
}

int main(void) {
    printf("Hello, World!\n");
    return 0;
}
