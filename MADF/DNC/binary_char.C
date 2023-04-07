//Binary search for sorted char array

#include<stdio.h>
#define MAX 100

int n;
char a[MAX],temp[MAX];

int binary(int low,int up,char ele);
void merge(int low,int mid,int up);
void merge_sort(int low,int up);

 int main()
 {
   char ele;
   int index=0;
   printf("Enter Number of elements: ");
   scanf("%d",&n);

   printf("Enter the elemets\n");
   for(int i=0;i<n;i++)
   {
     fflush(stdin);
     scanf("%c",&a[i]);
   }

   printf("\nUnsorted array is : ");
   for(int i=0;i<n;i++)
   {
     printf("%c ",a[i]);
   } 

   merge_sort(0,n-1);
   printf("\nSorted array is :   ");
   for(int i=0;i<n;i++)
   {
    printf("%c ",a[i]);
   } 
   fflush(stdin);
   printf("\nEnter the character to be searched: ");
   scanf("%c",&ele);

   index=binary(0,n,ele);
   if(index == -1)
   {
    printf("Element not found\n");
   }
   else
   {
    printf("Element found at position %d ",index);
   }
 }

 int binary(int low,int up,char ele)
 {
  int mid;
  if(low==up)
  {
   if(ele==a[low])
   {
    return low;
   }
   else
   {
    return -1;
   }
  }
  else
  {
   mid=(low+up)/2;
   if(ele < a[mid])
   {
    return binary(low,mid-1,ele);
   }
   else if(ele > a[mid])
   {
    return binary(mid+1,up,ele);
   }
   else
   {
    return mid;
   }
  }
 }

 void merge_sort(int low,int up)
{
 if(low<up)
 {
  int mid=(low+up)/2;
  merge_sort(low,mid);
  merge_sort(mid+1,up);
  merge(low,mid,up);
 }
}

void merge(int low,int mid,int up)
{
 int i=low,j=mid+1,k=low;
 while((i<=mid) && (j<=up))
 {
  if(a[i]<=a[j])
  {
   temp[k++]=a[i++];
  }
  else
  {
   temp[k++]=a[j++];
  }
 }
 while(i<=mid)
 {
  temp[k++]=a[i++];
 }
 while(j<=up)
 {
  temp[k++]=a[j++];
 }

 for(int i=low;i<=up;i++)
 {
  a[i]=temp[i];
 }
}