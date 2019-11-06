#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node* next;
};

void create(struct node**);
void display(struct node*);
int survivor(struct node**,int skip);

void create(struct node** head_ref){
  struct node* temp,*rear;
  int a,ch;
  do{
    printf("Enter a number");
    scanf("%d",&a);
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=a;
    temp->next=NULL;
    if(*head_ref==NULL){
      *head_ref=temp;
    }else{
      rear->next=temp;
    }
    rear=temp;
    printf("Do u want to add? [0->no / 1->yes]");
    scanf("%d",&ch);
  }while(ch!=0);
  rear->next=*head_ref;
}

void display(struct node* head){
struct node* temp=head;
printf("%3d",temp->data);
temp=temp->next;
while(head!=temp){
  printf("%3d",temp->data);
  temp=temp->next;
}
printf("\n");
}

int survivor(struct node** head_ref,int skip){
struct node*p,*q;
q=p=(*head_ref);
while(p->next!=p){
  for(int i=0;i<skip;i++){
    q=p;
    p=p->next;
  }
  q->next=p->next;
  printf("\n%d kiled\n",p->data);
  p=q->next;
}
(*head_ref)=p;
return(p->data);




}







void main(){
  struct node* head=NULL;
  int survive,skip;
  create(&head);
  printf("The persons in circular list are\n");
  display(head);
  printf("Enter persons to skip");
  scanf("%d",&skip);
  survive=survivor(&head,skip);
  printf("The person to survive is %d",survive);
  free(head);

}
