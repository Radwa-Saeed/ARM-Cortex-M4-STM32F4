#include <stdio.h>
#include "main.h"

// #include "fun.h"
int main(void)
{
    // ############ calculate v and s #############
    float u, a, t;
    printf("ENTER THE INITIAL VELOCITY...\n");
    scanf("%f", &u);
    printf("ENTER THE ACCELERATION ...\n");
    scanf("%f", &a);
    printf("ENTER THE DISTANCE...\n");
    scanf("%f", &t);
    finalVelocity(u, a, t);

    // ########### calculate sum, avg, prod, max and min ##########
    // int num1, num2, num3;
    // printf("ENTER THREE DIFFERENT NUMBERS ... ");
    // scanf("%d  %d  %d", &num1, &num2, &num3); // space between specifiers means you should seperate your input numbers by spaces
    // calculat(num1, num2, num3);

    // ########### calculate time from seconds
    // int seconds;
    // printf("PLEASE ENTER THE TOTAL TIME ELAPSED IN SECONDS ... ");
    // scanf("%d", &seconds);
    // time(seconds);

    return 0;
    getchar();
};
