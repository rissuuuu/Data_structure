#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int top=-1;
int stack[100];


void push()
{

}






void main(){
  char number[20]="";
  printf("Enter number: ");
  scanf("%s",&number);
  printf("%s ",number );
  for(int i=0;i<strlen(number);i++){
    printf("%d ",number[i]-48 );
  }

}
