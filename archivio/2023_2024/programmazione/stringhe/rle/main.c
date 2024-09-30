#include <stdio.h>
void codifica_rle(char originale[],char codificata[]){
    int j=0;
    for (int i=0 ; originale [i]!= '\0'; i++){
        int contatore=1;
        while  (contatore<9 && originale[i]==originale[i+1]){
            contatore++;
            i++;
        }
        if (contatore==1){
            codificata[j]=originale[i];
            j++;
        } else{
            codificata[j]=contatore+'0';
            j++;
            codificata[j]=originale[i];
            j++;
        }
    }
   codificata[j]='\0';
}
void decodifica_rle(char codificata[], char originale[]){
    int i=0 , j=0;
    while (codificata[i]!='\0'){
        if (codificata[i]>='2' && codificata[i]<='9'){
            int quanti=codificata[i]-'0';
            for (int k=0;k<quanti;k++){
                originale[j]=codificata[i+1];
                j++;
            }
            i=i+2;
        }else{
            originale[j]=codificata[i];
            j++;
            i++;
        }
    }
    originale[j]='\0';
}
int main() {
    char s[]="affgggffffffffffff";
    char c[100];
    char d[100];
    codifica_rle(s,c);
    printf("%s\n",c);
    decodifica_rle(c,d);
    printf("%s", d);
    return 0;
}
