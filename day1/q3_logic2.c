#include <stdio.h>
int main(){
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i] < arr[j]){
                arr[i] = arr[i] ^ arr[j];
                arr[j] = arr[i] ^ arr[j];
                arr[i] = arr[i] ^ arr[j];
            }
        }
    }
    int duplicates = 0;
    int ele = arr[0];
    int maxi = 0;
    for(int i=0;i<n;i++){
        int occ = 0;
        if(arr[i] == arr[i+1]){
            duplicates++;
        }
        while(arr[i] == arr[i+1]){
            i++;
            occ++;
        }
        if(occ > maxi){
            maxi = occ;
            ele = arr[i-1];
        }
    }
    if(duplicates == 0) printf("There are no duplicate elements in the array\n");
    else printf("The number of duplicate elements in the array is: %d\n", duplicates);
    printf("The element that occurs the maximum number of times is: %d\n", ele);
}