#include<stdio.h> 
#include<malloc.h>
struct node 
{
int data; 
struct node* left;
struct node* right;
};
struct node *root=NULL;

void printInorder(struct node* node)
{
     if (node == NULL)
          return;

     /* first recur on left child */
     printInorder(node->left);

     /* then print the data of node */
     printf("%d ", node->data);  

     /* now recur on right child */
     printInorder(node->right);
}
struct node *insert(int val)
{
struct node *newn =  (struct node *)malloc(sizeof(struct node));
newn->data=val;
newn->left=NULL;
newn->right=NULL;
	if(root ==NULL)
	{
	root=newn;
	}
	else 
	{
	struct node *temp=root,*ptr;
		while(temp!=NULL)
		{
		ptr=temp;
		if(val<temp->data)temp=temp->left;
		else temp=temp->right;
		}
	if(val<ptr->data)
	ptr->left=newn;
	else 
	ptr->right=newn;
	}
return root;
}
struct node *delete(int val)
{
struct node *temp=root,*ptr;
while(temp!=NULL)
{
ptr=temp;
if(temp->data==val)
break;
else if(val<temp->data)temp=temp->left;
else if(val>temp->data)temp=temp->right;
}
if(temp==NULL)
{
printf("The entered value is not found in the tree");
}
else if(temp->left==NULL&&temp->right ==NULL)
{
free(temp);
}
else if(temp->right==NULL&&temp->left!=NULL)
{
if(temp==ptr->left)
ptr->left=temp->left;
else ptr->right=temp->left;
free(temp);
}
else if(temp->left==NULL&&temp->right!=NULL)
{
if(temp==ptr->right)
ptr->right=temp->right;
else ptr->right=temp->left;
free(temp);
}
else 
{
struct node *t=temp->left,*p;int dtaa;
while(t->right!=NULL)
{
p=t;
t=t->right;
}

dtaa=temp->data;
temp->data=t->data;
t->data=dtaa;

p->right=t->left;


free(t);

}
return root;
}

void main()
{	int choice,val;
	printf("***************Menu************\n1.Insert\n2.Delete\n3:exit\n");
	printf("\nEnter choice:");
	scanf("%d",&choice);
	while(choice!=3)
	{
	printf("\nEnter choice:");
	scanf("%d",&choice);switch(choice)
	{
		case 1:	printf("\nEnter value:");
			scanf("%d",&val);
			
			root =insert(val);printInorder(root);
				break;
		case 2:
				printf("\nEnter value");scanf("%d",&val);
			root=	delete(val);
printInorder(root);
break;
case 3: break;
}}
}
/*
OUTPUT:
***************Menu************
1.Insert
2.Delete
3:exit

Enter choice:1

Enter choice:1

Enter value:100
100 
Enter choice:1

Enter value:50
50 100 
Enter choice:1

Enter value:125
50 100 125 
Enter choice:1

Enter value:125
50 100 125 125 
Enter choice:1

Enter value:150
50 100 125 125 150 
Enter choice:1

Enter value:25
25 50 100 125 125 150 
Enter choice:1

Enter value:75
25 50 75 100 125 125 150 
Enter choice:1

Enter value:80
25 50 75 80 100 125 125 150 
Enter choice:2

Enter value100
25 50 75 80 125 125 150 
Enter choice:
*/





 
