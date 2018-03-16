/*
Linked List Implementation of a Stack:
The disadvantage of a stack implemented using an array is that its size is fixed and needs to be specified at compile time. This stack implementation is often impractical. To make the size of the stack to be dynamic and determined at run-time, we need to implement it using a linked list. By doing this, the size of the stack can shrink or grow on demand during the program execution. A stack implemented using a linked list is also known as a linked stack.
First, we declare the element of the stack:
Second, we need to initialize the stack by setting the head pointer of the stack to NULL:
Third, to push an element into the stack, we create a new node, and point the stack pointer to the new node e.g., to push the first element:
To pop an element from the stack, we need to get the data of the element, point the stack pointer to the next element and remove it. 
To display the stack content, we traverse the stack elements from the first element to NULL.

*/



#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};
 
struct node *start=NULL;

struct node *push(struct node *start) {
	int num,pos;
	struct node *new;
	printf("Enter the value to be inserted\n");
	scanf("%d",&num);
	new =(struct node *)malloc(sizeof(struct node ));
	new->data=num;
	if(start==NULL) {
		new->next=start;
		start=new;
	}
	else {
		new->next=start;
		start=new;
	}
	printf("%d has been inserted to  the stack\n",num);
	return start;
}
struct node *pop(struct node *start) {
	struct node *ptr;
	ptr=start;
	if(ptr==NULL) {
		printf("Underflow\n");
	}
	else {  printf("The deleted value is %d\n",start->data);
		start=start->next;
		free(ptr);
	}
return start;
}
struct node *peek(struct node *start) {
	if(start==NULL)
		printf("The stack is empty\n");
	else 
		printf("The peek is %d\n",start->data);
		return start;
}
struct node *disp(struct node *start) {
	struct node *ptr;
	printf("the stack is as follows\n");
	ptr=start;
	while (ptr!=NULL) {
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
	return start;
}

void main() {
	int choice ;
	while(1) {
		printf("Enter choice\n1:insert\n2:delete\n3:display\n4:peek\n5:exit\n");
		scanf("%d",&choice);
		switch(choice) {
			case 1 :   start=push(start);
				   start=disp(start);
				   break;
			case 2:	   start=pop(start);
				   start=disp(start);
				   break;
			case 3:    start=disp(start);
				   break;
			case 4:	   start=peek(start);
				   break;
			case 5:	   break;
		}
		if(choice==5)
		break;
	}
}
/*
OUTPUT:
Enter choice
1:insert
2:delete
3:display
4:peek
5:exit
1
Enter the value to be inserted
5
5 has been inserted to  the stack
the stack is as follows
5 
Enter choice
1:insert
2:delete
3:display
4:peek
5:exit
1
Enter the value to be inserted
4
4 has been inserted to  the stack
the stack is as follows
4 5 
Enter choice
1:insert
2:delete
3:display
4:peek
5:exit
1
Enter the value to be inserted
3
3 has been inserted to  the stack
the stack is as follows
3 4 5 
Enter choice
1:insert
2:delete
3:display
4:peek
5:exit
4
The peek is 3
Enter choice
1:insert
2:delete
3:display
4:peek
5:exit
2
The deleted value is 3
the stack is as follows
4 5 
Enter choice
1:insert
2:delete
3:display
4:peek
5:exit
2
The deleted value is 4
the stack is as follows
5 
Enter choice
1:insert
2:delete
3:display
4:peek
5:exit
5

*/

