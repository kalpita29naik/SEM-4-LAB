#include<stdio.h>
#define inf 999
int n;
void fgraph(int G[n+1][n+1],int k,int p[n+1],int c[n+1][n+1]);

int main()
{
  int v,o,d,cost,p[n],k;
  printf("Enter the number of vertices: ");
  scanf("%d",&n);
  printf("Enter the number of paths: ");
  scanf("%d",&v);
  int G[n+1][n+1],c[n+1][n+1];
  for(int i = 0;i <= n;i++)
  {
    for(int j = 0;j < n;j++)
    {
      G[i][j] = 0;
      c[i][j] = 0;
    }
  }

  printf("Enter the paths and cost:");
  for(int i = 0;i < v;i++)
  {
    scanf("%d%d%d",&o,&d,&cost);
    G[o][d] = 1;
    c[o][d] = cost;
  }
 
  printf("Enter the number of stages: ");
  scanf("%d",&k);
  fgraph(G,k,p,c);
}

void fgraph(int G[n+1][n+1],int k,int p[n+1],int c[n+1][n+1])
{
  int cost[n+1],d[n+1],min,r,j;
  cost[n] = 0;
  for(j = n-1;j >= 1;j--)
  {
    min = inf;
    for(r = j + 1;r <= n;r++)
    {
      if(G[j][r] != 0 && c[j][r] + cost[r] < min)
      {
        min = c[j][r] + cost[r];
        d[j] = r;
      }
    }
    cost[j] = min;
  }
  p[1] = 1;
  p[k] = n;
  for(j = 2;j <= k-1;j++)
  {
    p[j] = d[p[j-1]];
  }
  printf("The cost is: %d",cost[1]);
  printf("The path is: ");
  int u=1;
  for(j = 1;j < k;j++)
  {
    printf("p[%d] = %d \n",u,d[u]);
    u = d[u];
  }
}
