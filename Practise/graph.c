#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* next;
};
struct graph{
  int vertices;
  struct node** adjlist;
};
struct node* createnode(int data){
struct node* newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=data;
newnode->next=NULL;
return newnode;
}

struct graph* creategraph(int v){
  struct graph* grap=(struct graph*)malloc(sizeof(struct graph));
  grap->vertices=v;
  grap->adjlist=malloc(v*sizeof(struct node));
for(int i=0;i<v;i++){
  grap->adjlist[i]=NULL;
}
return grap;
}

void addEdge(struct graph* g, int src,int dest){
struct node* newnode=createnode(dest);
newnode->next=g->adjlist[src];
g->adjlist[src]=newnode;
newnode=createnode(src);
newnode->next=g->adjlist[dest];
g->adjlist[dest]=newnode;
}

void printGraph(struct graph* g){
struct node* temp;
for(int i=0;i<g->vertices;i++){
  temp=g->adjlist[i];
  printf("Vertex %d->",i);

  while(temp){
    printf("%d->",temp->data);
    temp=temp->next;
  }
  printf("\n");
}
}

void main(){
struct graph* graph;
int no_vertices,edges,src,dest;
printf("Enter number of vertices");
scanf("%d",&no_vertices);
graph=creategraph(no_vertices);

printf("Enter number of edges");
scanf("%d",&edges);

for(int i=0;i<edges;i++){
  printf("Enter src and dest");
  scanf("%d%d",&src,&dest);
  addEdge(graph,src,dest);

}
printGraph(graph);

}
