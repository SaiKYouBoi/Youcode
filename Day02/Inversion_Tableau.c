#include <stdio.h>

void swap(int arr[],int size){

  for (int i = size-1; i >=0; i--)
  {
      printf("%d",arr[i]);
  }
  
}

int main()
{
  int size ;

  printf("Entrer le nombre des elements:");
  scanf("%d",&size);
  int arr[size];

  for (int i = 0; i < size; i++)
  {
    printf("Entrer les nombres:");
    scanf("%d",&arr[i]);
  }

  swap(arr,size);

}