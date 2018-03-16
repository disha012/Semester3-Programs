/*
Euclid's GCD algorithm
Now any divisor d common to m and n must divide the first term with no remainder, since it is the product of n and an integer. Therefore, d must also divide the second term since d divides m and m is the sum of the two terms.
Since any divisor common to m and n must divide the remainder of m/n, we know that, in particular, the gcd does, since it is a common divisor. It just happens to be the greatest such divisor.
So by taking the GCD(n, remainder of m/n), we can "close in quickly" on the GCD of m and n. 
Now we can write:
int gcd(int m, int n) {
   if ((m % n) == 0)
      return n;
   else
      return gcd(n, m % n);
}

gcd(468, 24)
gcd(24, 12)
=> 12
*/

#include<stdio.h>
int gcd(int x,int y)
{
if(x%y==0)
return y;
else return gcd(y,x%y);
}
void main()
{
int x,y;
printf("Enter the two values for which GCD is to be calculated\n");
scanf("%d%d",&x,&y);
int r=gcd(x,y);
printf("The GCD is %d\n",r);
}
/*
OUTPUT:
Enter the two values for which GCD is to be calculated
22
12
The GCD is 2
*/
