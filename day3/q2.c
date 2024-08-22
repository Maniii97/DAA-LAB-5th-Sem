#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int comparisons = 0;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

int read_from_file(const char* filename, int arr[]) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Unable to open file %s for reading.\n", filename);
        return -1;
    }

    int n = 0;
    while (fscanf(file, "%d", &arr[n]) != EOF && n < MAX_SIZE) {
        n++;
    }

    fclose(file);
    return n;
}

void write_to_file(const char* filename, int arr[], int size) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Unable to open file %s for writing.\n", filename);
        return;
    }

    for (int i = 0; i < size; i++) {
        fprintf(file, "%d\n", arr[i]);
    }

    fclose(file);
}

void print_array(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Unable to open file %s for reading.\n", filename);
        return;
    }

    int num;
    printf("Sorted elements:\n");
    while (fscanf(file, "%d", &num) != EOF) {
        printf("%d ", num);
    }
    printf("\n");

    fclose(file);
}

void analyze_partition(int low, int high, int pivot_index) {
    int size = high - low + 1;
    if (pivot_index == low + size / 2) {
        printf("Partitioning is likely best-case.\n");
    } else if (pivot_index == low || pivot_index == high) {
        printf("Partitioning is likely worst-case.\n");
    } else {
        printf("Partitioning is neither best-case nor worst-case.\n");
    }
}

int main() {
    int arr[MAX_SIZE];
    int n;
    int choice;
    int order;
    const char* input_filename = "input.txt";
    const char* output_filename = "output.txt";

    do {
        printf("Menu:\n");
        printf("1. Read data from file\n");
        printf("2. Sort elements using Quick Sort\n");
        printf("3. Display sorted elements\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                n = read_from_file(input_filename, arr);
                if (n == -1) {
                    printf("Failed to read from file.\n");
                } else {
                    printf("Data read successfully from file.\n");
                }
                break;

            case 2:
                if (n <= 0) {
                    printf("No data available to sort.\n");
                    break;
                }

                printf("Starting Quick Sort...\n");
                comparisons = 0;

                quick_sort(arr, 0, n - 1);

                write_to_file(output_filename, arr, n);

                analyze_partition(0, n - 1, n - 1);

                printf("Sorting completed.\n");
                break;

            case 3:
                if (n <= 0) {
                    printf("No data available to display.\n");
                    break;
                }

                print_array(output_filename);

                printf("Number of comparisons: %d\n", comparisons);
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
