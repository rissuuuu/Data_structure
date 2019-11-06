#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* prev;
  struct node* next;
};
void printGraph(struct node*);
struct node* createNode(int element){
  struct node* newnode=(struct node*)malloc(sizeof(struct node));
  newnode->data=element;
  newnode->prev=NULL;
  newnode->next=NULL;
}

struct node* insert(struct node** head,int element){
  struct node* temp=*head;
  struct node* newnode;
  if(temp==NULL)
    return createNode(element);
  while(temp->next){
    temp=temp->next;
  }
  newnode=createNode(element);
  temp->next=newnode;
  newnode->prev=temp;
  return temp;
}

struct node* insertfirst(struct node** head,int element){

  struct node* newnode=createNode(element);
  newnode->next=*head;
  newnode->prev=NULL;
  (*head)->prev=newnode;
  (*head)=newnode;
  return (*head);

}

struct node* insertatpos(struct node** head,int element,int pos){
  int count=0;
  struct node* temp=(*head);
  struct node* parent=temp;
  struct node* current=temp;
  struct node* newnode=createNode(element);
  if(pos==0){
    insertfirst(head,element);
  }
  else{
    while(parent->next){
      parent=parent->next;

      if(count==pos){
        current->next=newnode;
        newnode->prev=current;
        newnode->next=parent;
        parent->prev=newnode;
      }
      //if(position){
        //printf("Position out of exceed");
      //}
      count++;
      current=current->next;
    }
    if(pos==count && parent==current){
      parent->next=newnode;
      newnode->prev=parent;
    }
    if(pos>count){
      printf("Position out of exceed\n");
    }
  }
  return temp;

}
struct node* deleteFirst(struct node** head){

struct node* temp=(*head);
if(temp!=NULL){
struct node* temp2;
temp2=temp->next;
temp2->prev=NULL;
(*head)=temp2;
}
else{
  printf("Cannot delete empty list");
}
return temp;

}

struct node* deleteatpos(struct node** head, int delelement){
struct node* temp=(*head);
struct node* current=temp;
struct node* parent=temp;
struct node* joinnode;
int count=0;

  if(temp!=NULL && temp->data==delelement){
      current=temp->next;
      current->prev=NULL;
      (*head)=current;
      return temp;
  }
while(current!=NULL && current->data!=delelement){
    parent=current;
    current=current->next;
}
if(current==NULL){
  printf("element not found\n");
  return temp;
}
if(current->next!=NULL){
  joinnode=current->next;
  parent->next=joinnode;
  joinnode->prev=parent;
}
else{
  parent->next=NULL;
  free(current);
}
return temp;
}

struct node* deleteLast(struct node** head){
struct node* temp=(*head);
struct node* temp3;
struct node* current=temp;
struct node* parent;
if(temp!=NULL){
while(current){
  temp3=current;
  current=current->next;
}
printf("%d\n",temp3->data);
parent=temp3->prev;
printf("%d\n",parent->data);
parent->next=NULL;
}
else{
  printf("Cannot delete empty list");
}
return temp;



}


void printGraph(struct node* head){
  while(head){
    printf("%d->",head->data );
    head=head->next;
  }
  printf("\n");
}

void reverseGraph(struct node* head){
struct node* temp=head;
struct node* temp2;
while(temp->next){
  temp=temp->next;
}
temp2=temp;
while(temp2){
  printf("%d->",temp2->data );
  temp2=temp2->prev;
}
printf("\n");
}





void main(){
  int choice, data,position,pos,choicedel,choicepos;
  struct node* head=NULL;
  while(1){
  printf("Enter 1. Insert 2. Delete 3. Traverse 4. reverseGraph Enter your choice:");
  scanf("%d",&choice);
  switch(choice){
    case 1: printf("1. Insert last 2. insert begining 3. insert after pos Enter choice:");
            scanf("%d",&position);
            switch(position){
              case 1:if(head==NULL){
                printf("\nEnter the element to insert:");
                scanf("%d",&data );
                head=insert(&head,data);
                }
              else{
                printf("\nEnter the element to insert:");
                scanf("%d",&data );
                insert(&head,data);
              }
              break;

              case 2:if(head==NULL){
                printf("\nEnter the element to insert:");
                scanf("%d",&data );
                head=insert(&head,data);
                }
              else{
                printf("\nEnter the element to insert:");
                scanf("%d",&data );
                insertfirst(&head,data);
              }

              break;

              case 3:if(head==NULL){
                printf("\nEnter the element to insert:");
                scanf("%d",&data );
                head=insert(&head,data);
                }
              else{
                printf("Enter position to insert:");
                scanf("%d",&pos );
                printf("\nEnter the element to insert:");
                scanf("%d",&data );
                insertatpos(&head,data,pos);
              }
              break;

              default: printf("Invalid choice");
            }

            break;
    case 2: printf("1.Delete First 2.Delete particular element 3.Delete Last");
            scanf("%d",&choicedel);
            switch(choicedel){
              case 1: deleteFirst(&head);
                      break;

              case 2: printf("Enter the element to delete");
                      scanf("%d",&choicepos);
                      deleteatpos(&head,choicepos);
                      break;

              case 3: deleteLast(&head);
                      break;

              default: printf("Invalid choice");
            }
            break;

    case 3: printGraph(head);
            break;
    case 4: reverseGraph(head);
            break;

    default:  printf("Invalid choice\n");


  }

}
}
