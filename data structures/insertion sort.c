#include <stdio.h>
void insertionSort(int arr[],int n)
{int i,j,temp,f;
	for( i=1;i<n;i++)
	{
	j=i-1;
	temp=arr[i];
	while(j>=0&&temp<arr[j])
	{
	arr[j+1]=arr[j];
	j--;
	}
	arr[j+1]=temp;
	}
	for( i=0;i<n;i++)
	printf("%d ",arr[i]);
	printf("\n");
}
void main()
{
int arr[100];
int i,n;
printf("Enter the number of terms ");
scanf("%d",&n);
printf("Enter the terms \n");
	for( i=0;i<n;i++)
		scanf("%d",&arr[i]);
	insertionSort(arr,n);
	
}

/*
OUTPUT:
Enter the number of terms 5
Enter the terms 
5
4
3
2
1
1 2 3 4 5 

*/












