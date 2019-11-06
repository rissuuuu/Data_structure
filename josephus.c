#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node* next;
};

void create(struct node**);
void display(struct node*);
int survivor(struct node**,int);

void create(struct node** head){
struct node* temp, *rear;
int a,ch;
do{
  printf("Enter a number");
  scanf("%d",&a);
  temp=(struct node*)malloc(sizeof(struct node));
  temp->data=a;
  temp->next=NULL;

  if(*head==NULL){
  *head=temp;
  }
  else{
    rear->next=temp;
  }
  rear=temp;
  printf("Do u want to add another number[0/1]?");
  scanf("%d",&ch);
}while(ch!=0);
rear->next=*head;
}

void display(struct node* head){
struct node* temp=head;
printf("%d\t",temp->data);
temp=temp->next;
while(head!=temp){
  printf("%d\t",temp->data);
  temp=temp->next;
}
printf("\n");

}

int survivor(struct node** head,int k){
struct node*p,*q;
int i;
q=p=*head;
while(p->next!=p){
  for(i=0;i<k-1;i++){
    q=p;
    p=q->next;
  }
  q->next=p->next;
  printf("%d is killed\n",p->data );
  free(p);
  p=q->next;
}
*head=p;
return(p->data);



}

int main(){
struct node* head=NULL;
int survive,skip;
create(&head);
printf("The persons of circular list are\n" );
display(head);
printf("Enter the number of persons to be skipped:" );
scanf("%d",&skip);
survive=survivor(&head,skip);
printf("The person to survive is: %d\n",survive);
free(head);
return 0;



}
