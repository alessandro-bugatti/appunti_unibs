#include <stdio.h>

int esadecimale (char s[]){
    if(s[0] != '0'){
        return 0;
    }
    if (!(s[1] == 'x' || s[1] == 'X')){
        return 0;
    }
    for (int i = 2; s[i] != '\0' ; ++i) {
        if(!((s[i] >= '0' && s[i] <= '9') ||
        (s[i] >= 'A' && s[i] <= 'F') ||
        (s[i] >= 'a' && s[i] <= 'f'))){
            return 0;
        }
    }
    return 1;
}

int main() {
    printf("1234 %d\n", esadecimale("1234"));
    printf("0f1234 %d\n", esadecimale("0f1234"));
    printf("0x12G4 %d\n", esadecimale("0x12G4"));
    printf("0x1234 %d\n", esadecimale("0x1234"));
    printf("0X12fF %d\n", esadecimale("0X12fF"));
    char s[20];
    printf("Inserisci una stringa che rappresenta un valore esadecimale: ");
    scanf("%s", s); //NOn va la & perchè s è già un indirizzo
    if (esadecimale(s)){
        printf("%s è esadecimale\n", s);
    }
    else{
        printf("%s non è esadecimale\n", s);
    }
    //Vediamo come è fatto internamente una stringa
    for (int i = 0; i < 20; ++i) {
        printf("%c => %d\n", s[i], s[i]);
    }
    return 0;
}
