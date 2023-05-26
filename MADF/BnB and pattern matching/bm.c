#include<stdio.h>
#include<string.h>
#define N 100

int BMMatch(char *T,char *P);
int last(char c , char *P);
int min(int a,int b);


int main(void)
{
 char T[N],P[N];
 printf("\nEnter the string: ");
 scanf("%s",T);
 printf("\nEnter the pattern: ");
 scanf("%s",P);
 int index = BMMatch(T,P);
 if(index == -1)
 {
 printf("\nPattern not found!!\n");
 }
 else
 {
 printf("\nPattern found at index %d!!\n",index);
 }
}

int BMMatch(char *T,char *P)
{
 int n=strlen(T),m=strlen(P);
 int i=m-1,j=m-1;
 while(i < n)
 {
   if(P[j] == T[i])
   {
      if(j == 0)
      {
         return i;
      }
      else
      {
         i--;
         j--;
      }
  }
  else
  {
     i = i + m - min(j,1 + last(T[i],P));
     j = m - 1;
  }
}//end of while
 return -1; 
}

int last(char c , char *P)
{
 int i;
 for(i=strlen(P)-1;i>=0;i--)
 {
  if(P[i] == c)
  {
   return i;
  }
 }
 return -1;
}

int min(int a,int b)
{
 if(a < b)
 {
  return a;
 }
 else
 {
  return b;
 }
}