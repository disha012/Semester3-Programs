/*
 Hashing
Hashing is a technique to convert a range of key values into a range of indexes of an array.
Hashing is implemented in two steps:
1.	An element is converted into an integer by using a hash function. This element can be used as an index to store the original element, which falls into the hash table.
2.	The element is stored in the hash table where it can be quickly retrieved using hashed key.
hash = hashfunc(key)
index = hash % array_size

In this method, the hash is independent of the array size and it is then reduced to an index (a number between 0 and array_size ? 1) by using the modulo operator (%).
Hash function
A hash function is any function that can be used to map a data set of an arbitrary size to a data set of a fixed size, which falls into the hash table. The values returned by a hash function are called hash values, hash codes, hash sums, or simply hashes.

*/
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
		while((a[m+i++]%10!=-1)&&i<10);
		if(i>=10)
		printf("Hashing not possible");
		else
		{
			printf("Number of collisions is %d \n",i-1);
			a[m+--i]=t;
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
5
Enter the values
11
21
Number of collisions is 1
31
Number of collisions is 2
44
54
Number of collisions is 1
-1 11 21 31 44 54 -1 -1 -1 -1 
*/
