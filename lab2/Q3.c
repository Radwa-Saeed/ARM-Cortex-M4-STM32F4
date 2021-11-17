/* 3- The Fibonacci series 0, 1, 1, 2, 3, 5, 8, 13, 21, … begins with the terms 0 and 1 and has the
    property that each succeeding term is the sum of the two preceding terms. a) Write a code that
    print the number of series terms after reading it from a user input.
*/
// Fn = Fn-1 + Fn-2
#include <stdio.h>

int main(){
    int terms, i, a=0, b=1, new;
    printf("ENTER N OF TERMS ");
    scanf("%d",&terms);
    for(i=0;i<=terms;i++){
        if(i==0){
            printf("%d, ",a);
        }
        else if (i==1){
            printf("%d, ",b);
        }
        else{
            new=a+b;
            printf("%d, ",new);
            a=b;
            b=new;
        }
        
    }
    printf("..."); 
    return 0;
}