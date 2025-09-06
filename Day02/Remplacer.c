#include <stdio.h>

void swap(int arr[], int size, int remplacement, int nouveanum)
{

  for (int i = 0; i < size; i++)
  {
    if (arr[i] == remplacement)
    {
      arr[i] = nouveanum;
      break;
    }
  }

  printf("Nouvelle Tableau:\n");

  for (int i = 0; i < size; i++)
  {
    printf("%d\n", arr[i]);
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

  printf("La valeur a remplacer:");
  scanf("%d", &remplacement);

  printf("Novelle Valeur:");
  scanf("%d", &nouveanum);

  swap(arr, size, remplacement, nouveanum);
}