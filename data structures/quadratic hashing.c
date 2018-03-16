#include<stdio.h>
int a[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
void hashing(int t)
{
int j,i,m=t%10;
if(a[m]==-1)
a[m]=t;

else 
{
i=1;
while((a[(m+(3*i)+(5*i*i++))%10]!=-1)&&i<10);
if(i>=10)
printf("Hashing not possible");
else 
{printf("Number of collisions is %d \n",--i);
a[(m+(3*i)+(5*i*i))%10]=t;
}
}

}
void main()
{
int n,temp,i,j;
printf("Enter the number of elements you want to insert\n");
scanf("%d",&n);
printf("Enter the values\n");
for( i=0;i<n;i++)
{
scanf("%d",&temp); 
hashing(temp);

}
for( j=0;j<10;j++)printf("%d ",a[j]);
}

/*
OUTPUT:
Enter the number of elements you want to insert
4
Enter the values
11
21
Number of collisions is 1 
31
Number of collisions is 2 
41
Number of collisions is 3 
-1 11 -1 -1 -1 41 -1 31 -1 21 
*/
