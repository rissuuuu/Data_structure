#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node* next;
};

struct node* createnode(int data){
  struct node* newnode=(struct node*)malloc(sizeof(struct node));
  newnode->data=data;
  newnode->next=NULL;
  return newnode;
}
struct node* insert(struct node** head_ref,int data,int position){
  struct node* temp=(*head_ref);
  struct node* current=temp;
  struct node* parent=temp;
  int count=0;
  if(position==0){
    if(temp==NULL){
      return createnode(data);
    }
    else{
      struct node* newnode=createnode(data);
      newnode->next=(*head_ref);
      (*head_ref)=newnode;
  }
}
  else{
  if(temp==NULL){
    return createnode(data);
  }
  else{
    struct node* newnode=createnode(data);
    while(current->next){
        parent=current;
        current=current->next;
        if(count==position){
            parent->next=newnode;
            newnode->next=current;
        }
        count++;
    }
    if(position>=count){
      current->next=newnode;
    }
}
  return temp;
}
}
void delete(struct node** head_ref,int number ){
  struct node* temp=(*head_ref);
  struct node* current=temp;
  struct node* parent;
  int count=0;
while(current){
  if(count==0 && current->data==number){
    *head_ref=temp->next;
    break;
  }
  while(current->data!=number){
    parent=current;
    current=current->next;
    if(current==NULL){
      printf("Element not found\n");
      break;
    }
  }
  parent->next=current->next;
  break;

}
}


void Traverse(struct node** head_ref){
  struct node* temp=(*head_ref);
  while(temp){
    printf("%d->",temp->data);
    temp=temp->next;
  }
  printf("NULL\n");
}

void main(){
  struct node* head=NULL;
  int no,choice,number,position;
  while(1){
  printf("1. Insert 2. Delete 3. Traverse");
  scanf("%d",&choice);
  switch(choice){

    case 1: printf("Enter the position to insert:");
            scanf("%d",&position);
            printf("\nEnter the element to insert");
            scanf("%d",&number);
            if(head==NULL){
            head=insert(&head,number,position);
            }
            else{
              insert(&head,number,position);
            }
            break;

    case 2: printf("Enter the element to delete");
            scanf("%d\n",&no);
            delete(&head,no);
            break;

    case 3:Traverse(&head);
            break;

    default: printf("Invalid choice" );

  }
}
  }
