#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* link;

};struct node* top=NULL;

void push(int);
void traverse();

void push(int element){
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=element;
	temp->link=top;
 	top=temp;
 	printf("%d",temp->data);

}
void traverse(){


}





void mian(){
	int ele;
	while(ele!=0){
	printf("Enter data");
	scanf("%d",&ele);
	push(ele);
}
}
