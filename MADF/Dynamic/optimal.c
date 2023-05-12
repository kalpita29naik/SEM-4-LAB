#include<stdio.h>

void obst(int n,int p[n+1],int q[n+1],int c[n+1][n+1],int w[n+1][n+1],int r[n+1][n+1],char id[n+1][n+1]);
int find(int n,int i,int j,int c[n+1][n+1],int w[n+1][n+1],int r[n+1][n+1]);
void print(int n,int c[n+1][n+1],int w[n+1][n+1],int r[n+1][n+1]);

int main(void)
{
 int n;
 printf("Enter the number of identifiers: ");
 scanf("%d",&n);
 int p[n+1],q[n+1];
 char id[n+1][n+1];
 printf("Enter the identifiers: ");
 for(int i=1;i<=n;i++)
 {
  scanf("%s",&id[i]);
 }
 printf("Enter the probability of identifiers:");
 for(int i=1;i<=n;i++)
 {
  scanf("%d",&p[i]);
 }
 printf("Enter the probability of dummy identifiers:");
 for(int i=0;i<=n;i++)
 {
  scanf("%d",&q[i]);
 }
 int c[n+1][n+1],w[n+1][n+1],r[n+1][n+1];
 obst(n,p,q,c,w,r,id);
}

void obst(int n,int p[n+1],int q[n+1],int c[n+1][n+1],int w[n+1][n+1],int r[n+1][n+1],char id[n+1][n+1])
{
 int k;
 for(int i = 0;i < n;i++)
 {
  w[i][i] = q[i];
  r[i][i] = 0;
  c[i][i] = 0;
  w[i][i+1] = q[i] + q[i+1] + p[i+1];
  r[i][i+1] = i+1;
  c[i][i+1] = q[i] + q[i+1] + p[i+1];
 }
 w[n+1][n+1] = q[n+1];
 r[n+1][n+1] = 0;
 c[n+1][n+1] = 0;

 for(int m = 2;m <= n + 1;m++)
 {
  for(int i = 0;i <= n + 1 - m;i++)
  {
   int j = i + m;
   w[i][j] = w[i][j-1] + p[j] + q[j];
   k = find(n,i,j,c,w,r);
   c[i][j] = c[i][k-1] + c[k][j] + w[i][j];
   r[i][j] = k;
  }
 }
 
 print(n,c,w,r);
 printf("Minimum Cost=%d\n",c[0][n-(n+1-2)]);
 printf("Root=%s\n",id[r[0][n]]);
}

int find(int n,int i,int j,int c[n+1][n+1],int w[n+1][n+1],int r[n+1][n+1])
{
 int min = 9999,l;
 for(int m = i + 1;m <= j;m++)
 {
  if(c[i][m-1] + c[m][j] < min)
  {
   min = c[i][m-1] + c[m][j];
   l = m;
  }
 }
 return l;
}

void print(int n,int c[n+1][n+1],int w[n+1][n+1],int r[n+1][n+1])
{
 int a = 0,i = 0,j = 0;
 while(a < n + 1)
 {
  i = 0;
  j = a;
  while(j < n + 1 && i < n + 1 - a)
  {
   printf("w[i][j]=%d\t",w[i][j]);
   i++;
   j++;
  }
  i = 0;
  j = a;
  printf("\n");
  while(j < n + 1 && i < n + 1-a)
  {
   printf("c[i][j]=%d\t",c[i][j]);
   i++;
   j++;
  }
  i = 0;
  j = a;
  printf("\n");
  while(j < n + 1 && i < n + 1-a)
  {
   printf("r[i][j]=%d\t",r[i][j]);
   i++;
   j++;
  }
  printf("\n-------------------------------------------------------------------------\n");
  a++;
 }
}