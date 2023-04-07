#include<stdio.h>
void AllPaths(int n,int cost[n][n],int A[n][n]);

int main(void)
{
 int n,o,d,c,e;
 printf("Enter the number of vertices: ");
 scanf("%d",&n);
 printf("Enter the number of edges: ");
 scanf("%d",&e);
 int cost[n][n],A[n][n];
for(int i = 0;i < n ;i++)
{
 for(int j = 0;j < n;j++)
 {
  if(i == j)
  {
   cost[i][j] = 0;
  }
  else
  {
   cost[i][j] = 999;
  }
  
 }
}
printf("Enter paths and cost:\n");
for(int i = 0;i < e;i++)
{
 scanf("%d %d %d",&o,&d,&c);
 cost[o-1][d-1] = c;
}

 AllPaths(n,cost,A);
 return 0;

}

void AllPaths(int n,int cost[n][n],int A[n][n])
{
 for(int i = 0;i < n;i++)
 {
  for(int j = 0;j < n;j++)
  {
   A[i][j] = cost[i][j];
  }
 }
 printf("Initial matrix: A[0] \n");
 for(int i = 0;i < n;i++)
 {
  for(int j = 0;j < n;j++)
  {
   printf("%d ",A[i][j]);
  }
  printf("\n");
 }
 for(int k = 0;k < n;k++)
 {
  for(int i = 0;i < n;i++)
  {
   for(int j = 0;j < n;j++)
   {
    if(A[i][j] > A[i][k] + A[k][j])
    {
     A[i][j] = A[i][k] + A[k][j];
    }
   }
  }
  printf("Intermediate matrix: A[%d] \n" ,k+1);
  for(int i = 0;i < n;i++)
  {
   for(int j = 0;j < n;j++)
   {
    printf("%d ",A[i][j]);
   }
   printf("\n");
  }
 }
 printf("All pair shortest path matrix:\n");
 for(int i = 0;i < n;i++)
 {
  for(int j = 0;j < n;j++)
  {
   printf("%d ",A[i][j]);
  }
  printf("\n");
 }
}

