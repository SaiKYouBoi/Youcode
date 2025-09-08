#include <stdio.h>
#include <string.h>

int main(){
char name[50];
char lastname[50];

printf("Entrer le nom:");
fgets(name, sizeof(name), stdin);
name[strlen(name) - 1] = '\0';

printf("Entrer le prenom:");
fgets(lastname, sizeof(lastname), stdin);
lastname[strlen(lastname) - 1] = '\0';

if(strcmp(name,lastname) == 0){
  printf("egale");
}else{
  printf("differentes");
}

}