#include<stdio.h>
int fact(int n){
    if(n == 0 || n==1 ) return n;
    return n*fact(n-1);
}
int main(){
    printf("input a number");
    int n;
    scanf("%d",&n);
    return 0;
}