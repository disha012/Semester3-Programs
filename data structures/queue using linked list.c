/*
Linked List Implementation of a Queue:
We go for a linked list implementation of a queue rather than an array implementation because of the run time memory allocation feature of linked lists. In this implementation we make a head pointer and make it point to the first created node in the stack. Whenever an element is enqueued into the queue, a new node is created at the end of the linked list and the element is kept in that node. Whenever a dequeue operation is performed on the queue, the head pointer is made to point to the node, next to the one that it is currently pointing to.


Algorithm:
1. Create a structure with an element (Element) and a pointer (Next) that points to the next node in the list.
2. Create a head pointer using malloc function and assign the resultant pointer variable to the head pointer Q.
3. During the Enqueue operation of a new element X:
a. Create a new node called TmpCell using the malloc function. Assign the element to that node by the statement: TmpCell - > Element = X and assign TmpCell-> Next to NULL
b. If, at the time of insertion, Q->Next is NULL (i.e. the queue is initially empty) assign Q->Next to TmpCell.
c. Otherwise, slide a pointer to the node, P, to the end of the queue by the statement P=P->Next until P->Next!=NULL and assign P->Next= TmpCell.
4. During the Dequeue operation:
a. Store the value of Q->Next in a temporary pointer FirstCell.
b. Make Q->Next = Q-> Next->Next.
c. Free the memory contents of FirstCell.
*/


#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};
 
struct node *start=NULL;
struct node *rear=NULL;

struct node *enque(struct node *start) {
	int num,pos;
	struct node *new;
	printf("Enter the value to be inserted\n");
	scanf("%d",&num);
	new =(struct node *)malloc(sizeof(struct node ));
	new->data=num;
	if(start==NULL&&rear==NULL) {
		new->next=NULL;
		start=new;
		rear=new;
	}
	else {
		rear->next=new;
		new->next=NULL;
		rear=new;
	}
	printf("%d has been inserted to  the queue\n",num);
	return start;
}
struct node *deque(struct node *start) {
	struct node *ptr;
	ptr=start;
	if(ptr==NULL) {
		printf("Underflow\n");
	}
	else if(ptr->next ==NULL) {
		printf("The deleted value is %d\n",start->data);
	        start=NULL;
	        rear =NULL;
	        free(ptr);
	}
	else {  printf("The deleted value is %d\n",start->data);
		start=start->next;
		free(ptr);
	}
return start;
}
struct node *disp(struct node *start) {
	struct node *ptr;
	ptr=start;
	if(ptr==NULL)
	printf("EMPTY QUEUE ");
	else{
	printf("the queue is as follows\n");
	while (ptr!=NULL) {
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	}
	printf("\n");
	return start;
}

void main() {
	int choice ;
	while(1) {
		printf("Enter choice\n1:insert\n2:delete\n3:display\n4:exit\n");
		scanf("%d",&choice);
		switch(choice) {
			case 1 :   start=enque(start);
				   start=disp(start);
				   break;
			case 2:	   start=deque(start);
				   start=disp(start);
				   break;
			case 3:    start=disp(start);
				   break;
			case 4:	   break;
		}
		if(choice==4)
		break;
	}
}
/*
OUTPUT:
Enter choice
1:insert
2:delete
3:display
4:exit
1
Enter the value to be inserted
6
6 has been inserted to  the queue
the queue is as follows
6 
Enter choice
1:insert
2:delete
3:display
4:exit
1
Enter the value to be inserted
5
5 has been inserted to  the queue
the queue is as follows
6 5 
Enter choice
1:insert
2:delete
3:display
4:exit
1
Enter the value to be inserted
4
4 has been inserted to  the queue
the queue is as follows
6 5 4 
Enter choice
1:insert
2:delete
3:display
4:exit
2
The deleted value is 6
the queue is as follows
5 4 
Enter choice
1:insert
2:delete
3:display
4:exit
2
The deleted value is 5
the queue is as follows
4 
Enter choice
1:insert
2:delete
3:display
4:exit
2
The deleted value is 4
EMPTY QUEUE
Enter choice
1:insert
2:delete
3:display
4:exit
1
Enter the value to be inserted
6
6 has been inserted to  the queue
the queue is as follows
6 
Enter choice
1:insert
2:delete
3:display
4:exit
1
Enter the value to be inserted
4
4 has been inserted to  the queue
the queue is as follows
6 4 
Enter choice
1:insert
2:delete
3:display
4:exit
3
the queue is as follows
6 4 
Enter choice
1:insert
2:delete
3:display
4:exit
4
*/


