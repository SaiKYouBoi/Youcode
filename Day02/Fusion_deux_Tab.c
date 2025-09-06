#include <stdio.h>

void swap(int arr1[], int arr2[], int size1, int size2)
{
  int totalsize = size1 + size2;
  int mergarr[totalsize];

  for (int i = 0; i < size1; i++)
  {
    mergarr[i] = arr1[i];
  }

  for (int i = 0; i < size2; i++)
  {
    mergarr[size1 + i] = arr2[i];
  }
  printf("Tableau fusionne:\n");

  for (int i = 0; i < totalsize; i++)
  {
    printf("%d ", mergarr[i]);
  }
}

int main()
{
  int size1, size2;

  printf("Entrer le nombre des elements de 1er tableau:");
  scanf("%d", &size1);
  int arr1[size1];

  for (int i = 0; i < size1; i++)
  {
    printf("Entrer les nombres de 1er tableau:");
    scanf("%d", &arr1[i]);
  }

  printf("Entrer le nombre des elements de 2eme tableau:");
  scanf("%d", &size2);
  int arr2[size2];

  for (int i = 0; i < size2; i++)
  {
    printf("Entrer les nombres de 2eme tableau:");
    scanf("%d", &arr2[i]);
  }

  swap(arr1, arr2, size1, size2);
}