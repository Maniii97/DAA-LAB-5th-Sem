#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int item_id;
    double item_profit;
    double item_weight;
    double profit_weight_ratio;
} ITEM;

void swap(ITEM* a, ITEM* b) {
    ITEM temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(ITEM arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].profit_weight_ratio < arr[smallest].profit_weight_ratio)
        smallest = left;

    if (right < n && arr[right].profit_weight_ratio < arr[smallest].profit_weight_ratio)
        smallest = right;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        heapify(arr, n, smallest);
    }
}

void heapSort(ITEM arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}
void printHeap(ITEM arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d %lf %lf %lf\n", arr[i].item_id, arr[i].item_profit, arr[i].item_weight, arr[i].profit_weight_ratio);
}

int main() {
    int n;
    double capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    ITEM* items = (ITEM*)malloc(n * sizeof(ITEM));

    for (int i = 0; i < n; i++) {
        printf("Enter the profit and weight of item no %d: ", i + 1);
        scanf("%lf %lf", &items[i].item_profit, &items[i].item_weight);
        items[i].item_id = i + 1;
        items[i].profit_weight_ratio = items[i].item_profit / items[i].item_weight;
    }

    printf("Enter the capacity of knapsack: ");
    scanf("%lf", &capacity);

    heapSort(items, n);

    printf("\nItems sorted by profit/weight ratio:\n");
    printHeap(items, n);

    double total_profit = 0.0;
    double remaining_capacity = capacity;

    printf("Item No\t\tProfit\t\tWeight\t\tAmount to be taken\n");

    for (int i = 0; i < n; i++) {
        if (remaining_capacity == 0){
            while(i < n){
                printf("%d\t\t%.6lf\t%.6lf\t%.6lf\n", items[i].item_id, items[i].item_profit, items[i].item_weight, 0.0);
                i++;
            }
            break;
        }

        double amount_taken = 0.0;
        if (items[i].item_weight <= remaining_capacity) {
            amount_taken = 1.0;
            remaining_capacity -= items[i].item_weight;
            total_profit += items[i].item_profit;
        } else {
            amount_taken = remaining_capacity / items[i].item_weight;
            total_profit += items[i].item_profit * amount_taken;
            remaining_capacity = 0;
        }

        printf("%d\t\t%.6lf\t%.6lf\t%.6lf\n", items[i].item_id, items[i].item_profit, items[i].item_weight, amount_taken);
    }

    printf("\nMaximum profit: %.6lf\n", total_profit);

    free(items);
    return 0;
}