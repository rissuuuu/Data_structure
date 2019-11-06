#include<stdio.h>
#include<stdlib.h>
	struct Node{
	int data;
	struct Node* left;
	struct Node* right;

};struct Node* root=NULL;

struct stacknode{
	int data;
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
	if(root==NULL){
		return create(element);
	}
	if(element<root->data){
				root->left=insert(root->left,element);
	}
	else{
		root->right=insert(root->right,element);
	}
	return root;
}

struct Node* traverse(struct Node* root){
	if(root==NULL)
		return NULL;
	root->left=traverse(root->left);
	printf("%d->",root->data);
	root->right=traverse(root->right);
}


void push();
struct Node* pop(struct Node* top);
int isEmpty();

int isEmpty(top){

	if(top==NULL)
		return 1;
	else
		return 0;
}

void inOrder(struct Node* root){
	struct node* current=root;
	while(1){
		while(current){
			push(current);
			current=current->left;
		}
		if(isEmpty())
			break;
		current=pop();
		print(current->data);
		current=current->right;
	}


void push(struct stacknode* pushed){
	struct stacknode* temp;
	temp=(struct stacknode*)malloc(sizeof(struct stacknode));
	temp->data=pushed->data;
	printf("%d",temp->data));
	temp->link=top;
	top=temp;
}

void pop(){
	struct stacknode* temp;
	temp=top;
	printf("%d",temp->data);
	top=top->link;
	top->link=NULL;
	free(temp);
}












}












int main(){
	root=insert(root,20);
	insert(root,10);
	insert(root,45);
	traverse(root);
	printf("Null\n");
	return 0;
}
