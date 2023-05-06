#include<stdio.h>
#include<math.h>
int N;

void Nqueen(int N,int k,int x[N+1]);
int Place(int k,int i,int x[N]);
void Print(int N,int x[N+1]);


int main()
{
 int k=1;
 printf("Enter the number of queens: ");
 scanf("%d",&N);
 int x[N+1];
 Nqueen(N,k,x);

}

void Nqueen(int N,int k,int x[N+1])
{
 for(int i = 1; i <= N; i++)
 {
  if(Place(k,i,x))
  {
   x[k] = i;
   if(k == N)
   {
    Print(N,x);
   }
   else
   {
    Nqueen(N,k+1,x);
   }
  }
 }
}

int Place(int k,int i,int x[N])
{
 for(int j = 1; j < k; j++)
 {
  if((x[j] == i) || (abs(x[j]-i) == abs(j-k)))
  {
   return 0;
  }
 }
 return 1;
}

void Print(int N,int x[N+1])
{
 char board[N+1][N+1];
 for(int i=1;i<=N;i++)
 {
  for(int j=1;j<=N;j++)
  {
   board[i][j]='-';
  }
 }
 for(int i=1;i<=N;i++)
 {
  board[i][x[i]]='Q';
 }

 for(int i=1;i<=N;i++)
 {
  for(int j=1;j<=N;j++)
  {
   printf("%c\t",board[i][j]);
  }
  printf("\n");
 }
 printf("\n------------------------------\n");
}