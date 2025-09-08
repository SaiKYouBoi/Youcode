#include <stdio.h>
#include <string.h>

int main(){
char name[50];

printf("Entrer le nom:");
fgets(name, sizeof(name), stdin);
name[strlen(name) - 1] = '\0';

int num = strlen(name);

for (int i = num - 1; i >= 0; i--)
{
  printf("%c",name[i]);
}

}