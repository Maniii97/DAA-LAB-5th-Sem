#include <stdio.h>
int main(){
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    int count[100] = {0};
    FILE *file;
    file = fopen("input.txt", "r");
    if (file == NULL){
        printf("File not found\n");
        return 1;
    }
    for (int i = 0; i < n; i++){
        fscanf(file, "%d", &arr[i]);
    }
    for (int i = 0; i < n; i++){
        count[arr[i]]++;
    }
    int duplicates = 0;
    int maxCount = 0;
    int maxi = 0;
    for (int i = 0; i < 100; i++){
        if (count[i] > 1){
            duplicates++;
        }
        if(count[i] > maxCount){
            maxCount = count[i];
            maxi = i;
        }
    }
    if(duplicates == 0) printf("There are no duplicate elements in the array\n");
    else printf("The number of duplicate elements in the array is: %d\n", duplicates);
    
    if(maxCount == 1) printf("All elements are unique\n");
    else printf("The element that occurs the maximum number of times is: %d\n", maxi);
}