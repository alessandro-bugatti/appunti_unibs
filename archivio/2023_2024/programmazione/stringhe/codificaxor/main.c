#include <stdio.h>
char codifica_xor(char a, char b){
    return a^b;
}
void codifica_stringa(char s[]){
    for (int i = 0; s[i] != 0; ++i) {
        s[i] = codifica_xor(s[i], 0x5A);
    }
}
int main() {
    char s[] = "arrivederci";
    codifica_stringa(s);
    printf("%s\n", s);
    codifica_stringa(s);
    printf("%s\n", s);

    return 0;
}
