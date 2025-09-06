#include <stdio.h>

int main()
{
  int T[50], N;
  printf("Entrer la valeur ");
  scanf("%d", &N);
  T[0] = 0;
  T[1] = 1;
  for (int i = 2; i <= N; i++)
  {
    T[i] = T[i - 1] + T[i - 2];
  }

  for (int i = 0; i <= N; i++)
  {
    printf("%d ", T[i]);
  }
}