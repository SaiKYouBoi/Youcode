#include <stdio.h>

void swap(int arr[], int size)
{

  for (int i = 0; i < size; i++)
  {
    if (arr[i]%2 == 0)
    {
      printf("%d\n",arr[i]);
    }
  }
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