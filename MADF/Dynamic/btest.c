#include<stdio.h>
#define inf 999
void bgraph(int n,int G[n+1][n+1],int k,int p[n+1],int c[n+1][n+1]);

int main()
{
  int n,v,o,d,cost,p[n],k;
  printf("Enter the number of vertices: ");
  scanf("%d",&n);
  printf("Enter the number of paths: ");
  scanf("%d",&v);
  /*
  for(int i = 0;i < n;i++)
  {
    for(int j = 0;j < n;j++)
    {
      G[i][j] = 0;
      c[i][j] = inf;
    }
  }

  printf("Enter the paths and cost:");
  for(int i = 0;i < v;i++)
  {
    scanf("%d%d%d",&o,&d,&cost);
    G[o][d] = 1;
    G[d][o] = 1;
    c[o][d] = cost;
    c[d][o] = cost;
  }*/
  int c[13][13]={{inf,inf,inf,inf,inf,inf,inf,inf,inf,inf,inf,inf,inf},
               {inf,inf,3,8,4,12,inf,inf,inf,inf,inf,inf,inf},
                {inf,inf,inf,inf,inf,inf,4,3,inf,inf,inf,inf,inf},
                {inf,inf,inf,inf,inf,inf,5,4,inf,inf,inf,inf,inf},
                {inf,inf,inf,inf,inf,inf,inf,3,2,inf,inf,inf,inf},
                {inf,inf,inf,inf,inf,inf,inf,2,1,inf,inf,inf,inf},
                {inf,inf,inf,inf,inf,inf,inf,inf,inf,3,4,inf,inf},
                {inf,inf,inf,inf,inf,inf,inf,inf,inf,4,7,6,inf},
                {inf,inf,inf,inf,inf,inf,inf,inf,inf,inf,8,7,inf},
                {inf,inf,inf,inf,inf,inf,inf,inf,inf,inf,inf,inf,3},
                {inf,inf,inf,inf,inf,inf,inf,inf,inf,inf,inf,inf,1},
                {inf,inf,inf,inf,inf,inf,inf,inf,inf,inf,inf,inf,4},
                {inf,inf,inf,inf,inf,inf,inf,inf,inf,inf,inf,inf,inf}};

  int G[13][13]={{0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,1,1,1,1,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,1,1,0,0,0,0,0},
                {0,0,0,0,0,0,1,1,0,0,0,0,0},
                {0,0,0,0,0,0,0,1,1,0,0,0,0},
                {0,0,0,0,0,0,0,1,1,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,1,1,0,0},
                {0,0,0,0,0,0,0,0,0,1,1,1,0},
                {0,0,0,0,0,0,0,0,0,0,1,1,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,1},
                {0,0,0,0,0,0,0,0,0,0,0,0,1},
                {0,0,0,0,0,0,0,0,0,0,0,0,1},
                {0,0,0,0,0,0,0,0,0,0,0,0,0}};
  printf("Enter the value of k: ");
  scanf("%d",&k);
  bgraph(n,G,k,p,c);
  


}

void bgraph(int n,int G[n+1][n+1],int k,int p[n+1],int c[n+1][1+n])
{
  int bcost[1+n],min,r,d[1+n];
  bcost[1] = 0;
  for(int j = 2;j <= n ;j++)
  {
    min = inf;
    for(int r = 1; r <= j; r++)
    {
      if(G[r][j] != 0 && (c[r][j] + bcost[r]) < min)
      {
        min = c[r][j] + bcost[r];
        d[j] = r;
      }
    }
    bcost[j] = min;
  }
  p[1] = 1;
  p[k] = n;
  for(int j = k - 1;j <= 2 ;j--)
  {
    p[j] = d[p[j + 1]];
  }
  printf("The cost is: %d\n",bcost[n]);
  for(int i=0;i<=n;i++)
  {
    printf("\ncost[%d]=%d \n",i,bcost[i]);
  }
  printf("The path is: ");
  int u=2;
  for(int j = 1;j < k;j++)
  {
   printf("p[%d]=%d ",u,d[u]);
    u = d[u];
  }
}