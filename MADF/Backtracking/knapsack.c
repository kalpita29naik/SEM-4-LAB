#include<stdio.h>
#define N 20

int n,m,w[N],p[N],x[N],fp ,fw,y[N];

void BKnap(int k ,int cp ,int cw);
int bound(int k,int cp,int cw);
void print();

int main(void)
{
 int k=1,cp=0,cw=0;
 printf("Enter the number of elements: ");
 scanf("%d",&n);
 printf("Enter the capacity of the knapsack: ");
 scanf("%d",&m);
 printf("Enter the weights of the elements: ");
 for(int i = 1;i <= n;i++)
 { scanf("%d",&w[i]);}
 printf("Enter the profits of the elements: ");
 for(int i = 1;i <= n;i++)
 { scanf("%d",&p[i]); }
 BKnap(k,cp,cw);
 printf("\nThe optimal solution is: ");
 print();
 printf("\n\nThe optimal profit is: %d\n",fp);
 printf("\nThe optimal weight is: %d\n",fw);
 return 0;
}

void BKnap(int k ,int cp ,int cw)
{
 if(cw + w[k] <= m)
 {
  y[k] = 1;
  if(k < n)
  {
   BKnap(k+1,cp+p[k],cw+w[k]);
  }
  if(((cp+p[k]) > fp)  && (k == n))
  {
   fp = cp + p[k];
   fw = cw + w[k];
   for(int i = 1;i <= k;i++)
   {
    x[i] = y[i];
   }
  }
 }
 if(bound(k,cp,cw) >= fp)
 {
  y[k] = 0;
  if(k < n)
  {
   BKnap(k+1,cp,cw);
  }
  if((cp > fp) && (k == n))
  {
   fp = cp;
   fw = cw;
   for(int i = 1;i <= k;i++)
   {
    x[i] = y[i];
   }
  }
 }
}

int bound(int k,int cp,int cw)
{
 int b = cp;
 int c = cw;
 for(int i = k+1;i <= n;i++)
 {
  c = c + w[i];
  if(c <= m)
  {
   b = b + p[i];
  }
  else
  {
   return b + (1 - (c - m)/w[i])*p[i];
  }
 }
 return b;
}

void print()
{
 for(int i = 1;i <= n;i++)
 {
  printf("%d ",x[i]);
 }
}