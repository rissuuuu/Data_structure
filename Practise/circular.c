#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* next;
};
struct node* addEmpty(struct node* temp, int data){
if(temp!=NULL)
  return temp;

  struct node* newnode=(struct node*)malloc(sizeof(struct node));
  newnode->data=data;
  temp=newnode;

  temp->next=temp;
  return temp;


}

struct node* addbegin(struct node* temp,int data){
if(temp==NULL)
  addEmpty(temp,data);

  struct node* newnode=(struct node*)malloc(sizeof(struct node));
  newnode->data=data;
  newnode->next=temp->next;
  temp->next=newnode;
  return temp;



}
struct node* addafter(struct node* temp,int data){
if(temp==NULL)
return addEmpty(temp,data);
struct node* newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=data;
newnode->next=temp->next;
temp->next=temp;
temp=newnode;
return temp;



}
void traverse(struct node* last){
  struct node *p;

      // If list is empty, return.
      if (last == NULL)
      {
        printf("List is empty");
          return;
      }

      // Pointing to first Node of the list.
      p = last -> next;

      // Traversing the list.
      do
      {
          printf("%d->",p->data);
          p = p -> next;

      }
      while(p != last->next);



}

void main(){
  struct node* head=NULL;
  int choice;
  printf("Enter the element");
  scanf("%d",&choice);
  head=addEmpty(head,choice);
  while(1){
  printf("1. Insert begening 2.Insert End");
  scanf("%d",&choice);
  switch(choice){
    case 1: printf("Enter element");
            scanf("%d",&choice);
            head=addbegin(head,choice);
            break;
    case 2: traverse(head);

    default: printf("Invalid choice");
  }
}
}
