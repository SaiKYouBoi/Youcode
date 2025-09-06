#include <stdio.h>

int main()
{

int base, expo;
int count=0,result=1;

  printf("Entrer la base");
  scanf("%d",&base);

  printf("Entrer l'exposant");
  scanf("%d",&expo);

  while (count<expo)
  {
    result*=base;
    count++;
  }

  printf("Result:%d",result);

}
