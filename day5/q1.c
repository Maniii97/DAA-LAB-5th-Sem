#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int item_id;
    double item_profit;
    double item_weight;
} ITEM;

int comp(const void* a, const void* b) {
    ITEM* itemA = (ITEM*)a;
    ITEM* itemB = (ITEM*)b;
    double r1 = itemA->item_profit / itemA->item_weight;
    double r2 = itemB->item_profit / itemB->item_weight;
    if (r1 < r2) return 1;
    if (r1 > r2) return -1;
    return 0;
}

int main() {
    int n;
    double capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    ITEM items[n];

    for (int i = 0; i < n; i++) {
        printf("Enter the profit and weight of item no %d: ", i + 1);
        scanf("%lf %lf", &items[i].item_profit, &items[i].item_weight);
        items[i].item_id = i + 1;
    }

    printf("Enter the capacity of knapsack: ");
    scanf("%lf", &capacity);

    qsort(items, n, sizeof(ITEM), comp);
    printf("\nItems sorted by profit/weight ratio:\n");

    for(int i=0;i<n;i++){
        printf("Item %d: Profit: %lf, Weight: %lf\n",items[i].item_id,items[i].item_profit,items[i].item_weight);
    }

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