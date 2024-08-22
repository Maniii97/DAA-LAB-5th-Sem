// Write a menu driven program to sort list of array elements using Merge Sort
// and calculate the execution time only to sort the elements.  
// Count the number of comparisons. 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

// Global variable to keep track of comparisons
int comparisons = 0;

void merge(int arr[], int left, int mid, int right, int ascending) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        comparisons++;
        if ((ascending && L[i] <= R[j]) || (!ascending && L[i] >= R[j])) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }

    free(L);
    free(R);
}

void merge_sort(int arr[], int left, int right, int ascending) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid, ascending);
        merge_sort(arr, mid + 1, right, ascending);

        merge(arr, left, mid, right, ascending);
    }
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[MAX_SIZE];
    int n;
    int choice;
    int order;
    clock_t start, end;
    double cpu_time_used;

    do {
        printf("Menu:\n");
        printf("1. Enter elements\n");
        printf("2. Sort elements using Merge Sort\n");
        printf("3. Display elements\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of elements (max %d): ", MAX_SIZE);
                scanf("%d", &n);
                if (n > MAX_SIZE) {
                    printf("Number of elements exceeds maximum size.\n");
                    break;
                }
                printf("Enter %d elements:\n", n);
                for (int i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }
                break;

            case 2:
                printf("Choose sorting order:\n");
                printf("1. Ascending\n");
                printf("2. Descending\n");
                printf("Enter your choice: ");
                scanf("%d", &order);

                if (order != 1 && order != 2) {
                    printf("Invalid choice for sorting order.\n");
                    break;
                }

                start = clock();
                comparisons = 0;  // Reset comparison count
                merge_sort(arr, 0, n - 1, order == 1);
                end = clock();
                cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000.0;
                
                printf("Sorted array: \n");
                print_array(arr, n);
                printf("Time taken to sort: %lf seconds\n", cpu_time_used);
                printf("Number of comparisons: %d\n", comparisons);
                break;

            case 3:
                printf("Current elements: \n");
                print_array(arr, n);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
