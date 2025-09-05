#include <stdio.h>

int main()
{

  int size;
  int multifactor;
  int result;

  printf("Entrer nombre des elements:");
  scanf("%d", &size);
  int arr[size];

  printf("Entrer le facteur de multiplication:");
  scanf("%d", &multifactor);
  
  for (int i = 0; i < size; i++)
  {
    printf("Entrer Les elements:");
    scanf("%d",&arr[i]);
    
  }

  for (int i = 0; i < size; i++)
  {
    result = arr[i]*multifactor;
    printf("%d*%d = %d\n",arr[i],multifactor,result);
  }
  
  return 0;
  
}
