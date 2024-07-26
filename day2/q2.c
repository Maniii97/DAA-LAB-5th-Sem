#include <stdio.h>
int gcd(int a , int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}
int main(){
    FILE *fptr;
    fptr = fopen("input2.txt", "r");
    if(fptr == NULL){
        printf("Error opening file\n");
        return 1;
    }
    int a, b;
    fscanf(fptr, "%d %d", &a, &b);
    fclose(fptr);
    fptr = fopen("output2.txt", "w");
    fprintf(fptr, "The gcd of %d and %d is %d", a, b, gcd(a, b));
    fclose(fptr);

    printf("GCD has been written to output2.txt\n");
}