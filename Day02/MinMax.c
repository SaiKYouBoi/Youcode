#include <stdio.h>

int maxmin(int arr[],int size){
  
    int max = arr[0];
    int min = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i]; 
        }
        if (arr[i] < min) {
            min = arr[i]; 
        }
    }  
printf("Maximum\n:%d",max);
printf("Minimum:%d",min);

}

int main(){

int size;
int number;

printf("Etrer la taille:");
scanf("%d",&size);

int arr[size];

for (int i = 0; i < size; i++)
{
  printf("Entrer le nombres%d:",i+1);
  scanf("%d",&arr[i]);
  }
    
maxmin(arr,size);

}