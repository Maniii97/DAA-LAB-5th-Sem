#include <stdio.h>
#include <stdlib.h>

void makeBinary(char* s, int n, int* idx){
    if(n > 0){
        makeBinary(s,n/2,idx);
        s[*(idx)++] = (n%2) + '0';
    }
}

int isPalindrome(char* s, int i, int j){
    if(i >= j) return 1;
    if(s[i] != s[j]) return 0;

    return isPalindrome(s, i+1, j-1);
}

int main(){
    int n;
    char s[32];
    int idx = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    makeBinary(s, n, &idx);
    s[idx] = '\0';

    int ans = isPalindrome(s, 0, idx-1);
    if(ans) printf("Binary of %d is Palindrome \n",n);
    else printf("Binary of %d is NOT Palindrome \n",n);
}