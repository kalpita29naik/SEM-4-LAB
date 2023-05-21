#include<stdio.h>
#include<math.h>
int count=1;

void SumOfSubset(int n,int s,int k,int r,int w[n+1],int m,int x[n+1]);

int main(void)
{
 int n,m;
 printf("Enter the total number of elements: ");
 scanf("%d",&n);
 printf("Enter m: ");
 scanf("%d",&m);
 int w[n+1],x[n+1],r=0;
 printf("Enter the weights: ");
 for(int i=1;i<=n;i++)
 {
  scanf("%d",&w[i]);
 }
  for(int i=1;i<=n;i++)
  {
    x[i]=0;
    r=r+w[i];
  }
 int s=0,k=1;
for(int i=1;i<=n;i++)
{
  
  printf("\tx%d",i);
}
printf("\n");

 SumOfSubset(n,s,k,r,w,m,x);
 
}

void SumOfSubset(int n,int s,int k,int r,int w[n+1],int m,int x[n+1])
{
 if(k>n)
 {
  return;
 }
 x[k]=1;
 if(s+w[k]==m)
 {
   printf("\nSolu %d:",count);
 count++;
  for(int i=1;i<=n;i++)
  {
    printf("\t%d",x[i]);

  }
  printf("\n");
 }
 else if(s+w[k]+w[k+1]<=m)
 {
  SumOfSubset(n,s+w[k],k+1,r,w,m,x);
 }
 if((s+r-w[k]>=m) && (s+w[k+1]<=m))
 {
  x[k]=0;
  SumOfSubset(n,s,k+1,r,w,m,x);
 }
}