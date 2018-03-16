/*
Circular queues
A circular queue is an improvement over the standard queue structure. In a standard queue, when an element is deleted, the vacant space is not reutilized. However, in a circular queue, vacant spaces are reutilized.
While inserting elements, when you reach the end of an array and you need to insert another element, you must insert that element at the beginning (given that the first element has been deleted and the space is vacant).

Variables used
In addition to all the variables that are used in a standard queue, circular queues support the following variable:
count: Number of elements present in a queue

Functions supported
Circular queues support all the functions that are supported by standard queues, however, there is a difference in the implementation of these functions.
*/
#include<stdio.h>

int f=-1,r=-1;
int a[5];int n=0,max=5;
int  isfull()
	{
		if((f==0&&r==max-1)||n==5)
		return 1;
		else return 0;
	}
int isempty()
	{
		if((f==-1&&r==-1)&&n==0)
		return 1;
		else return 0;
	}

void enque(int val)
	{
	if(!isfull())
	{
		if(f==-1&&r==-1)
		{	
			f=0;r=0;
			a[r]=val;n++;
		}	

		else  
		{
			r=(r+1)%max;//printf("r=%d \n",r);
			a[r]=val;n++;
		}
	}
	else 
	printf("overflow\n");
	}

int dque()
	{
	int temp=-1;
	if(!isempty())
	{
		if(f==r)
		{
			temp=a[f];
			f=0;r=0;n--;
		}

		else 
		{
			temp=a[f];
			f=(f+1)%max;
			n--;
		}
	return temp;
	}
	else 
	return temp;
	}

void disp()
{
int i,j,k;
	if(f==-1&&r==-1)
	printf("empty que");
	else
	{
		if(f<=r)
		{
			for( i=f;i<=r;i++)
			{
			printf("%d ",a[i]);
			}
			printf("\n");
		}
		else 
		{
			for( j=f;j<max;j++)
			printf("%d ",a[j]);
			for(k=0;k<=r;k++)
			printf("%d ",a[k]);
			printf("\n");
		}
	}
}	


void main()
{

int choice ;
int e,h;

while(1)
{
	printf("enter choice\n1:insert\n2:delete\n3:size\n4:exit\n");
	scanf("%d",&choice);
switch(choice)
	{
		case 1 :   printf("enter the number to be inserted ");
			   scanf("%d",&h);
			   enque(h);
			   disp();
			   break;
			   
	
		case 2:	   e=dque();
			   printf("%d\n",e);
			   disp();
			   break;
			   
		case 3:    printf("%d\n",n);           	 
			   	 
		case 4:    break;
	}
if(choice==4)
break;
}

}
           	   
/*
OUTPUT:

enter choice
1:insert
2:delete
3:size
4:exit
1
enter the number to be inserted 2
2 
enter choice
1:insert
2:delete
3:size
4:exit
1
enter the number to be inserted 4
2 4 
enter choice
1:insert
2:delete
3:size
4:exit
1
enter the number to be inserted 5
2 4 5 
enter choice
1:insert
2:delete
3:size
4:exit
1
enter the number to be inserted 6
2 4 5 6 
enter choice
1:insert
2:delete
3:size
4:exit
1
enter the number to be inserted 7
2 4 5 6 7 
enter choice
1:insert
2:delete
3:size
4:exit
1
enter the number to be inserted 8
overflow
2 4 5 6 7 
enter choice
1:insert
2:delete
3:size
4:exit
2
2
4 5 6 7 
enter choice
1:insert
2:delete
3:size
4:exit
2
4
5 6 7 
enter choice
1:insert
2:delete
3:size
4:exit
2
5
6 7 
enter choice
1:insert
2:delete
3:size
4:exit
1
enter the number to be inserted 8
6 7 8 
enter choice
1:insert
2:delete
3:size
4:exit
1
enter the number to be inserted 9
6 7 8 9 
enter choice
1:insert
2:delete
3:size
4:exit
1
enter the number to be inserted 5
6 7 8 9 5 
enter choice
1:insert
2:delete
3:size
4:exit
1
enter the number to be inserted 7
overflow
6 7 8 9 5 
enter choice
1:insert
2:delete
3:size
4:exit
2
6
7 8 9 5 
enter choice
1:insert
2:delete
3:size
4:exit
2
7
8 9 5 
enter choice
1:insert
2:delete
3:size
4:exit
2
8
9 5 
enter choice
1:insert
2:delete
3:size
4:exit
3
2
enter choice
1:insert
2:delete
3:size
4:exit
4
*/	   
	   

























