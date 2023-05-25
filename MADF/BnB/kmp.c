#include<stdio.h>
#include<string.h>
#define N 100
int f[N];

int KMPMatch(char *T,char *P);
void KMPFailure(char *P);
void showtable(char *P);

int main(void)
{
 char T[N],P[N];
 printf("\nEnter the string: ");
 scanf("%s",T);
 printf("\nEnter the pattern: ");
 scanf("%s",P);
 int index = KMPMatch(T,P);
 if(index == -1)
 {
 printf("\nPattern not found!!\n");
 }
 else
 {
 printf("\nPattern found at index %d!!\n",index);
 }
}

int KMPMatch(char *T,char *P)
{
 KMPFailure(P);
 int i=0,j=0,n=strlen(T),m=strlen(P);
 while(i < n)
 {
 if(P[j] == T[i])
 {
 if(j == m - 1)
 {
 return i - m + 1;
 }
 i++;
 j++;
 }
 else if(j > 0)
 {
 j = f[j - 1];
 }
 else
 {
 i++;
 }
 }
 return -1;
}


void KMPFailure(char *P)
{
 int i = 1;
 int j = 0;
 f[0] = 0; 
 int m = strlen(P);
 while(i < m)
 {
 if(P[j] == P[i])
 {
 f[i] = j+1;
 i++;
 j++;
 }
 else if(j > 0)
 {
 j = f[j - 1];
 }
 else
 {
 f[i] = 0;
 i++;
 }
 }
 showtable(P);
}

void showtable(char *P)
{
 int m = strlen(P);
 printf("\nFailure function\n");
 printf("P[j]\t");
 for(int i=0;i<m;i++)
 {
 printf("%c\t",P[i]);
 }
 printf("\n");
 printf("f[j]\t");
 for(int i=0;i<m;i++)
 {
 printf("%d\t",f[i]);
 }
 printf("\n");
}
