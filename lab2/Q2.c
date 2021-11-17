/* 2- Write a program that prints the following diamond shape. You may use printf statements that
    print either a single asterisk (*) or a single blank. Maximize your use of iteration (with nested for
    statements) and minimize the number of printf statements.*/
/* **** Method 1 *********
int i, j;
    for (i = 1; i <= 5; i++){
        for (j = 1; j <= 9; j++){
            if ((j <= 5 - i) || (j >= 5 + i)){
                printf(" ");
            }
            else{
                printf("*");
            }
        }
        printf("\n");
    }
    for (i = 1; i <= 4; i++){
        for (j = 1; j <= 9; j++){
            if ((j <= i) || (j >= 10 - i)){
                printf(" ");
            }
            else{
                printf("*");
            }
        }
        printf("\n");
    }*/
// ******* Method 2 **********   
#include <stdio.h>
int main(){
    int row,column;
    for(row=-4;row<=4;row++){
        for(column=-4;column<=4;column++){
            if(row<=column+4 && row>=column-4 && row<=-column+4 && row>=-column-4){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}