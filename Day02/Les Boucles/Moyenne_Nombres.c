#include <stdio.h>

int main() {
    int num;
    int sum = 0;
    int count = 0;

    printf("Entrer des nombres positifs (0 pour terminer):\n");

    while (1) {
        scanf("%d", &num);

        if (num == 0) {
            break;  
        }

        sum += num;
        count++;
    }

    if (count > 0) {
        printf("Moyenne: %f\n", sum / count);
    } 

    return 0;
}
