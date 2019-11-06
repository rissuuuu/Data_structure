#include<stdio.h>
#include<stdlib.h>

struct palin{
  int data;
  struct palin* next;
};struct palin* head1;struct palin head2;


struct palin* create(int element){
  struct palin* newnode=(struct palin*)malloc(sizeof(struct palin));
  newnode->data=element;
  newnode->next=NULL;
  return newnode;

}

void push(struct palin** head_ref,int data);

void push(struct palin** head_ref,int data){
struct palin* temp=(struct palin*)malloc(sizeof(struct palin));
  temp->data=data;
  temp->next=(*head_ref);
  (*head_ref)=temp;
}



struct palin* insert(struct palin* head,int data){
  struct palin* head2=NULL;
  struct palin* temp1=(struct palin*)malloc(sizeof(struct palin));
  struct palin* temp=head;
  if(temp==NULL){
    temp1=create(data);
    temp=temp1;

  }
  else{
  while(temp->next!=NULL){
    temp=temp->next;
  }

  temp1=create(data);
  push(&head2,temp1->data);
  temp->next=temp1;

}
return temp;
}

void traverse(struct palin* head);

void traverse(struct palin* head){
while(head){
  printf("%d",head->data );
  head=head->next;
}
}

int  pop(struct palin** head_ref);

int  pop(struct palin** head_ref){
  struct palin* top;
  int res;
  if(head_ref){
    top=(*head_ref);
    res=top->data;
    (*head_ref)=top->next;
    free(top);
    return res;
  }




}

void checking(struct palin* head1,struct palin* head2);

void checking(struct palin* head1,struct palin* head2){
  printf("\n" );
  traverse(head2);

  int n1,n2;
while(head1){
  n1=pop(&head1);
  n2=pop(&head2);
  printf("%d,%d \n",n1,n2 );
  head1=head1->next;

}
}




void main(){
  struct palin* head2=NULL;
  struct palin* head1=NULL;
  int n1,n2;
head1=create(1);
insert(head1,2);
insert(head1,3);
insert(head1,4);
insert(head1,5);
insert(head1,6);
insert(head1,7);

traverse(head1);
printf("\n");
while(head1){
  push(&head2,head1->data);
  head1=head1->next;
}
printf("\n" );
traverse(head2);

//checking(head2,head1);
  n1=pop(&head1);
  n2=pop(&head2);
  printf("%d,%d \n",n1,n2 );

}
