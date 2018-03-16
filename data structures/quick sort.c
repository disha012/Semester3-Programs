#include<stdio.h>
int n,a[1000];
void quicksort(int left,int right)
{
	if(right-left<2)
	return;
	int m=partition(left,right);
	quicksort(left,m);
	quicksort(m+1,right);
}
int partition(int left,int right)
{
	int pivot=a[left],i=left,j=right;
	while(i<j)
	{
		while (i<j&&a[--j]>=pivot);
		if(i<j)
		a[i]=a[j];
		while (i<j&&a[++i]<=pivot);
		if(i<j)
		a[j]=a[i];
	}
	a[j]=pivot;
	return j;
}
void main()
{
	int n,i;
	printf("Enter number of array elements\n");
	scanf ("%d",&n);
	printf("Enter the values\n");
	for( i=0;i<n;i++)
	scanf("%d",&a[i]);
	quicksort(0,n);
	for( i=0;i<n;i++)
	printf("%d",a[i]);
	printf("\n");
}
/*
OUTPUT:
Enter number of array elements
5
Enter the values
5
4
3
2
1
12345

*/

