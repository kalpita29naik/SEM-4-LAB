//3d.Bellman Ford Algorithm
#include<stdio.h>
void BellmanFord(int n,int cost[n][n],int v,int dist[n]);
void print(int n,int dist[n]);

int main(void)
{
 int n,o,d,c,e,v;
 printf("Enter the number of vertices: ");
 scanf("%d",&n);
 printf("Enter the number of edges :");
 scanf("%d",&e);
 int cost[n][n];
 for(int i=0;i<n;i++)
 {
  for(int j=0;j<n;j++)
  {
   if(j==0)
   { cost[i][j]=0;  }
   else
   { cost[i][j]=999;  } 
  }
 }
 printf("Enter the paths and cost:\n");
 for(int i=0;i<e;i++)
 {
  scanf("%d %d %d",&o,&d,&c);
  cost[o-1][d-1]=c;
 }
  printf("Enter the starting vertex: ");
  scanf("%d",&v);
  int dist[n];
  BellmanFord(n,cost,v,dist);
}

void BellmanFord(int n,int cost[n][n],int v,int dist[n])
{
 int i,j,k;
 for(i=0;i<n;i++)
 { dist[i]=cost[v-1][i]; }
 printf("dist(k)\t");
 for (i=1;i<=n;i++)
 { printf("%d\t",i); }
 printf("\n");
 printf("1\t");
 print(n,dist);
 for(k = 0;k < n - 2;k++)
 {
  for(i = 0;i < n;i++)
  {
   for(j = 0;j < n;j++)
   {
    if(dist[j] > dist[i] + cost[i][j])
    { dist[j] = dist[i] + cost[i][j]; }
   }
  }
  printf("%d\t",k+2);
  print(n,dist);
 }
}

void print(int n, int dist[n])
{
 for(int i = 0;i < n;i++)
 { printf("%d\t",dist[i]);}
 printf("\n");
}