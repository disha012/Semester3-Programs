#include<stdio.h>
#define max 5
int q[max],f=-1,r=-1;
int empty(int q[])
{
	if (r==-1)
		return 1;
	else 
		return 0;
}
void enqueue(int q[],int val)
{
	if(r==max-1)
		printf("Overflow\n");
	if( r==-1)
	{
		f=0;
		r=0;
	}
	else
		r++;
	q[r]=val;
}
int dequeue(int q[])
{
	if( r==-1)
	{
		printf("Underflow\n");
		return 0;
	}
	int val=q[f];
	if(f==r)
	{
		f=-1;
		r=-1;
	}
	else
		f++;
	return val;
}
void bfs(int adj[][max],int visit[],int i,int n)
{
	int j;
	enqueue(q,i);
	visit[i]=1;
	printf("%c\t",i+65);
	while(!empty(q))
	{
		int v=dequeue(q);
		for(j=0;j<n;j++)
		{
			if(visit[j]==0 &&adj[v][j]!=0)
			{
				enqueue(q,j);
				visit[j]=1;
				printf("%c\t",j+65);
			}
		}
	}
}
void main()
{
	int i,j,n;
	int adj[max][max];
	int visit[max]={0};
	printf("Enter the no of vertices\n");
	scanf("%d",&n);
	printf("Enter adj matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&adj[i][j]);
		}
	}
	printf("Adj Matrix is:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d",adj[i][j]);
		}
		printf("\n");
	}
	printf("BFS traversal:\n");
	bfs(adj,visit,0,n);
}
