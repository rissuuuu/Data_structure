#include<stdio.h>
#include<stdlib.h>
#define size 40

struct queue{
  int items[size];
  int front;
  int rear;
};

struct node{
  int vertex;
  struct node* next;
};

struct graph{
  int no_vertices;
  struct node** adjlists;
  int *visited1,*visited2;
};
struct queue* createQ(){
struct queue* q=(struct queue*)malloc(sizeof(struct queue));
q->front=-1;
q->rear=-1;
return q;
}

int isEmpty(struct queue* q){
  if(q->rear==-1)
  return -1;
  else
  return 0;
}
void enqueue(struct queue* q, int value){
  if(q->rear==size-1)
  printf("Queue full");
  else{
    if(q->front==-1)
      q->front=0;
    q->rear++;
    q->items[q->rear]=value;

  }
}
int dequeue(struct queue* q){
  int item;
  if(isEmpty(q)){
    printf("Empty Queue");
    item=-1;
  }
  else{
    item=q->items[q->front];
    q->front++;
    if(q->front>q->rear){
      q->front=q->rear=-1;
    }
  }
  return item;
}
void printQueue(struct queue* q){
  int i=q->front;
  if(isEmpty(q))
  printf("Queue Empty");
  else{
    printf("\n Queue Contains ");
    for(i;i<q->rear+1;i++){
      printf("%d ",q->items[i]);
    }
  }
}
void BFS(struct graph *g,int start){
  struct queue* q=createQ();
  g->visited1[start]=1;
  enqueue(q,start);
  while(!isEmpty(q)){
    printQueue(q);
    int currentvertex=dequeue(q);
    printf("\n Visited %d",currentvertex);

    struct node* temp=g->adjlists[currentvertex];
    while(temp){
      int adjvertex=temp->vertex;
      if(g->visited1[adjvertex]==0){
        g->visited1[adjvertex]=1;
        enqueue(q,adjvertex);
      }
      temp=temp->next;

    }
  }

}

void DFS(struct graph* g,int start){
  struct node* adjlist=g->adjlists[start];
  struct node* temp=adjlist;
  g->visited2[start]=1;
  printf("Visited %d\n",start);
  while(temp!=NULL){
    int connectd=temp->vertex;
    if(g->visited2[connectd]==0){
      DFS(g,connectd);
    }
    temp=temp->next;
  }
}

struct node* createNode(int data){
  struct node* newnode=(struct node*)malloc(sizeof(struct node));
  newnode->vertex=data;
  newnode->next=NULL;
  return newnode;
}

struct graph* createGraph(int v){
struct graph* g=malloc(sizeof(struct graph));
g->no_vertices=v;
g->adjlists=malloc(v*sizeof(struct node));
g->visited1=malloc(v*sizeof(int));
g->visited2=malloc(v*sizeof(int));
for(int i=0;i<v;i++){
  g->adjlists[i]=NULL;
  g->visited1[i]=0;
  g->visited2[i]=0;
}
return g;
}

void addEdge(struct graph* g,int src, int dest){
  struct node* newnode=createNode(src);
  newnode->next=g->adjlists[dest];
  g->adjlists[dest]=newnode;

  newnode=createNode(dest);
  newnode->next=g->adjlists[src];
  g->adjlists[src]=newnode;
}


void printGraph(struct graph* g){
struct node* temp;
for(int i=0;i<g->no_vertices;i++){
  temp=g->adjlists[i];
  printf("%d->",i);
  while(temp){
    printf("%3d",temp->vertex);
    temp=temp->next;
  }
  printf("\n");
}

}

void main(){
  int v,e,src,dst;
  printf("Enter no of vertex");
  scanf("%d",&v);
  struct graph* graph=createGraph(v);
  printf("Enter number of edges");
  scanf("%d",&e);
  for(int i=0;i<e;i++){
    printf("Enter src and dest");
    scanf("%d%d",&src,&dst);
    addEdge(graph,src,dst);
  }
  printGraph(graph);
  BFS(graph,1);
  DFS(graph,1);
}
