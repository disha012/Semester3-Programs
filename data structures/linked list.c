/*
Linked List:
A singly-linked list is simply a sequence of dynamically allocated items, each of which refers to its successor in the list. Each item in the list is called a node and contains two fields, an information field and a next address field. The information field holds the actual element on the list and next address field contains the address of the next node in the list. Hence the next address field has to be a pointer of type similar to the elements in the list. The entire list is pointed by an external pointer called ‘header’ (L) which points to the first node in the list. Whenever header is pointing to NULL, the list is empty. The next address field of the last node in the list will be pointing to NULL.
 During insertion a new node is created and the position at which the element is to be inserted is assigned as P. 
node p is made to point to the new node and the new node points to the node that P was pointing to initially before insertion. The following figure shows the changes that are made during the insertion of the element 10 in the existing list after the position 100.
Algorithm:
1. Declare and initialize the necessary variables.
2. Create a node structure with two fields, one - an information field, and the other, a pointer to a structure of a similar type of node.
3. Using malloc function create a structure and store the address of that in the variable L as the dummy or header node value.
4. To create a list of elements in the linked list, get the number of elements as input. For each element create a new node using an malloc function. Let the node be P.
a. The first created node at the address P, should be assigned to L->next. Then the value of the address at P should be assigned to a temporary cell called TempCell.
b. After that the subsequent nodes are created. Each node called P is assigned to TempCell->next and P->next is assigned as NULL. After that the value of P is assigned to the variable TempCell.
5. To insert an element X, after the position P in the above list, we first create a new node using malloc function and assign the returned memory address to the pointer TempCell.
Then,
a. Assign TempCell->element as X.
b. Make TempCell->next point to P.
c. Make P->next point to TempCell.
6. To delete an element X in the linked list,
a. Find the node previous to the element X in the list in the following manner.
Initialize the value of a node pointer, say P to the header value L. Keep on incrementing the value of P to be P->next until P->next->element is not equal to the element X. Once P->next->element is equal to X, then P is the previous node to X.
b. Store P->next in a temporary variable TempCell. Now the TempCell contains the pointer to the element X to be deleted.
c. Make P->next as TempCell->next.
d. Free the memory of TempCell. 
7. To find the position of an element X in the list,
a. Initialize the value of any node pointer variable, P as L->next, i.e. the first element in the list.
b. Keep on incrementing the value of P as P=P->next until P->element is not equal to the element X that is being searched. If P->element is equal to the element being searched or if we reach the end of the list, i.e. P=Null, we stop and return the value of P.

*/


#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};
 
struct node *start=NULL;

struct node *create(struct node *start) {
	struct node *new,*ptr;
	int num;
	printf("Enter -1 to exit \n");
	printf("Enter a value\n");
	scanf("%d",&num);
	while(num!=-1) {
		new =(struct node *)malloc(sizeof(struct node));
		new->data =num;
		if(start==NULL) {
			new->next =NULL;
			start=new;
		}
		else {
			ptr=start;
			while(ptr->next!=NULL) {
				ptr=ptr->next;
			}
			ptr->next=new;
			new->next=NULL;
		}
		printf("Enter a value\n");
		scanf("%d",&num);
	}
	return start;
}
struct node *insert(struct node *start) {
	int num,pos;
	struct node *new,*ptr,*pp;
	ptr=start;

	printf("Enter the value to be inserted\n");
	scanf("%d",&num);
	printf("Enter the number before which the number is to be inserted\n");
	scanf("%d",&pos);
	new =(struct node *)malloc(sizeof(struct node ));
	new->data=num;
	if(ptr->data ==pos) {
		new->next=ptr;
		start=new;
	}
	else {
		while(ptr->data!=pos) {
			pp=ptr;
			ptr=ptr->next;
		}
		pp->next=new;
		new->next=ptr;
	}
	return start;
}
struct node *delete(struct node *start) {
	int num;
	struct node *ptr,*pp;
	printf("Enter the value to be deleted ");
	scanf("%d",&num);
	if(start->data==num) {
		ptr=start;
		start=start->next;
		free(ptr);
		return start;
	}
	else {
		ptr =start;
		while(ptr->data!=num && ptr!=NULL) {
			pp=ptr;
			ptr=ptr->next;
		}
		if(ptr==NULL) {
			printf("value not found");
		}
		else if(ptr->next==NULL) {
			pp->next=NULL;
			free(ptr);
		}
		else {
			pp->next=ptr->next;
			free(ptr);
		}
		return start;
	}

}
struct node *disp(struct node *start) {
	struct node *ptr;
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
		printf("Enter choice\n1:create\n2:insert\n3:delete\n4:display\n5:exit\n");
		scanf("%d",&choice);
		switch(choice) {
			case 1 :   start=create(start);
				   start=disp(start);
				   break;
			case 2:	   start=insert(start);
				   start=disp(start);
				   break;
			case 3:    start=delete(start);
				   start=disp(start);
				   break;
			case 4:	   start=disp(start);
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
1:create
2:insert
3:delete
4:display
5:exit
1
Enter -1 to exit 
Enter a value
2
Enter a value
3
Enter a value
4
Enter a value
5
Enter a value
-1
2 3 4 5 
Enter choice
1:create
2:insert
3:delete
4:display
5:exit
2
Enter the value to be inserted
7
Enter the number before which the number is to be inserted
5
2 3 4 7 5 
Enter choice
1:create
2:insert
3:delete
4:display
5:exit
3
Enter the value to be deleted 2
3 4 7 5 
Enter choice
1:create
2:insert
3:delete
4:display
5:exit
3
Enter the value to be deleted 5
3 4 7 
Enter choice
1:create
2:insert
3:delete
4:display
5:exit
3
Enter the value to be deleted 4
3 7 
Enter choice
1:create
2:insert
3:delete
4:display
5:exit
2
Enter the value to be inserted
1
Enter the number before which the number is to be inserted
3
1 3 7 
Enter choice
1:create
2:insert
3:delete
4:display
5:exit
4
1 3 7 
Enter choice
1:create
2:insert
3:delete
4:display
5:exit
5
	   
*/	   

























