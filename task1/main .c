/*Exponential function using taylor series:
Without using functions, you are required to write a code to calculate the exponential function using Taylor series. 
Your program is required to ask the use to enter the exponent and the number of iteration and then print the exponential result.*/
#include <stdio.h>
// power fun to return the nominator x^n of term n
float power(float x, int n){
    int i;
    float nom=1.0;
    for(i=1;i<=n;i++){
        nom*=x;
    }
    return nom;
}
// fact fun to retern the denominator factor n! of term n
int fact(int n){
    int i, denom=1;
    for(i=1;i<=n;i++){
        denom*=i;
    }
    return denom;
}
void tailor(float x,int n){
    int i;
    float term,sum=1;
    if (n==0){
        printf("1");
    }
    for(i=1;i<n;i++){
        term=(power(x,i)/fact(i));
        sum+=term;
        printf(" + (%0.1f)^%d/%d!",x,i,i);
    }
    printf(" = %0.3f",sum);
}
int main(void){
    // e^x = 1 + x/1! + x^2/2! + x^3/3! + ...... unti n terms
    int n,i; 
    float x;
    float exp=1 ;
    printf("ENTER THE POWER x : ");
    scanf("%f",&x);
    printf("ENTER THE NUMBER OF TERMS n : ");
    scanf("%d",&n);
    // printf("%f\n",power(x,n));
    // printf("%d\n",fact(n));
    printf("TAILOR EXPANTION OF e^%0.1f OF FIRST %d TERMS =\n 1",x,n);
    tailor(x,n);

    return 0;    
}