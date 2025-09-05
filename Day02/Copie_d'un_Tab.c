#include <stdio.h>

int arr[] = {7, 2, 5, 4, 9, 6};
int size = 6;
int arr1[6];

int main()
{

  printf("Tableau original:\n");
  for (int i = 0; i < size; i++)
  {
    arr1[i] = arr[i];
    printf("%d\n", arr[i]);
  }

  printf("Tableau copie:\n");
  for (int i = 0; i < size; i++)
  {
    printf("%d\n", arr1[i]);
  }
}