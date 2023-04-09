#include<stdio.h>
void BellmanFord(int n,int cost[n][n],int v,int dist[n]);

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
   {
    cost[i][j]=0;
   }
   else
   {
    cost[i][j]=999;
   } 
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
 {
  dist[i]=cost[v-1][i];
 }
 for(k=0;k<n;k++)
 {
  for(i=0;i<n;i++)
  {
   for(j=0;j<n;j++)
   {
    if(dist[j]>dist[i]+cost[i][j])
    {
     dist[j]=dist[i]+cost[i][j];
    }
   }
  }
  /*printf("The distance matrix after %d iteration is:\n",k+1);
  for(i=0;i<n;i++)
  {
   printf("%d -> %d => %d",v,i+1,dist[i]);
   printf("\n");
  }*/

 }
 printf("The final distance matrix is:\n");
 for(i=0;i<n;i++)
 {
  printf("%d -> %d => %d",v,i+1,dist[i]);
  printf("\n");
}
}
