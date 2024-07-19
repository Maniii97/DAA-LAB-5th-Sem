#include <stdio.h>
int main(){
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int px[n];
    px[0] = arr[0];
    for (int i = 1; i < n; i++){
        px[i] = px[i - 1] + arr[i];
    }
    printf("The prefix sum array is: ");
    for(int i=0;i<n;i++){
        printf("%d ", px[i]);
    }
}