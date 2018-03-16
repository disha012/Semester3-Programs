#include<stdio.h>

void m(int a[],int beg,int mid,int end)
{
int i=beg,j=mid+1,c=beg,temp[1000];
while(i<=mid&&j<=end)
{
if(a[i]<a[j])
temp[c++]=a[i++];
else 
temp[c++]=a[j++];
}
if(i>mid)
{
while(j<=end)
temp[c++]=a[j++];
}
if(j>end)
{
while(i<=mid)
temp[c++]=a[i++];
}
for( i=beg;i<=end;i++)
a[i]=temp[i];
}
int* merge(int a[],int beg,int end)
{
int mid,i;
if(beg<end)
{
mid=(beg+end)/2;
merge(a,beg,mid);
merge(a,mid+1,end);
m(a,beg,mid,end);
}
return a;
}

void main()
{
int a[1000];
int n,i;
printf("Enter the total numbers to be inserted\n");
scanf("%d",&n);
for(i=0;i<n;i++)
scanf("%d",&a[i]);
merge(a,0,n-1);
for(i=0;i<n;i++)
printf("%d ",a[i]);
printf("\n");
}
/*
OUTPUT:
Enter the total numbers to be inserted
5
5
4
3 
2
1
1 2 3 4 5 
*/


