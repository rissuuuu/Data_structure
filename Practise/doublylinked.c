#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node* next;
  struct node* prev;
};

struct node* createnode(int data){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    temp->prev=NULL;
    return temp;

}
struct node* insert(struct node** head,int data){
  struct node* temp=(*head);
  struct node* newnode=createnode(data);
  if(temp==NULL)
  return createnode(data);
  while(temp->next){
    temp=temp->next;
  }
  temp->next=newnode;
  newnode->prev=temp;
  return temp;
}

void traverse(struct node* temp){
  while(temp){
    printf("%d->",temp->data);
    temp=temp->next;
  }
  printf("Null\n");
}

void traverseback(struct node* head){
struct node* temp=head;
struct node* tempback;
while(temp){
  tempback=temp;
  temp=temp->next;
}
while(tempback){
  printf("%d->",tempback->data);
  tempback=tempback->prev;
}
printf("Null\n");
}

struct node* deletenode(struct node** head_ref,int element){
struct node* temp=(*head_ref);
struct node* current=temp;
struct node* parent;
struct node* temp2;
if(temp->data==element){
current=temp->next;
(*head_ref)=current;
current->prev=NULL;
}

else
{
  while(current->data!=element){
    parent=current;
    current=current->next;

  }
  if(current->next==NULL){
    parent->next=NULL;
    free(current);
  }
  else{
  temp2=current->next;
  parent->next=temp2;
  temp2->prev=parent;
  }
}
return temp;
}

int main(){
  struct node* head=NULL;
  int choice,element;
  while(1){
    printf("1. Insert 2. Traverse 3. Delete Enter choice:");
    scanf("%d",&choice);
    switch(choice){
      case 1: printf("Enter the element to insert");
              scanf("%d",&element);
              if(head==NULL){
                head=insert(&head,element);
              }
              else{
                insert(&head,element);
              }
              break;

      case 2: printf("\n 1.Traverse Forward 2.Traverse Backward");
              scanf("%d",&choice);
              if(choice==1){
                traverse(head);

              }
              else if(choice==2){
                traverseback(head);
              }
              else{
                printf("Enter valid choice\n");
              }
              break;

      case 3: printf("\nEnter the element to delete");
              scanf("%d",&element);
              deletenode(&head,element);
              break;

      default: printf("Invalid choice");
    }
  }
}
