#include <stdio.h>
#include <string.h>

int main(){

char name[50];

printf("Entrer le nom:");
fgets(name, sizeof(name), stdin);
name[strlen(name) - 1] = '\0';


int num = strlen(name);

for (int i = 0; i < num; i++)
{
  name[i] = tolower(name[i]);
}
 printf("%s",name);

}