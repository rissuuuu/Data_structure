#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node* left;
  struct node* right;
}; struct node* root=NULL;struct node* mains=NULL;


struct stacknode{
  struct node* t;
  struct stacknode* link;
}; struct stacknode* top=NULL;

//void insert(struct node* head,int data);
void push(struct stacknode** head_ref,struct node* t);
void Inorder(struct node* head);
void PostOrder(struct node* head);
void Preorder(struct node* head);

struct node* create(int data){
struct node* temp=(struct node*)malloc(sizeof(struct node));
temp->data=data;
temp->left=NULL;
temp->right=NULL;
return temp;

}

struct node* insert(struct node* root,int data){

struct node* temp=(struct node*)malloc(sizeof(struct node));
temp=create(data);
if(root==NULL){
  return create(data);
}
struct node* current=root;
struct node* parent=NULL;
while(current){
  parent=current;
  if(data<current->data){
    current=current->left;
  }
  else{
    current=current->right;
  }
}
  if(data<parent->data){
    parent->left=temp;
  }

  else{
    parent->right=temp;
  }
return root;
}

void push(struct stacknode** head_ref,struct node* t){
struct stacknode* temp;
temp=(struct stacknode*) malloc(sizeof(struct stacknode));

temp->t=t;
temp->link=(*head_ref);
(*head_ref)=temp;

}

struct node* pop(struct stacknode**head_ref){
struct node* res;
struct stacknode* top;
if((*head_ref)==NULL){
  getchar();
  exit(0);
}
else{
  top=(*head_ref);
  res=top->t;
  (*head_ref)=top->link;
  free(top);
  return res;
}


}
void Inorder(struct node* root){
struct node* current=root;
struct stacknode* s=NULL;
while(1){
while(current){
  push(&s,current);
  current=current->left;
}
if(s==NULL)
break;
current=pop(&s);
printf("%d->",current->data );
current=current->right;
}
}

void PostOrder(struct node* root){
struct stacknode* s=NULL;
struct node* current=root;
struct node* holdroot=NULL;
while(1){
while(current){
  push(&s,current);
  current=current->left;
}

current=pop(&s);
printf("%d->",current->data );
if(holdroot)
printf("%d->",holdroot->data );


  printf("%d Main root",mains->data );

if(s==NULL)
  break;

if(current->right!=NULL){
  current=current->right;
}
else{
  current=pop(&s);
  holdroot=current;
}
current=current->right;
}
}

void Preorder(struct node* root){
  struct stacknode* s=NULL;
  struct node* current=root;
  while(1){
    while(current){
    push(&s,current);
    printf("%d->",current->data );
    current=current->left;
    }
    if(s==NULL)
      break;
    current=pop(&s);
    current=current->right;

}
}


void main(){
mains=create(10);
root=mains;
insert(root,3);
insert(root,15);
insert(root,1);
insert(root,5);
insert(root,12);
insert(root,20);
Inorder(root);
printf("\n" );
Preorder(root);
printf("\n" );

PostOrder(root);



}
