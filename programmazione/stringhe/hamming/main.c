#include <stdio.h>
#include <string.h>

int my_strlen(char s[]) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

int hamming(char s1[], char s2[]) {
    if (strlen(s1) != strlen(s2)) {
        return -1;
    }
    int conta = 0;
    for (int i = 0; i < s1[i] != '\0'; ++i) {
        if (s1[i] != s2[i]) {
            conta++;
        }
    }
    return conta;
}

int main(void) {
    char s1[] = "pinO", s2[] = "lino", s3[] = "mario";
    printf("%d %d\n", strlen(s1), my_strlen(s1));
    printf("La distanza di Hamming tra %s e %s è %d",
        s1, s2, hamming(s1, s2));
    printf("La distanza di Hamming tra %s e %s è %d",
        s1, s3, hamming(s1, s3));
    return 0;
}
