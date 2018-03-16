/*
When a function calls itself, its called Recursion.
Recursion is useful in solving problems which can be broken down into smaller problems of the same kind. But when it comes to solving problems using Recursion there are several things to be taken care of. Let's take a simple example and try to understand those. Following is the pseudo code of finding factorial of a given number X using recursion.
function factorial(x)
    if x is 0                    // base case
        return 1
    return x*factorial(x-1)       // break into smaller problem(s)
Base Case: Any recursive method must have a terminating condition. Terminating condition is one for which the answer is already known and we just need to return that. For example for the factorial problem, we know that 
factorial(0)=1
so when x is 0 we simply return 1, otherwise we break into smaller problem i.e. find factorial of x?1. If we don't include a Base Case, the function will keep calling itself, and ultimately will result in stack overflow. 
Number of Recursive calls: There is an upper limit to the number of recursive calls that can be made. To prevent this make sure that your base case is reached before stack size limit exceeds.
So, if we want to solve a problem using recursion, then we need to make sure that:
·	The problem can be broken down into smaller problems of same type.
·	Problem has some base case(s).
·	Base case is reached before the stack size limit exceeds.
*/


#include<stdio.h>
void reverse(char *str)
{
   if (*str)
   {
       reverse(str+1);
       printf("%c", *str);
   }
}
void main()
{
char a[100];
printf("Enter the string to be reversed\n");
scanf("%[^\n]",a);
reverse(a);
}
/*
OUTPUT:
Enter the string to be reversed
I play football
llabtoof ylap I

*/
