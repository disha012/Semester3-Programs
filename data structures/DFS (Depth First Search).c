
#include<stdio.h>
int q[20],top=-1,front=-1,rear=-1,a[20][20],vis[20],stack[20]; 
void add(int item); 
void bfs(int s,int n); 
void dfs(int s,int n); 
void push(int item); 
int pop();
int main() 
{
	int n,i,s,ch,j;
	char c;
	printf("Enter The Number Of Vertices: "); 
	scanf("%d",&n); 
	for(i=1;i<=n;i++) 
	{ 
		for(j=1;j<=n;j++) 
		{ 
			printf("Enter 1 If %d Has a Node With %d Else 0 ",i,j); 
			scanf("%d",&a[i][j]); 
		} 
	} 
	printf("The Adjacency Matrix Is\n"); 
	for(i=1;i<=n;i++) 
	{ 
		for(j=1;j<=n;j++) 
		{ 
			printf(" %d",a[i][j]); 
		} 
		printf("\n"); 
	} 
	for(i=1;i<=n;i++) 
		vis[i]=0; 
	printf("Enter The Source Vertex :"); 
	scanf("%d",&s); 
	dfs(s,n);
}

void dfs(int s,int n) 
{ 
	int i,k; 
	push(s); 
	vis[s]=1; 
	k=pop(); 
	if(k!=0) 
		printf(" %d ",k); 	
		while(k!=0) 
		{ 
			for(i=1;i<=n;i++) 
			if((a[k][i]!=0)&&(vis[i]==0)) 
			{ 
				push(i); 
				vis[i]=1; 
			} 
			k=pop(); 
			if(k!=0) 
			printf(" %d ",k); 
		} 
		for(i=1;i<=n;i++) 
		if(vis[i]==0) 
		dfs(i,n); 
} 

void push(int item) 
{ 
	if(top==19) 
		printf("Stack Overflow "); 
	else 
		stack[++top]=item; 
} 

int pop() 
{ 
	int k; 
	if(top==-1) 
		return(0); 
	else 
	{ 
		k=stack[top--]; 
		return(k); 
	} 
}

/*
Output:

Enter The Number Of Vertices: 5
Enter 1 If 1 Has a Node With 1 Else 0 0
Enter 1 If 1 Has a Node With 2 Else 0 1
Enter 1 If 1 Has a Node With 3 Else 0 1
Enter 1 If 1 Has a Node With 4 Else 0 0
Enter 1 If 1 Has a Node With 5 Else 0 0
Enter 1 If 2 Has a Node With 1 Else 0 0
Enter 1 If 2 Has a Node With 2 Else 0 0
Enter 1 If 2 Has a Node With 3 Else 0 0
Enter 1 If 2 Has a Node With 4 Else 0 0
Enter 1 If 2 Has a Node With 5 Else 0 1
Enter 1 If 3 Has a Node With 1 Else 0 0
Enter 1 If 3 Has a Node With 2 Else 0 0
Enter 1 If 3 Has a Node With 3 Else 0 0
Enter 1 If 3 Has a Node With 4 Else 0 1
Enter 1 If 3 Has a Node With 5 Else 0 0
Enter 1 If 4 Has a Node With 1 Else 0 1
Enter 1 If 4 Has a Node With 2 Else 0 0
Enter 1 If 4 Has a Node With 3 Else 0 0
Enter 1 If 4 Has a Node With 4 Else 0 0
Enter 1 If 4 Has a Node With 5 Else 0 0
Enter 1 If 5 Has a Node With 1 Else 0 0
Enter 1 If 5 Has a Node With 2 Else 0 0
Enter 1 If 5 Has a Node With 3 Else 0 0
Enter 1 If 5 Has a Node With 4 Else 0 0
Enter 1 If 5 Has a Node With 5 Else 0 0
The Adjacency Matrix Is
 0 1 1 0 0
 0 0 0 0 1
 0 0 0 1 0
 1 0 0 0 0
 0 0 0 0 0
Enter The Source Vertex : 0  1  3  4  2  5 

*/
