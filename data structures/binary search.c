/*
Binary Search:
Binary search is the most popular Search algorithm.It is efficient and also one of the most commonly used techniques that is used to solve problems.
Binary search works only on a sorted set of elements. To use binary search on a collection, the collection must first be sorted.
When binary search is used to perform operations on a sorted set, the number of iterations can always be reduced on the basis of the value that is being searched.
Binary search has huge advantage of time complexity over linear search. Linear search has worst-case complexity of ?(n) whereas binary search has ?(log n).
There are cases where the location of target data may be known in advance. Here, linear search and even binary search will seem slow as we can directly jump to memory space where names start from 'M' are stored.
Step 1  ? Start searching data from middle of the list.
Step 2  ? If it is a match, return the index of the item, and exit.
Step 3  ? If it is not a match, probe position.
Step 4  ? Divide the list using probing formula and find the new middle.
Step 5  ? If data is greater than middle, search in higher sub-list.
Step 6  ? If data is smaller than middle, search in lower sub-list.
Step 7  ? Repeat until match
*/
#include<stdio.h>
int bsearch(int a[],int beg,int end,int n)
	{
	int mid=(beg+end)/2;
	if(beg==end-1&&a[beg]!=n&&a[end]!=n)
	return -1;
	else if (a[mid]>=n)
		{
		if(a[mid]==n)
		return mid;
		else 
		return bsearch(a,beg,mid,n);
		}
	else if(a[mid]<n)
	return bsearch(a,mid+1,end,n);
	}
void main()
{
	int n;
	int a[10]={1,22,33,42,51,66,72,81,97,100};
	printf("Enter the number to be searched\n");
	scanf("%d",&n);
	if(bsearch(a,0,9,n)==-1)
	printf("Value not found\n");
	else
	printf("%d\n",bsearch(a,0,9,n));
}

/*
OUTPUT 1:
Enter the number to be searched
72
6
OUTPUT 2:
Enter the number to be searched
11
Value not found
*/
