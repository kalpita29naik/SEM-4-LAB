//3b.All pair shortest path 
#include<stdio.h>

void AllPaths(int n,int cost[n][n],int A[n][n]);
void print(int n,int cost[n][n]); 

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
  {  A[i][j] = cost[i][j]; }
 }
 printf("\nA[0] = ");
 print(n,A);
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
  printf("\nA[%d] = " ,k+1);
 print(n,A);
 }
}

void print(int n,int cost[n][n])
{
 for(int i = 0;i < n;i++)
 {
  for(int j = 0;j < n;j++)
  {
   printf("\t%d",cost[i][j]);
  }
  printf("\n");
 }
}