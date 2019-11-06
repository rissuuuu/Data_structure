#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct stack{
	int val;
	struct stack* next;
}stack;

int count(stack** top)
{
	int co=0;
	stack* temp = *top;
	while(temp != NULL){
		co++;
		temp=(temp)->next;
	}
	return co;
}

void push(stack** top,int val)
{
	stack* temp = (stack*)malloc(sizeof(stack));
	temp->val = val;
	temp->next = NULL;
	if(*top == NULL)
	{
		*top = temp;
	}
	else
	{
		temp->next = *top;
		*top = temp;
	}
}
int pop(stack** top)
{
	if(*top == NULL)
	return 0;
	stack* temp = *top;
	*top = (*top)->next;
	int val = temp->val;
	free(temp);
	return val;
}

void print_move(char from, char to, int disk)
{
	printf("\nMove disk %d from %c to %c",disk,from,to);
}
void move(stack** source,stack** dest,char s, char d)
{
	int temp1 = pop(source);
	int temp2 = pop(dest);
	if(temp1 == 0)
	{
		push(source,temp2);
		print_move(s,d,temp2);
	}
	else if(temp2 == 0)
	{
		push(dest,temp1);
		print_move(d,s,temp1);
	}
	else if(temp1 > temp2)
	{
		push(source,temp1);
		push(source,temp2);
		print_move(d,s,temp2);
	}
	else
	{
		push(dest,temp2);
		push(dest,temp1);
		print_move(s,d,temp1);
	}
}

void display(stack* source, stack* aux, stack* dest,int disks)
{
	int a[disks][3];
	int i=0,j=0;
	int numberofEle=0;
	stack *top1=source;
	stack *top2=aux;
	stack *top3=dest;

	for(i=0;i<disks;i++)
		for(j=0;j<3;j++)
			a[i][j]=0;

	numberofEle=count(&source);
	for(i=(disks-numberofEle);i<disks;i++){
		a[i][0]=top1->val;
		top1=(top1)->next;
	}
	numberofEle=count(&aux);
	for(i=(disks-numberofEle);i<disks;i++){
		a[i][1]=top2->val;
		top2=(top2)->next;
	}


	numberofEle=count(&dest);
	for(i=(disks-numberofEle);i<disks;i++){
		a[i][2]=top3->val;
		top3=(top3)->next;
	}

	printf("\n");




	for(i=0;i<disks;i++){
		for(j=0;j<3;j++){
			if(a[i][j] == 0)
				printf("  ");
			else
				printf("%d ",a[i][j]);
		}
	printf("\n");
	}
	printf("------");
	printf("\nA B C ");
}
void tower(stack* source,stack* aux,stack* dest,int disks)
{
	char s='A',a='B',d='C';
	if(disks%2 == 0)
	{
		char temp = a;
		a = d;
		d = temp;
	}
	int i,total_moves = pow(2,disks) - 1;
	for(i=disks;i>=1;i--)
	{
		push(&source,i);
	}
	for(i = 1;i<=total_moves;i++)
	{
		if(i%3 == 1)
		move(&source,&dest,s,d);
		else if(i%3 == 2)
		move(&source,&aux,s,a);
		else
		move(&aux,&dest,a,d);
		display(source,aux,dest,disks);
	}
	printf("\nTotal number of moves: %d",total_moves);
}


int main()
{
	int disks;
	printf("Enter no. of disks\n");
	scanf("%d",&disks);
	stack *source=NULL,*aux=NULL,*dest=NULL;
	tower(source,aux,dest,disks);
	printf("\n");
	return 0;
}
