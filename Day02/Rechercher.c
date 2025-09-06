#include <stdio.h>

void swap(int arr[], int size, int number)
{
  int found = 0;

  for (int i = 0; i < size; i++)
  {
    if (arr[i] == number)
    {
      found = 1;
      break;
    }
  }

  if (found)
  {
    printf("Trouve");
  }
  else
  {
    printf("Non Trouve");
  }
}

int main()
{
  int size;
  int number;

  printf("Entrer le nombre des elements:");
  scanf("%d", &size);
  int arr[size];

  for (int i = 0; i < size; i++)
  {
    printf("Entrer les nombres:");
    scanf("%d", &arr[i]);
  }

  printf("Entrer le nombre  a rechercher:");
  scanf("%d", &number);

  swap(arr, size, number);
}