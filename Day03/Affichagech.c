#include <stdio.h>
#include <string.h>

int main(){
char name[50];

printf("Entrer le nom:");
fgets(name, sizeof(name), stdin);
name[strlen(name) - 1] = '\0';

printf("Le nom est: %s",name);

}
