#include<stdio.h>
int fact(int n){
    if(n == 0 || n==1 ) return n;
    return n*fact(n-1);
}
int main(){
    printf("input a number");
    int n;
    scanf("%d",&n);
    if(n<0){
        printf("factorial of negative number is not possible");
        return 0;
    }
    printf("factorial of %d is %d",n,fact(n));
    return 0;
}