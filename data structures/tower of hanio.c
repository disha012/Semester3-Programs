/*
Tower of Hanoi:
In our Towers of Hanoi solution, we recurse on the largest disk to be moved. That is, we will write a recursive function that takes as a parameter the disk that is the largest disk in the tower we want to move. Our function will also take three parameters indicating from which peg the tower should be moved (source), to which peg it should go (dest), and the other peg, which we can use temporarily to make this happen (spare).
At the top level, we will want to move the entire tower, so we want to move disks 5 and smaller from peg A to peg B. We can break this into three basic steps.
In pseudocode, this looks like the following. At the top level, we'll call MoveTower with disk=5, source=A, dest=B, and spare=C.
FUNCTION MoveTower(disk, source, dest, spare):
IF disk == 0, THEN:
    move disk from source to dest
ELSE:
    MoveTower(disk - 1, source, spare, dest)   // Step 1 above
    move disk from source to dest              // Step 2 above
    MoveTower(disk - 1, spare, dest, source)   // Step 3 above
END IF
Note that the pseudocode adds a base case: When disk is 0, the smallest disk. In this case we don't need to worry about smaller disks, so we can just move the disk directly. In the other cases, we follow the three-step recursive procedure we already described for disk 5.

*/


#include<stdio.h>
void towerofhanoi(int n, char source, char dest, char spare)
{
    if (n == 1)
    {
        printf("Move disk 1 from rod %c to rod %c\n", source, dest);
        return;
    }
    towerofhanoi(n-1, source,spare, dest);
    printf("Move disk %d from rod %c to rod %c\n", n, source, dest);
    towerofhanoi(n-1,spare, dest, source);
}
 int main()
{
    int n = 4;
    towerofhanoi(n, 'A', 'C', 'B');
    return 0;
}

/*
OUTPUT:
Move disk 1 from rod A to rod B
Move disk 2 from rod A to rod C
Move disk 1 from rod B to rod C
Move disk 3 from rod A to rod B
Move disk 1 from rod C to rod A
Move disk 2 from rod C to rod B
Move disk 1 from rod A to rod B
Move disk 4 from rod A to rod C
Move disk 1 from rod B to rod C
Move disk 2 from rod B to rod A
Move disk 1 from rod C to rod A
Move disk 3 from rod B to rod C
Move disk 1 from rod A to rod B
Move disk 2 from rod A to rod C
Move disk 1 from rod B to rod C
*/
