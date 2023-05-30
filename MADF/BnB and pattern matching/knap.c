#include<stdio.h>
#define N 100

void BnB(int level,int w,int p);
int Upper_Bound(int level,int w,int p);

int m,n,currentsol[N],bestsol[N],cw,cp,finalProfit,weights[N],profits[N];


int main(void)
{
 printf("\nEnter the number of items: ");
 scanf("%d",&n);
 printf("\nEnter the capacity of knapsack: ");
 scanf("%d",&m);
 printf("Enter weights: ");
 for(int i=0;i<n;i++)
 {
  scanf("%d",&weights[i]);
 }
 printf("Enter profits: ");
 for(int i=0;i<n;i++)
 {
  scanf("%d",&profits[i]);
 }
 cw = cp = finalProfit = 0;
 for(int i=0;i<n;i++)
 {
  currentsol[i] = bestsol[i] = 0;
 }
 BnB(0,cw,cp);

 printf("\nBest solution is: ");
 for(int i=0;i<n;i++)
 {
  printf("%d ",bestsol[i]);
 }
 printf("\n\nProfit: %d\n\n",finalProfit);
 return 0;
}

void BnB(int level,int w,int p)
{
 if(w <= m)
 {
  if(p > finalProfit)
  {
   finalProfit = p;
   for(int i=0;i<n;i++)
   {
    bestsol[i] = currentsol[i];
   }
  }
 }

 if(level == n || Upper_Bound(level,w,p) <= finalProfit)
 {
  return;
 }

 currentsol[level] = 1;
 BnB(level+1,w+weights[level],p+profits[level]);
 currentsol[level] = 0;
 BnB(level+1,w,p);
}

int Upper_Bound(int level , int w , int p)
{
 int r = m - w;
 int upperbound = p;
 for(int i=0;i<n;i++)
 {
  if(weights[i] <= r)
  {
   r = r- weights[i];
   upperbound = upperbound + profits[i];
  }
  else
  {
   upperbound = upperbound + (r/weights[i])*profits[i];
   break;
  }
 }
 return upperbound;
}