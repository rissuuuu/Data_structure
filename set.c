

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


struct node{
	int data;
	struct node* next;
};

void push(struct node** head_ref,int new_data);
bool isPresent(struct node* head,int data);
void sort(struct node* head);

void push(struct node** head_ref,int data){
	struct node* check=(*head_ref);
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	if(!isPresent(check,data)){
	newnode->data=data;
	newnode->next=(*head_ref);
	(*head_ref)=newnode;
	}
}

void printList(struct node* node){
	while(node!=NULL){
		printf("%d ",node->data);
		node=node->next;
	}
}
bool isPresent(struct node* head,int data){
	struct node* t=head;
	while(t!=NULL){
		if(t->data==data)
			return 1;
		t=t->next;
	}
	return 0;
}
struct node* unions(struct node* head1,struct node* head2){
	struct node* result=NULL;
	struct node* t1=head1,*t2=head2;

	while(t1!=NULL){
		push(&result,t1->data);
		t1=t1->next;
	}
	while(t2!=NULL){
		if(!isPresent(result,t2->data))
			push(&result,t2->data);
		t2=t2->next;
	}
	return result;
}

struct node* intersection(struct node* head1,struct node* head2){
	struct node* result2=NULL;
	struct node* t1=head1;

	while(t1!=NULL){
		if(isPresent(head2,t1->data))
			push(&result2,t1->data);
		t1=t1->next;
	}
	return result2;
}

void sort(struct node* head){
	struct node* i;
	struct node* j;
	int temp;
	for(i=head;i!=NULL;i=i->next){
		for(j=i->next;j!=NULL;j=j->next){
			if(i->data>j->data){
				temp=i->data;
				i->data=j->data;
				j->data=temp;
			}
		}
		printf("%d ",i->data);
	}


}


int main(){
	struct node* head1=NULL;
	struct node* head2=NULL;
	struct node* get_intersection=NULL;
	struct node* get_unions=NULL;



	push(&head1,20);
	push(&head1,15);
	push(&head1,10);
	push(&head1,40);
	push(&head1,20);
	push(&head1,15);
	push(&head1,10);
	push(&head1,40);

	push(&head2,35);
	push(&head2,20);
	push(&head2,30);
	push(&head2,10);
	push(&head2,35);
	push(&head2,20);
	push(&head2,30);
	push(&head2,10);

	printList(head1);
	printf("\n------------\n");

	printList(head2);
	printf("\n--Union---\n");
	get_unions=unions(head1,head2);
	printList(get_unions);
	printf("\n---Intersection----\n");
	get_intersection=intersection(head1,head2);
	printList(get_intersection);
	printf("\n\nAfter Sorting\n" );
	printf("------------\n");
	sort(get_unions);
}
