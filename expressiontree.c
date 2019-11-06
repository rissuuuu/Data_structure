#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
char a[50];
struct expt{
  char value;
  struct expt *left,*right;
};
struct stack{
  struct expt* t;
  struct stack* next;
};struct stack* top=NULL;struct stack* top2=NULL;struct stack* added=NULL;

void push(struct stack** head,struct expt* tree){
struct stack* temp=(struct stack*)malloc(sizeof(struct stack));
temp->t=tree;
temp->next=(*head);
(*head)=temp;
}
struct expt* pop(struct stack** head){
  struct expt* result;
if(*head==NULL){
  getchar();
  exit(0);
}
else{
top=(*head);
result=top->t;
(*head)=top->next;
free(top);
return result;
}
}
struct expt* newnode(char v){
  struct expt* temp=(struct expt*)malloc(sizeof(struct expt));
  temp->value=v;
  temp->left=NULL;
  temp->right=NULL;
  return temp;
}
bool isOperator(char c){
  if(c=='+' || c=='-'|| c=='*' || c=='/' || c=='^')
    return true;
  else
    return false;
}
void infix( struct expt* tree){
  if(tree==NULL)
    return;
  infix(tree->left);
  printf("%c ",tree->value);
  push(&added,tree);
  infix(tree->right);
}
void postfix(struct expt* tree){
  if(tree==NULL)
    return;
  postfix(tree->left);
  postfix(tree->right);
  printf("%c ",tree->value);
}
struct expt* construct(char postfix[]){
struct stack* st=NULL;
struct expt * t,*t1,*t2;

for(int i=0;i<strlen(postfix);i++){
    if(!isOperator(postfix[i])){
      t=newnode(postfix[i]);
      push(&st,t);
    }
    else{
      t=newnode(postfix[i]);
      t1=pop(&st);
      t2=pop(&st);

      t->right=t1;
      t->left=t2;
      push(&st,t);
    }
}
t=pop(&st);
if(&st!=NULL)
  return t;
else
  printf("No solution found\n");
}
void main(){
  char conct[100];
  char postf[]="ab+cde+**";
  char postf2[]="ab+cdef**g+h-i/+";
  int valof[50],total=0, i=0,s=0,ints[50];
  char els[50];
  char symbols[50];
  char newel[50];
  char c;
  struct expt* r=construct(postf);
  struct expt* elements;
  printf("\n");
  infix(r);
  printf("\n");
  postfix(r);
  printf("\n" );
  while(added){
    elements=pop(&added);
    if(elements=='\0')
      break;
    els[i]=elements->value;
    i++;
  }
    for(int j=i-1;j>=0;j--){
    newel[s]=els[j];
    s++;
  }
  printf("\n Elements in stacks\n" );
    for(int i=0;i<s;i++){
      c=newel[i];
      //printf("%c ",c);
      if(!(c=='+' || c=='-'|| c=='*' || c=='/' || c=='^')){
      printf("Enter value for %c : ",newel[i]);
      scanf("%d",&valof[i]);
      ints[i]=valof[i];
      printf("%d",ints[i]);
      itoa(ints[i],conct,100);
    }
    else{
        symbols[i]=c;
        }
    }

    for(int i=0,j=1;i<=s,j<=s;i++,j++){
      char val=ints[i];

      printf("%d%c",ints[i],symbols[j] );
      if(symbols[j]=='+')
        total=total+ints[i]+ints[i+2];
      if(symbols[j]=='-')
        total=total+ints[i]-ints[i+2];
      if(symbols[j]=='*')
        total=total+ints[i]*ints[i+2];
      if(symbols[j]=='/')
        total=total+ints[i]/ints[i+2];
      if(symbols[j]=='^')
        total=total+ints[i]+ints[i+2];
      i++;
      j++;
    }
    printf("%s\n",conct );
    printf("\n%d",total );
}
