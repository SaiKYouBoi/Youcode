#include <stdio.h>

int num = 7;

int main()
{
  for (int i = 1; i <= 7; i++)
  {
    for (int j = 1; j <= num - i; j++)
    {
      printf(" ");
    }
    for (int k = 1; k <= 2 * i - 1; k++) {
            printf("*");
        }
    printf("\n");
  }

  return 0;

}