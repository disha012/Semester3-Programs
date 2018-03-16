/*
Stack:
A stack is a list in which all insertions and deletions are made at one end, called the top. It is a collection of contiguous cells, stacked on top of each other. The last element to be inserted into the stack will be the first to be removed. Thus stacks are sometimes referred to as Last In First Out (LIFO) lists.
The operations that can be performed on a stack are push, pop and top. Push is to insert an element at the top of the stack. Pop is deleting an element that is at the top most position in the stack. Top simple examines and returns the top most value in the stack without deleting it.
Push on an already filled stack and pop on an empty stack results in serious errors. Before any insertion, the value of the variable top is initialized to -1. 

Algorithm:
1. Declare an array ahead of time called Array.
2. Declare a structure called Stack that contains the TopOfStack and the Capacity fields.
3. The variable called TopOfStack for the stack is initialized to -1.
4. To push an element into the stack, increment TopOfStack and then set Array[TopOfStack]=X.
5. To pop an element from the array, set the return value to Array[TopOfStack] and then decrement TopOfStack.
*/


#include<stdio.h>

int t=-1;
int a[5];int n=0;
int  isfull() {
	if(n==5)
	return 1;
	else return 0;
}
int isempty() {
	if(n==0)
	return 1;
	else return 0;
}
void peek() {
	if(t==-1)
	printf("The stack is empty");
	else 
	printf("The peek is %d\n",a[t]);
}
void push (int val) {
	if(!isfull()) {
		t++;
		n++;
		a[t]=val;
	}
	else
	 printf("overflow\n");
}
int pop() {
	int temp=-1;
	if(!isempty()) {
		temp=a[t];
		t--;
		n--;	
		return temp;
	}
	else 
	return temp;
}
void disp() {	
	int i;
	if(t==-1)
		printf("empty que\n");
	else {
		for( i=t;i>=0;i--) {	
			printf("%d ",a[i]);
		}
	printf("\n");
	}
}
void main() {
	int num,e;
	int choice ;
	while(1) {
	printf("enter choice\n1:insert\n2:delete\n3:display\n4:peek\n5:exit\n");
	scanf("%d",&choice);
		switch(choice) {
			case 1 :   printf("enter the number to be inserted ");
				   scanf("%d",&num);
				   push(num);
				   disp();
				   break;
			case 2:    e=pop();
				   if(e==-1)
				   printf("empty\n");
				   else {
				   	 printf("The deleted value is %d\n",e);
				   	 disp();
				   }
				   break;
			case 3:	   disp();
				   break;
			case 4:    peek();
				   break;
			case 5:    break;       	 
		}
	if(choice==5)
	break;
	}
}

/*
OUTPUT:
enter choice
1:insert
2:delete
3:display
4:peek
5:exit
1
enter the number to be inserted 3
3 
enter choice
1:insert
2:delete
3:display
4:peek
5:exit
1
enter the number to be inserted 5
5 3 
enter choice
1:insert
2:delete
3:display
4:peek
5:exit
1
enter the number to be inserted 7
7 5 3 
enter choice
1:insert
2:delete
3:display
4:peek
5:exit
1
enter the number to be inserted 8
8 7 5 3 
enter choice
1:insert
2:delete
3:display
4:peek
5:exit
3
8 7 5 3 
enter choice
1:insert
2:delete
3:display
4:peek
5:exit
2
The deleted value is 8
7 5 3 
enter choice
1:insert
2:delete
3:display
4:peek
5:exit
4
The peek is 7
enter choice
1:insert
2:delete
3:display
4:peek
5:exit
2
The deleted value is 7
5 3 
enter choice
1:insert
2:delete
3:display
4:peek
5:exit
2
The deleted value is 5
3 
enter choice
1:insert
2:delete
3:display
4:peek
5:exit
2
The deleted value is 3
empty que
enter choice
1:insert
2:delete
3:display
4:peek
5:exit
5
*/

