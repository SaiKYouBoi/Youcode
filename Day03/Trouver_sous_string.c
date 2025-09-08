#include <stdio.h>
#include <string.h>

int main(){

char name[50];
char soustr[50];

printf("Entrer le nom:");
fgets(name, sizeof(name), stdin);
name[strlen(name) - 1] = '\0';

printf("Entrer le sous-string:");
fgets(soustr, sizeof(soustr), stdin);
soustr[strlen(soustr) - 1] = '\0';

int num = strlen(name);


    if (strstr(name, soustr) != 0) {
        printf("Sous-string trouvee\n");
    } else {
        printf("Sous-string non trouvee\n");
    }

}