#include<stdio.h>
int fibo(int n){
    if(n == 0 || n==1 ) return n;
    return fibo(n-1)+fibo(n-2);
}
int main(){
    int n;
    printf("enter limit ");
    scanf("%d",&n);
    if(n<0) printf("wrong limit, enter a positive value");
    for(int i=0;i<n;i++){
        printf("%d ",fibo(i));
    }    
    return 0;
}