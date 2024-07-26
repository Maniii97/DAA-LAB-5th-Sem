#include <stdio.h>

void findBinary(int n, int maxBits, FILE *fptr){
    if (maxBits > 1) {
        findBinary(n / 2, maxBits - 1, fptr);
    }
    fprintf(fptr, "%d", n % 2);
}

int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    FILE *fptr;
    fptr = fopen("input.txt", "r");
    if(fptr == NULL){
        printf("Error opening file\n");
        return 1;
    }
    int arr[n];
    for(int i=0; i<n; i++){
        fscanf(fptr, "%d", &arr[i]);
    }
    fclose(fptr);

    int maxBits = 16;

    FILE *outfptr;
    outfptr = fopen("output.txt", "w");
    if(outfptr == NULL){
        printf("Error opening output file\n");
        return 1;
    }

    for(int i=0; i<n; i++){
        fprintf(outfptr, "The binary equivalent of %d is ", arr[i]);
        findBinary(arr[i], maxBits, outfptr);
        fprintf(outfptr, "\n");
    }
    fclose(outfptr);

    printf("Binary representation has been written to output.txt\n");
    return 0;
}