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
    int maxi = arr[0], mini = arr[0];
    for (int i = 1; i < n; i++){
        if (arr[i] > maxi) maxi = arr[i];
        if (arr[i] < mini) mini = arr[i];
    }
    for(int i=0;i<n;i++){
        if(arr[i] == maxi) arr[i] = mini;
    }
    int secondMax = arr[0];
    for(int i=0;i<n;i++){
        if(arr[i] > secondMax) secondMax = arr[i];
    }
    for(int i=0;i<n;i++){
        if(arr[i] == mini) arr[i] = maxi;
    }
    int secondMin = arr[0];
    for(int i=0;i<n;i++){
        if(arr[i] < secondMin) secondMin = arr[i];
    }
    printf("The second largest element in the array is: %d\n", secondMax);
    printf("The second smallest element in the array is: %d\n", secondMin);
}