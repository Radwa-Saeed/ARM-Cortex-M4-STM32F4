/* 1- Write a program to perform a generic rotate right and rotate left expression using bit masking.
    The code shall ask the user to enter an 8 bit number x, number of rotate cycles num and rotate
    option o. The software shall print the rotate value of x, num times based on the value of o.*/
/*let num = 10011100 to be shifted left by shifts =3
   the result of (num<<shifts ) = 11100000 
   the result of (num>>(bits-shifts ))=(num>>5) =00000 100
   then oring (masking) both of results to add the rptated bits ==> 11100100 
   */
#include <stdio.h>
/*Function to rotate left num by shifts  bits*/
int leftRotate(signed int num, unsigned int shifts , int bits)
{
    return (num << shifts ) | (num >> (bits - shifts ));
}
/*Function to right rotate num by shifts  bits*/
int rightRotate(signed int num, unsigned int shifts , int bits)
{
    return (num >> shifts ) | (num << (bits - shifts ));
}
// ******* FOR TESTING ********* // left=*2 ... right=*0.5
// Left Rotation of 28 by 2 is 112 
// Right Rotation of 28 by 2 is 7 ===> 1799 ... due to overflow (8 bit ==> 32 bit)
// Left Rotation of 16 by 2 is 64
// Right Rotation of 16 by 2 is 4 ====> 1028
int main()
{
    signed int num;
    unsigned int shifts , option;
    int bits=8; 
    printf(">> ENTER 8 BIT NUMBER:");
    scanf("%d",&num);
    printf(">> ENTER THE NUMBER OF ROTATES: ");
    scanf("%d",&shifts);
    printf(">> SELECT AN OPTION OF ROTATE ...\n>>FOR ROTATE LEFT PRESS 0\n>>FOR ROTATE RIGHT PRESS 1\n");
    scanf("%d",&option);
    switch (option)
    {
    case 0:
        printf("%d ", leftRotate(num, shifts,bits));
        break;
    case 1:
        printf("%d", rightRotate(num, shifts,bits));
        break;
    default:
        printf(">>SORRY, COULDN'T UNDERSTAND YOUR INPUT");
        break;
    }
    return 0;
}