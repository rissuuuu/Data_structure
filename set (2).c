#include <stdio.h>
#include <stdlib.h>

typedef struct set{
	int val;
	struct set* next;
}set;

void swap( set* a, set* b)
{
	int temp=a->val;
	a->val = b->val;
	b->val = temp;
}

int isPresent(set* head, int key)
{
	int flag=0;
	while(head!=NULL)
	{
		if(head->val==key){
			flag=1;
			return flag;	
		}
		head=head->next;
	}
	return flag;
}


set* create_new(int val)
{
	set* temp = (set*)malloc(sizeof(set));
	temp->val=val;
	temp->next = NULL;
	return temp;
}


set* add(set* head, int val)
{
	if(head == NULL)
		return create_new(val);
	if(!isPresent(head,val)){
	set* new=(set*)malloc(sizeof(set));
	new->val=val;
	new->next=head;
	head=new;
	}
	else
		printf("Duplicate");
	return head;
}

set* delete(set* head,int key)
{
	set* temp = head, *prev;
	if(temp!= NULL && temp->val == key){
		head = temp->next;
		return head;
	}	
	
	while(temp!=NULL && temp->val != key){
		prev = temp;
		temp = temp->next;	
	}
	if(temp == NULL)
		return head;
	prev->next = temp->next;
	return head; 
}

void bubblesort(set* head){
	int swapped, i;
	set* ptr1;
	set* lptr = NULL;

	if(head == NULL)
		return;
	do{
		swapped = 0;
		ptr1 = head;
		while(ptr1->next != lptr)
		{
			if(ptr1->val > (ptr1->next)->val)
			{
				swap(ptr1,ptr1->next);
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;

	}while(swapped);
}

set* Union(set* head1, set* head2)
{
	set* temp1=head1;
	set* temp2=head2;
	set* result=NULL;
	while(temp1!=NULL){
		result=add(result,temp1->val);
		temp1=temp1->next;	
	}
	
	while(temp2!=NULL){
		if(!isPresent(result,temp2->val))
			result=add(result,temp2->val);
		temp2=temp2->next;
	}
	return result;
}

set* Intersection(set* head1, set* head2)
{
	set* temp1 = head1;
	set* result = NULL;
	while(temp1 != NULL){
		if(isPresent(head2,temp1->val))
			result=add(result,temp1->val);
		temp1=temp1->next;
	}
	return result;

}



void display(set* head)
{
	printf("{ ");
	if(head == NULL)
		printf("NULL");
	while(head!=NULL)
	{
		printf("%d, ",head->val);
		head=head->next;
	}
	printf("}\n");

}


int main()
{
	set* head1 = NULL;
	set* head2 = NULL;
	set* result = NULL;
	set* result2 = NULL;	
	char ch;
	int choice;
	int temp;
	/*head1=add(head1,10);
	head1=add(head1,15);
	head1=add(head1,20);
	head1=add(head1,25);
	head1=add(head1,30);
	head2=add(head2,10);
	head2=add(head2,15);
	head2=add(head2,20);
	head2=add(head2,30);
	head2=add(head2,50);
	head1=delete(head1,20);
	head1=delete(head1,10);
	bubblesort(head1);
	bubblesort(head2);
	display(head1);
	display(head2);
	result=Union(head1,head2);
	bubblesort(result);
	display(result);
	result2=Intersection(head1,head2);
	bubblesort(result2);
	display(result2);*/
	
	while(1)
	{
		printf("========Menu======== ");
		printf("\n1.Insert into SET1\n2.Insert into SET2\n3.Delete from SET1\n4.Delete from SET2 \n5.Display SET1\n6.Display SET2\n7.UNION\n8.INTERSECTION\n9.Exit\nEnter choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: {
					printf("\nSET1: Enter Integer to ADD: ");
					scanf("%d",&temp);
					head1 = add(head1,temp);
					bubblesort(head1);
					break;
				}
			case 2: {
					printf("\nSET2: Enter Integer to ADD: ");
					scanf("%d",&temp);
					head2 = add(head2,temp);
					bubblesort(head2);
					break;
				}

			case 3: {
					printf("\nSET1: Enter Integer to DELETE: ");
					scanf("%d",&temp);
					head1=delete(head1,temp);	
					break;
				}
			case 4: {
					printf("\nSET2: Enter Integer to DELETE: ");
					scanf("%d",&temp);
					head2 = delete(head2,temp);
					break;
				}
			case 5: {
					printf("\nSET 1: ");
					display(head1);
					break;
				}
			case 6: {
					printf("\nSET 2: ");
					display(head2);
					break;
				}
			case 7: {
					printf("\nUnion: ");
					result = Union(head1, head2);
					bubblesort(result);
					display(result);
					break;
				}
			case 8: {
					printf("\nIntersection: ");
					result2 = Intersection(head1, head2);
					bubblesort(result2);
					display(result2);
					break;
				}
			case 9: 
				exit(0);
			default: printf("Error: Wrong choice\n");
		}
	}
	
	return 0;
}