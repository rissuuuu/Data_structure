#include<stdio.h>
#include<stdlib.h>
int min(int,int);
void flyod(int p[10][10],int n){
int from,to,via;
for(via=1;via<=n;via++){
  for(from=1;from<=n;from++){
    for(to=1;to<=n;to++){
      if(from==to)
        p[from][to]=0;
      else
        p[from][to]=min(p[from][to],p[from][via]+p[via][to]);
    }
  }
}



}
int min(int a,int b){
  if(a<b)
    return a;
  else
    return b;
}



void main(){
int p[10][10],v,e,i,j,from,to,weight;
printf("Enter number of vertices");
scanf("%d",&v);
printf("Enter number of edges");
scanf("%d",&e);
for(i=0;i<=v;i++){
  for(j=0;j<=v;j++){
    p[i][j]=999;
  }
}
printf("\nThe matrix for raw data:\n");
for(i=1;i<=v;i++){
  for(j=1;j<=v;j++){
    printf("%d  ",p[i][j]);
  }
  printf("\n");
}
for(i=1;i<=e;i++){
printf("\nEnter 'from vertex' and 'to vertex' and weight of it\n");
scanf("%d %d %d",&from,&to,&weight);
p[from][to]=weight;
}
printf("\nThe matrix for input data:\n");
for(i=1;i<=v;i++){
  for(j=1;j<=v;j++){
    printf("%d  ",p[i][j]);
  }
  printf("\n");
}

flyod(p,v);

printf("\nThe matrix after finding path\n");
for(i=1;i<=v;i++){
  for(j=1;j<=v;j++){
    printf("%d  ",p[i][j]);
  }
  printf("\n");
}

printf("\nShortest Paths\n");
for(i=1;i<=v;i++){
  for(j=1;j<=v;j++){
    printf("Path of <%d,%d> ->%d \n",i,j,p[i][j]);
  }
}


printf("\nEnter vertices to find the shortest path from two nodes\n");
scanf("%d%d",&from,&to);
printf("The shortest path from %d and %d is %d",from,to,p[from][to]);











}
