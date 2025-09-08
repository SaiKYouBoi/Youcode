#include <stdio.h>
#include <string.h>

int main(){
char name[50];

printf("Entrer le nom:");
fgets(name, sizeof(name), stdin);
name[strlen(name) - 1] = '\0';

int name1=strlen(name);
printf("Le nom est: %d",name1);

}