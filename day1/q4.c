#include <stdio.h>
void exchange(int *p, int *q){
    *p = *p ^ *q;
    *q = *p ^ *q;
    *p = *p ^ *q;
}
void rotate_right(int arr[], int n){
    for(int i=n-1;i>0;i--){
        exchange(&arr[i], &arr[i-1]);
    }
}
int main(){
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("enter number of elements to rotate right: ");
    int k;
    scanf("%d", &k);
    rotate_right(arr, k);
    printf("The array after rotating right by 1 position is: ");
    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
}