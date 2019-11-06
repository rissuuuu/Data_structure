#include <stdio.h>
#include <stdlib.h>

struct list
{
	char data;
	struct list *next;
}*top1, *top2, *top3;


void push(struct list **top, char value)
{
	struct list *new = (struct list *) malloc(sizeof(struct list));
	new->data=value;
	
	if(top == NULL){
		*top = new;
		new->next = NULL;
	}
	else
	{
		new->next=*top;
		*top=new;
	}
}

int pop(struct list **top)
{
	char data;	
	struct list *temp = *top;
	*top =(*top)->next;
	data=temp->data;
	free(temp);
	return data;
}

	

void display(struct list **top)
{
	struct list *temp;
	temp = *top;
	
	while(temp != NULL){
		printf("%c->",temp->data);
		temp=temp->next;	
	}
	printf("NULL\n");
}


void main()
{
	char *input=(char *)malloc(sizeof(char)*20);
	char *temp=(char *)malloc(sizeof(char)*20);
	char num,chr,num1,num2;
	int flag=0;
	int i=0,j=0;
	printf("Enter Input: ");
	while((chr=getchar()) != '\n')
	{
		input[i]= chr;
		i++;
	}
	temp=input;
	while(j<i){
		
			push(&top1,input[j]);
			push(&top2,input[j]);
		j++;
	}

	while(top2 != NULL){
		num=pop(&top2);
		push(&top3,num);
	}

	while(top3 != NULL){
		num1=pop(&top1);
		num2=pop(&top3);
		if(num1 != num2){
			flag=1;
		}	
	}
	
	if(flag==0)
		printf("\n%s  is a palindrome",input);
	else
		printf("\n%s is not a palindrome",input);

	
}
















