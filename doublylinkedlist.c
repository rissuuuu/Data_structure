#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* next;
  struct node* prev;
}; struct node* head; struct node** head2;


void push(struct node** head_ref,int data);
void insertbefore(struct node** head_ref,struct node* next_node,int data );
void printList(struct node* node);
void insert(struct node* head,int data);
void traverse(struct node* head);
void traverseback(struct node* head);
int pop(struct node** head_ref);



struct node* create(int data){
struct node* temp=(struct node*)malloc(sizeof(struct node));
temp->data=data;
temp->prev=NULL;
temp->next=NULL;
return temp;
}


void insert(struct node* head,int data){
struct node* new_node=(struct node*)malloc(sizeof(struct node));
struct node* temp=head;
struct node* temp2=head;
while(temp->next){
temp=temp->next;
}
new_node=create(data);
temp->next=new_node;
new_node->prev=temp;
//new_node->next=temp2;


}

void push(struct node** head_ref,int data)
{
struct node* temp=(struct node*)malloc(sizeof(struct node));
temp->data=data;
//printf("%d\n",temp->data );
temp->next=(*head_ref);
(*head_ref)=temp;
}

int pop(struct node** head_ref){
struct node* top;
int result;
if(*head_ref==NULL){
  getchar();
  exit(0);
}
  else{
    top=(*head_ref);
    result=top->data;
    (*head_ref)=top->next;
    free(top);
    return result;
  }
}



void insertbefore(struct node** head_ref,struct node* next_node,int data )
{



}

void printList(struct node* node)
{



}
void traverse(struct node* head){
  struct node* temp=head;
  while(temp){
    printf("%d->",temp->data);
    temp=temp->next;
  }
}

void traverseback(struct node* temp){
struct node* temp1=temp;
struct node* temp2;
  while(temp1){

    temp2=temp1;
    temp1=temp1->next;
  }
  while(temp2){
    printf("%d->",temp2->data);
    temp2=temp2->prev;
  }
}

int main(){

struct node* head=NULL;
int popped;
struct node* head2=NULL;
struct node* temp;
head=create(10);
insert(head,20);
insert(head,30);
insert(head,40);
insert(head,50);
insert(head,60);
insert(head,70);

traverse(head);
printf("\n\n");

traverseback(head);
//temp=head;
//printf("\n" );

/*while(temp){
  push(&head2,temp->data);
  temp=temp->next;
}
traverse(head2);
printf("\n");
while(!NULL){
  popped=pop(&head2);
  //printf("%d->",popped );
}*/

}
