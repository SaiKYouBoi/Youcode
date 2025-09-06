#include <stdio.h>

int main()
{
    int numbers;

    printf("Entrer un nombre entier: ");
    scanf("%d", &numbers);

    while (numbers != 0)
    {
        int number = numbers % 10;
        printf("%d", number);
        numbers = numbers / 10;
    }

    printf("\n");
    return 0;
}
