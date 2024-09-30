#include <stdio.h>
#define N 100
int main()
{
   float v[N], media=0;
   int num=0, contatore = 0;
    printf("Quanti numeri?");
    scanf("%d",&num);
    for (int i = 0; i < num; ++i)
    {
        scanf("%f",&v[i]);
        media = media + v[i];
    }
    media  = media / num ;
    for (int i = 0; i < num; ++i)
    {
      if( v[i] > media )
      {
        contatore++;
      }

    }
    printf(" I numeri maggiori della media sono %d: ",contatore);
    for (int i = 0; i < num; ++i)
    {
        if(v[i]>media)
        {
            printf("%f\n",v[i]);
        }
    }
    return 0;
}
