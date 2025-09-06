#include <stdio.h>
int main(){

int size,numfac;

printf("Entrer le taille:");
scanf("%d",&size);

int arrnum[size];

printf("Entrer les nombres:\n");
for (int i = 0; i < size; i++)
{
  printf("N%d:",i+1);
  scanf("%d",&arrnum[i]);
}

for (int i = 0; i < size - 1; i++)
{
  for (int j = 0; j < size - i - 1; j++)
  {
    int temp = arrnum[j];
    arrnum[j]=arrnum[j+1];
    arrnum[j+1]=temp;
  }
}

printf("Entrer le factoriel:");
scanf("%d",&numfac);

printf("Table de multiplication en ordre décroissant:\n");

for (int i = 0 ; i < size ; i++)
{
  int fac = arrnum[i]*numfac;
  printf("%d * %d = %d\n",arrnum[i],numfac,fac);
}
}