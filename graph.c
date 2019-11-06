#include<stdio.h>
#include<stdlib.h>
struct newAdjacent{
  int data;
  struct newAdjacent* next;
};

struct edges{
  struct newAdjacent* head;
};
struct  Graph{
  int vertices;
  struct edges* array;
};

struct newAdjacent* create(int data){
  struct newAdjacent* newnode=(struct newAdjacent*)malloc(sizeof(struct newAdjacent));
  newnode->data=data;
  newnode->next=NULL;
  return newnode;
}

struct Graph* newGraph(int v){
  struct Graph* graph=(struct Graph*)malloc(sizeof(struct Graph));
  graph->vertices=v;
  graph->array=(struct edges*)malloc(v*sizeof(struct edges));
  int i;
  for(i=0;i<v;i++){
    graph->array[i].head=NULL;
  }
return graph;
}

void addEdge(struct Graph* graph, int src,int dest){
  struct newAdjacent* newnode=create(dest);
  newnode->next=graph->array[src].head;
  graph->array[src].head=newnode;
  newnode=create(src);
  newnode->next=graph->array[dest].head;
  graph->array[dest].head=newnode;
}

void printGraph(struct Graph* graph,int v){
  int i;
  for(i=0;i<v;i++){
    struct newAdjacent* temp=graph->array[i].head;
    printf("\n Adjacency list of vertex %d\n head",i );
    while(temp){
      printf("-> %d",temp->data );
      temp=temp->next;
    }
    printf("\n" );
  }
}

















void main(){
  int v=5;
  struct Graph* graph=newGraph(v);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 4);
  addEdge(graph, 1, 2);
  addEdge(graph, 1, 3);
  addEdge(graph, 1, 4);
  addEdge(graph, 2, 3);
  addEdge(graph, 3, 4);
  printGraph(graph,v);
}
