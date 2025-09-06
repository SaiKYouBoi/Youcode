#include <stdio.h>

void swap(int arr[], int size)
{
  int somme=0;

  for (int i = 0; i < size; i++)
  {
  somme+=arr[i];
  }

  printf("Moyenne:%d\n",somme/size);
}

int main()
{
  int size;
  int nouveanum;
  int remplacement;

  printf("Entrer le nombre des elements:");
  scanf("%d", &size);
  int arr[size];

  for (int i = 0; i < size; i++)
  {
    printf("Entrer les nombres:");
    scanf("%d", &arr[i]);
  }
  swap(arr, size);
}