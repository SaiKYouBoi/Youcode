#include <stdio.h>
#include <string.h>

int main(){

char name[50];
int count = 0;
char caractere;

printf("Entrer le nom:");
fgets(name, sizeof(name), stdin);
name[strlen(name) - 1] = '\0';

printf("Entrer le caractere:");
scanf("%c",&caractere);

int num = strlen(name);

for (int i = 0; i < num - 1; i++)
{
  if (name[i] == caractere)
  {
    count++;
  }
}
 printf("%d",count);

}