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
   int numVertices;
   struct node** adjLists;
   int* visited,*visited2;
 };
struct queue* createQueue();
void enqueue(struct queue* q, int);
int dequeue(struct queue* q);
void display(struct queue* q);
int isEmpty(struct queue* q);
void printQueue(struct queue* q);
void DFS(struct graph*, int);



void addEdge(struct graph* g,int src,int dest);
void printGraph(struct graph* g);
void bfs(struct graph* g, int startvertex);

struct node* createNode(int v){
  struct node* newNode=(struct node*)malloc(sizeof(struct node));
  newNode->vertex=v;
  newNode->next=NULL;
  return newNode;
}

struct graph* createGraph(int vertices){
  struct graph* g=malloc(sizeof(struct graph));
  g->numVertices=vertices;

  g->adjLists=malloc(vertices*sizeof(struct node*));
  g->visited=malloc(vertices*sizeof(int));
  g->visited2 = malloc(vertices * sizeof(int));
  int i;
  for(i=0;i<vertices;i++){
    g->adjLists[i]=NULL;
    g->visited[i]=0;
    g->visited2[i]=0;
  }
  return g;
}
void addEdge(struct graph* g, int src, int dest){
  struct node* newNode=createNode(dest);
  newNode->next=g->adjLists[src];
  g->adjLists[src]=newNode;

  newNode=createNode(src);
  newNode->next=g->adjLists[dest];
  g->adjLists[dest]=newNode;

}
void printgraph(struct graph* g){
  int i;
  struct node* temp;
  for(i=0;i<g->numVertices;i++){
    temp=g->adjLists[i];
    printf("%d->",i);
    while(temp){
      printf("%d->",temp->vertex);
      temp=temp->next;
    }
    printf("\n");
  }
}

struct queue* createQueue(){
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
  printf("\nQueue full\n");
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
    printf("Queue is empty");
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
    printf("Queue empty\n");
  else{
    printf("Queue Contains\n");
    for(i;i<q->rear+1;i++){
      printf("%d ",q->items[i]);
    }
  }
}



void bfs(struct graph* g, int start){
  struct queue* q=createQueue();
  g->visited[start]=1;
  enqueue(q,start);
  while(!isEmpty(q)){
    printQueue(q);
    int currentVertex=dequeue(q);
    printf("\nVisited %d\n-------------\n",currentVertex);

    struct node* temp=g->adjLists[currentVertex];
    while(temp){
      int adjvertex=temp->vertex;
      if(g->visited[adjvertex]==0){
        g->visited[adjvertex]=1;
        enqueue(q,adjvertex);
      }
      temp=temp->next;
    }
  }

}


void DFS(struct graph* graph, int vertex) {
        struct node* adjList = graph->adjLists[vertex];
        struct node* temp = adjList;

        graph->visited2[vertex] = 1;
        printf("Visited %d \n", vertex);

        while(temp!=NULL) {
            int connectedVertex = temp->vertex;

            if(graph->visited2[connectedVertex] == 0) {
                DFS(graph, connectedVertex);
            }
            temp = temp->next;
        }
}



void main(){
  struct graph* graph=createGraph(9);

  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 3);
  addEdge(graph, 1, 0);
  addEdge(graph, 1, 2);
  addEdge(graph, 1, 4);
  addEdge(graph, 2, 0);
  addEdge(graph, 2, 1);
  addEdge(graph, 2, 3);
  addEdge(graph, 2, 4);
  addEdge(graph, 2, 8);
  addEdge(graph, 3, 0);
  addEdge(graph, 3, 2);
  addEdge(graph, 3, 6);
  addEdge(graph, 4, 1);
  addEdge(graph, 4, 2);
  addEdge(graph, 4, 8);
  addEdge(graph, 4, 6);
  addEdge(graph, 8, 2);
  addEdge(graph, 8, 4);
  addEdge(graph, 8, 4);
  addEdge(graph, 6, 3);
  addEdge(graph, 6, 8);
  addEdge(graph, 6, 4);

  bfs(graph, 2);
  printf("\n");
  DFS(graph,2);
  //printf("\n\nThe elements of graphs are\n");
  //printgraph(graph);

}
