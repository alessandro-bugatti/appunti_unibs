#include <stdio.h>

int main() {
   float importo, commissione ;
   printf ("inserisci l'importo: ");
   scanf("%f",&importo);
   if(importo<2500){
       commissione= importo * 1.7/100 + 30;


   } else if(importo<6250) {
       commissione=importo*0.66/100 + 56;
   } else if(importo<20000) {
       commissione=importo *0.34/100 +76;
   } else {
       commissione=importo *0.22/100 +100;
   }
    if(commissione<39){
        commissione=39;
    }
    printf("la commissione è di %f euro",commissione);
    return 0;
}
