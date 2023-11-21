#include <stdio.h>

void pulisci_stringa (char s[])
{
    int j = 0;
    for(int i=0;s[i] != '\0';++i)
    {
        if(s[i]>='a' && s[i]<='z')
        {
            s[j]=s[i];
            j++;
        }
        if(s[i]>='A' && s[i]<='Z')
        {
            s[j]=s[i]-'A'+'a';  //s[j]=tolower(s[i]);
            j++;
        }

    }
    s[j]='\0';
}

char codifica (char c, int n ){
    n= n % 26;
    return (c-'a'+n) % 26 + 'a';
}

void codifica_cesare( char s[], int n){
    for (int i = 0; s[i] != 0; i++){
        s[i]= codifica(s[i], n);
    }
}

char decodifica (char c, int n){
    n= n % 26;
    return (c-'a'- n + 26) % 26 + 'a';
}

void decodifica_cesare (char s[], int n){
    for (int i = 0; s[i] != 0; i++){
        s[i]= decodifica(s[i] , n);
    }
}

int main() {
    char s[]="arriviamo, siamo in zona";
    pulisci_stringa(s);
    codifica_cesare(s, 13);
    printf("%s \n", s);
    decodifica_cesare(s, 13);
    printf("%s", s);
    return 0;
}
