
#include<stdio.h>
#include<stdlib.h>
	struct Node{
	int data;
	struct Node* left;
	struct Node* right;

};struct Node* root=NULL;

struct stacknode{
	struct Node* t;
	struct stacknode* link;
};struct stacknode* top=NULL;




struct Node* create(int element){
	struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
 	newnode->data=element;
	newnode->left= NULL;
	newnode->right=NULL;
	return newnode;
}
struct Node* insert(struct Node* root, int element){
	struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
	temp=create(element);
	if(root==NULL){
		return create(element);
	}
	struct Node* current=root;
	struct Node* parent=NULL;
	while(current){
		parent=current;
	if(element<current->data){
		current=current->left;
	}
	else{
		current=current->right;
	}
	}
	if(element<parent-> data){
		parent->left=temp;
	}
	else{
		parent->right=temp;
	}
return root;
}

void push(struct stacknode** top_ref,struct Node* t);
struct Node* pop(struct stacknode** top_ref);
int isEmpty(struct stacknode* top);
void traverse(struct Node* root);

int isEmpty(struct stacknode* top){
	return (top==NULL)?1:0;
}

void inOrder(struct Node* root){
	struct Node* current=root;
	struct stacknode* s=NULL;
	while(1){
		while(current){
			push(&s,current);
			current=current->left;
		}
		if(isEmpty(s))
			break;
		current=pop(&s);
		printf("%d->"	,current->data);
		current=current->right;
	}
}
void preOrder(struct Node* root){
	struct  Node* current=root;
	struct stacknode* s=NULL;
		while(1){
		while(current){
			push(&s,current);
			printf("%d->",current->data);
			current=current->left;
		}
		if(isEmpty(s))
			break;
		current=pop(&s);

		if(current->left==NULL && current->right==NULL)
			if(isEmpty(s))
			break;
		current=pop(&s);
		current=current->right;

		}
		}

void postOrder(struct Node* root){
	struct Node* current=root;
	struct stacknode* s=NULL;
	struct Node* temp=NULL;
	while(1){
			while(current){
			push(&s,current);
			current=current->left;
			}
			if(isEmpty(s))
				break;
			current=pop(&s);

			printf("%d->",current->data);
			if(temp)
			printf("%d->",temp->data);

			if(current->left==NULL && current->right==NULL)
				if(isEmpty(s))
					break;
			if(current->right!=NULL){
			current=current->right;
			}
			else{
				current=pop(&s);
				temp=current;
			}
			current=current->right;
	}
}

void push(struct stacknode** top_ref,struct Node* t){
	struct stacknode* temp;
	temp=(struct stacknode*)malloc(sizeof(struct stacknode));
	temp->t=t;
	temp->link=(*top_ref);
	(*top_ref)=temp;
}

struct Node* pop(struct stacknode** top_ref){
	struct Node*res;
	struct stacknode* top;
	if(isEmpty(*top_ref))
	{
     printf("Stack Underflow \n");
     getchar();
     exit(0);
	}
	else{
		top=*top_ref;
		res=top->t;
		*top_ref=top->link;
		free(top);
		return res;
	}
}

void traverse(struct Node* root){
  while (root) {
    printf("%d\n",root->data );
    root=root->left;
  }
}
int main(){
	root=insert(root,20);
	insert(root,15);
	insert(root,10);
	insert(root,18);
	insert(root,5);
	insert(root,12);
	insert(root,25);
	insert(root,22);
	insert(root,27);
  traverse(root);
	printf("\n _______In Order________\n\n");
	inOrder(root);
	printf("\n\n _______Pre Order________\n\n");
	preOrder(root);
	printf("\n\n _______Post Order________\n\n");
	postOrder(root);
	printf("\n");
	return 0;
}
