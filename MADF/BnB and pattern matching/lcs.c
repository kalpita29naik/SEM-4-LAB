#include<stdio.h>
#include<string.h>
#define N 100

int LCS(char *X,char *Y);
int max(int a,int b);


int main(void)
{
 char X[N],Y[N],S[N][N];
 printf("\nEnter the first string: ");
 scanf("%s",X);
 printf("\nEnter the second string: ");
 scanf("%s",Y);
 int lcs = LCS(X,Y);
 printf("\nLength of longest common subsequence is %d\n",lcs);
 return 0;

 


}

int  LCS(char *X,char *Y)
{
 int n = strlen(X);
 int m = strlen(Y);
 int L[n+1][m+1];
for(int i = 0; i <= n; i++)
{
    L[i][0] = 0;
}
for(int j = 0; j <= m; j++)
{
    L[0][j] = 0;
}
for(int i = 1; i <= n; i++)
{
    for(int j = 1; j <= m; j++)
    {
        if(X[i-1] == Y[j-1])
        {
            L[i][j] = L[i-1][j-1] + 1;
        }
        else
        {
            L[i][j] = max(L[i-1][j],L[i][j-1]);
        }
    }
}
return L[n][m];
}

int max(int a,int b)
{
 if(a > b)
 {
  return a;
 }
 else
 {
  return b;
 }
}