
/*
To convert infix to postfix
1. Print operands as they arrive.
2. If the stack is empty or contains a left parenthesis on top, push the incoming operator onto the stack.
3. If the incoming symbol is a left parenthesis, push it on the stack.
4. If the incoming symbol is a right parenthesis, pop the stack and print the operators until you see a left parenthesis. Discard the pair of parentheses.
5. If the incoming symbol has higher precedence than the top of the stack, push it on the stack.
6. If the incoming symbol has equal precedence with the top of the stack, use association. If the association is left to right, pop and print the top of the stack and then push the incoming operator. If the association is right to left, push the incoming operator.
7. If the incoming symbol has lower precedence than the symbol on the top of the stack, pop the stack and print the top operator. Then test the incoming operator against the new top of stack.
8. At the end of the expression, pop and print all operators on the stack. (No parentheses should remain.)
To evaluate postfix expression
1. Make an empty stack implemented as a linked list.
2. Get an input postfix expression from the user.
3. Scan the expression from left to right.
4. During your scanning:
a. If you encounter an operand, push it on to the stack and continue scanning. 
b. If you encounter an operator, pop only the topmost two elements from the stack, apply the operator on the elements and push the result back to the stack.
5. When you reach the end of the string, there should be only one element on to the stack. Pop this value to get the result of your postfix expression.
 A * (B + C * D) + E becomes A B C D * + * E +

*/

#include<stdio.h>
#include<string.h>
char post[10000];
int top=-1;
char a[10000];int n=0;
int isempty() {

	if(top==-1)
	return 1;
	else return 0;
}
void push (char val) {
		top++;
		n++;
		a[top]=val;
}
char pop() {
	if(top!=-1)
	{
		n--;
		return a[top--];
	}
}
void infixtopost(char ar[])
{
	char x;int i;
	int f=0;
	for( i=0;ar[i]!='\0';i++)
		{
			if(ar[i]=='(')
			push(ar[i]);
			else if(ar[i]=='+'||ar[i]=='-')
				{
				if(a[top]=='*'||a[top]=='/')
					{
					post[f++]=pop();
					push(ar[i]);
					}
				else
				push(ar[i]);
				}
			else if(ar[i]=='/'||ar[i]=='*')
				{
					push(ar[i]);
				}
			else if((ar[i]>='a'&&ar[i]<='z')||(ar[i]>='0'&&ar[i]<='9'))
				{
				post[f++]=ar[i];
				}
			else if(ar[i]==')')
				{

				while(a[top]!='('&&top!=-1)
					{
					post[f++]=a[top];
					top--;
					}
				x=pop();
				}

			else
			{
			printf("invalid char %c",ar[i]);
			break;
			}

		}
	if(top!=-1)
	{
	while(top!=-1)
	{
	    post[f++]=pop();
	}
	post[f]='\0';
	}
	printf("%s\n",post);
}
void evalve(char ar[])
{
int i;int op1,op2,ans;
for( i=0;ar[i]!='\0';i++)
{
    if((ar[i]>='0'&&ar[i]<='9'))
    {
        push((int)ar[i]-'0');
    }
    else
    {
        op1=pop();
        op2=pop();
        switch(ar[i])
        {
            case '+':   ans=op1+op2;break;
            case '-':   ans=op2-op1;break;
            case '*':   ans=op1*op2;break;
            case '/':   ans=op2/op1;break;
        }
        push(ans);
    }
}
printf("%d\n",a[top]);
}
void main()
{
char ar[10000];
printf("Enter the expression");
scanf("%s",ar);
infixtopost(ar);
evalve(post);
}
/*
OUTPUT:
Enter the expression7-(2*3+5)*(8-4/2)
723*5+842/-*-
-59
*/


































