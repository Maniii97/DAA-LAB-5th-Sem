#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int h){
    int temp[h-l+1];
    int lo = l, hi = m+1;

    int idx = 0;

    while(lo <= m && hi <= h){
        if(arr[lo] > arr[hi]){
            temp[idx++] = arr[lo];
            lo++;
        } else {
            temp[idx++] = arr[hi];
            hi++;
        }
    }
    while(lo <= m){
        temp[idx++] = (arr[lo]);
        lo++;
    }
    while(hi <= h){
        temp[idx++] = (arr[hi]);
        hi++;
    }
    for(int i = l; i <= h; i++){
        arr[i] = temp[i-l];
    }
}

void merge_sort(int arr[], int l, int h){
    if(l < h){
        int m = l + (h-l)/2;
        merge_sort(arr, l, m);
        merge_sort(arr, m+1, h);
        merge(arr, l, m, h);
    }
}

int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];

    for(int i=0;i<n;i++){
        arr[i] = random() % 100;
    }

    merge_sort(arr, 0, n-1);
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}