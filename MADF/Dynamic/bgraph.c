#include<stdio.h>
#define inf 999
int n,top = -1;
void bgraph(int G[n+1][n+1],int k,int p[n+1],int c[n+1][n+1]);
void path(int d[n+1],int n,int k);
void push(int stack[],int n);
int pop(int stack[]);

int main()
{
  int v,o,d,cost,p[n+1],k;
  printf("Enter the number of vertices: ");
  scanf("%d",&n);
  printf("Enter the number of paths: ");
  scanf("%d",&v);
  int G[n+1][n+1],c[n+1][n+1];
  for(int i = 0;i <= n;i++)
  {
    for(int j = 0;j <= n;j++)
    {
      G[i][j] = 0;
      c[i][j] = inf;
    }
  }

  printf("Enter the paths and cost\n");
  for(int i = 0;i < v;i++)
  {
    scanf("%d%d%d",&o,&d,&cost);
    G[o][d] = 1;

    c[o][d] = cost;

  }

  printf("Enter the value of k: ");
  scanf("%d",&k);
  bgraph(G,k,p,c);
}

void bgraph(int G[n+1][n+1],int k,int p[n+1],int c[n+1][n+1])
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
  printf("The path is: ");
  path(d,n,k);
}

void path(int d[n+1],int n,int k)
{
  int stack[k+1],i;
  push(stack,n);
  for(int i = 0;i < k;i++)
  {
    push(stack,d[n]);
    n = d[n];
  }
  for(i = top;i > 0;i--)
  {
    printf("%d -> ",pop(stack));
  }
  printf("%d ",pop(stack));
}

void push(int stack[],int n)
{
  stack[++top] = n;
}

int pop(int stack[])
{
  return stack[top--];
}