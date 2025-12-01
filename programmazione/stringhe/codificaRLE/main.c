#include <stdio.h>

void codificaRLE(char originale[], char compresso[]) {
    int ripetizioni = 1, j = 0;
    for (int i = 0; originale[i] != '\0'; ++i) {
        if (originale[i] == originale[i + 1] &&
            ripetizioni < 9) {
            ripetizioni++;
        }
        else {
            if (ripetizioni == 1) {
                compresso[j] = originale[i];
                j++;
            }
            else {
                compresso[j+1] = originale[i];
                compresso[j] = ripetizioni + '0';
                j += 2;
            }
            ripetizioni = 1;
        }
    }
    compresso[j] = '\0';
}

const int MAX = 100;

int main(void) {
    char s[] = "dddd";
    char t[] = "affggg";
    char r[] = "ffffffffffffff";
    char compresso[MAX];
    codificaRLE(s, compresso);
    printf("%s diventa %s\n", s, compresso);
    codificaRLE(t, compresso);
    printf("%s diventa %s\n", t, compresso);
    codificaRLE(r, compresso);
    printf("%s diventa %s\n", r, compresso);
    return 0;
}