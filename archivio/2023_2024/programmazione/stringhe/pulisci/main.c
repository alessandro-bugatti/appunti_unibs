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

int main() {
    char s[]="Sono Andato a Milano, pioveva.";
    pulisci_stringa(s);
    printf("%s",s);
    return 0;
}
