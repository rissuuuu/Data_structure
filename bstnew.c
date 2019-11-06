#include<stdio.h>
#include<stdlib.h>

typedef struct BST{
	int val;
	struct BST *left,*right;
}BST;



typedef struct stack{
	BST* val;
	struct stack *next;
}stack;

void push(stack** top,BST* val)
{
	stack* temp = (stack*)malloc(sizeof(stack));
	temp->val = val;
	temp->next = NULL;
	if((*top) == NULL)
		(*top) = temp;
	else
	{
		temp->next = (*top);
		(*top) = temp;
	}
}
BST* pop(stack** top)
{
	if((*top) == NULL)
		return NULL;
	stack *temp = (*top);
	(*top) = (*top)->next;
	return temp->val;
}

BST* Create_new(int val)
{
	BST *temp = (BST*)malloc(sizeof(BST));
	temp->val = val;
	temp->left = temp->right = NULL;
	return temp;
}
BST* Insert(BST* root,int val)
{
	if(root == NULL)
		return Create_new(val);
	if(val <= root->val)
		root->left = Insert(root->left,val);
	else if(val > root->val)
		root->right = Insert(root->right,val);
}

void inorder(BST* root)
{
	if(root == NULL)
		return;
	stack *top = NULL;
	BST *temp = root;
	while(temp != NULL || top!= NULL)
	{
		while(temp != NULL)
		{
			push(&top,temp);
			temp = temp->left;
		}
		temp = pop(&top);
		printf("%d ->",temp->val);
		temp = temp->right;
	}
	printf("NULL");
}

void preorder(BST *root)
{
	if(root == NULL)
		return;
	stack *top = NULL;

	push(&top,root);
	while(top !=NULL)
	{
		BST *temp = pop(&top);
		printf("%d ->",temp->val);
		if(temp->right)
			push(&top, temp->right);
		if(temp->left)
			push(&top, temp->left);
	}
	printf(" NULL");
}

BST* top_show(stack* top)
{
	if(top == NULL)
		return NULL;
	return top->val;
}

void postorder(BST *root)
{
	if(root == NULL)
		return;
	stack *top = NULL;
	BST *temp=root;

	do{
		while(temp!=NULL)
		{
			if(temp->right)
				push(&top,temp->right);
			push(&top,temp);
			temp=temp->left;
		}
		temp=pop(&top);
		if(temp->right && temp->right==top_show(top))
		{
			pop(&top);
			push(&top,temp);
			temp=temp->right;
		}
		else
		{
			printf("%d ->",temp->val);
			temp=NULL;
		}


	}while(top!=NULL);
	printf("NULL");

}

int height(BST *root)
{
	if(root == NULL)
		return 0;
	else{
		int lh=0;
		int rh=0;
		lh=1+height(root->left);
		rh=1+height(root->right);
		if(lh>rh)
			return(lh);
		else
			return(rh);
	}
}



int main()
{	BST* root = NULL;
	int choice,val,h;
	while(1)
	{
		printf("========Menu======== ");
		printf("\n1.Insert\n2.Inorder\n3.PreOrder \n4.Postorder\n5.Height of Tree\n6.Exit\nEnter choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: {
					printf("Enter value to add \n");
					scanf("%d",&val);
					root = Insert(root,val);
					break;
				}
			case 2: {
					printf("---------------------------\n");
					printf("Inorder: ");
					inorder(root);
					printf("\n---------------------------\n");

					break;
				}

			case 3: {
					printf("---------------------------\n");
					printf("\nPreorder: ");
					preorder(root);
					printf("\n---------------------------\n");
					break;
				}
			case 4:{
					printf("---------------------------\n");
					printf("\nPostorder: ");
					postorder(root);
					printf("\n---------------------------\n");
					break;
				}
			case 5:{
					printf("---------------------------\n");
					h=height(root);
					printf("\nHeight of TREE: %d\n",h);
					printf("\n---------------------------\n");
					break;

			}
			case 6:{
					printf("\n\n----------THANK YOU-------------\n\n");
					exit(0);

			}
			default: printf("Error: Wrong choice\n");
		}
	}

	return 0;
}
