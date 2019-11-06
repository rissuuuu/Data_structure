#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
  int data;
  struct node* next;
};
void push(struct node** head_ref,int data);
void sort(struct node* node);
bool isPresent(struct node* node,int data);

bool isPresent(struct node* head,int data){
struct node* temp=head;
while(temp!=NULL){
  if(temp->data==data)
    return 1;
  temp=temp->next;
  }
  return 0;
}


void push(struct node** head_ref,int data){
struct node* temp=(*head_ref);
struct node* newnode=(struct node*)malloc(sizeof(struct node));
if(!isPresent(temp,data)){
  newnode->data=data;
  newnode->next=(*head_ref);
  (*head_ref)=newnode;
}
}

void sort(struct node* head){
struct node* i;
struct node* j;
int temp;
printf("\n______________________\n");
for(i=head;i!=NULL;i=i->next){
  for(j=i->next;j!=NULL;j=j->next){
    if(i->data>j->data){
      temp=i->data;
      i->data=j->data;
      j->data=temp;
    }
  }

  printf("%d ",i->data);
}
printf("\n______________________\n");
}

void printlist(struct node* head){
while(head!=NULL){
  printf("%d->",head->data);
  head=head->next;
}
}

struct node* unions(struct node* head1,struct node* head2){
struct node* result=NULL;
struct node*t1=head1,*t2=head2;
while(t1!=NULL){
  push(&result,t1->data);
  t1=t1->next;
}
while(t2!=NULL){
  if(!isPresent(result,t2->data))
    push(&result,t2->data);
  t2=t2->next;

}
return result;

}

struct node* intersection(struct node* head1,struct node* head2){
struct node* result2=NULL;
struct node* t1=head1;
while(t1!=NULL){
  if(isPresent(head2,t1->data))
    push(&result2,t1->data);
  t1=t1->next;
  }
  return result2;
}

struct node* subtract(struct node* head1,struct node* head2){
struct node* result3=NULL;
struct node* t1=head1;
while(t1!=NULL){
  if(!isPresent(head2,t1->data))
    push(&result3,t1->data);
  t1=t1->next;
}
return result3;
}

void main(){
int choice,element;
struct node* head1=NULL,*head2=NULL,*getI,*getU,*getS;
while(1){
printf("\n  1.Insert in A 2.Insert in B\n 3.Intersection 4.Union \n 5.Subtraction Enter choice:");
scanf("%d",&choice);
switch(choice){
  case 1: printf("\nEnter the element for set A");
          scanf("%d",&element);
          push(&head1,element);
          break;

  case 2: printf("\nEnter the element for set B");
          scanf("%d",&element);
          push(&head2,element);
          break;
  case 3: printf("\nThe intersection is:");
          getI=intersection(head1,head2);
          //printlist(getI);
          sort(getI);
          break;

  case 4: printf("\nThe union is:");
          getU=unions(head1,head2);
          //printlist(getU);
          sort(getU);
          break;
  case 5: printf("The subtraction is:");
          getS=subtract(head1,head2);
          sort(getS);
          break;

  default: ("Invalid choice");


}

}
}
