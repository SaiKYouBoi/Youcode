#include <stdio.h>
#include <string.h>

int main(){

char name[50];

printf("Entrer le nom:");
fgets(name, sizeof(name), stdin);
name[strlen(name) - 1] = '\0';


int num = strlen(name);

int j = 0; 

    for (int i = 0; i < num ; i++) {
        if (name[i] != ' ') {       
            name[j] = name[i];
            j++;
        }
    }
    
    name[j] = '\0';

 printf("%s",name);

}