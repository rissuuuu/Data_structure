#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct exp{
    char value;
    struct exp *left, *right;
};

struct stack{
    struct exp* t;
    struct stack* next;
};struct stack* top=NULL;

struct exp* create(char value){
    struct exp* newnode=(struct exp*)malloc(sizeof(struct exp));
    newnode->value=value;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
bool isOperator(char c){
    if(c=='+' || c=='-'||c=='/'||c=='*'||c=='^')
        return true;
    else
        return false;
}
void push(struct stack**head,struct exp* t){
    struct stack* temp=(struct stack*)malloc(sizeof(struct stack));
    temp->t=t;
    temp->next=(*head);
    (*head)=temp;


}
struct exp* pop(struct stack** head){
    struct exp* result;
    if(top==NULL){
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
struct exp* construct(char postf[]){
    struct stack* s=NULL;
    struct exp *t,*t1,*t2;
    for(int i=0;i<strlen(postf);i++){
        if(!isOperator(postf[i])){
            t=create(postf[i]);
            push(&s,t);
        }
        else{
            t=create(postf[i]);
            t1=pop(&s);
            t2=pop(&s);
            t->right=t1;
            t->left=t2;
            push(&s,t);

        }
        t=pop(&s);
        return(t);
    }
}
void infix(struct exp* tree){
    if(tree==NULL)
        return;
    infix(tree->left);
    printf("%c",tree->value);
    infix(tree->right);
}


void main(){
    char postf[]="ab+cde+**";
    struct exp* tree=construct(postf);
    infix(tree);

}
