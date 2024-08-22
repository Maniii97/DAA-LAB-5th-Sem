#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
    int id;
    char name[50];
    int age;
    int height;
    int weight;
};

void swap(struct person* a, struct person* b) {
    struct person temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(struct person* heap, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left].age < heap[smallest].age)
        smallest = left;

    if (right < n && heap[right].age < heap[smallest].age)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        minHeapify(heap, n, smallest);
    }
}

void maxHeapify(struct person* heap, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left].weight > heap[largest].weight)
        largest = left;

    if (right < n && heap[right].weight > heap[largest].weight)
        largest = right;

    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        maxHeapify(heap, n, largest);
    }
}

void buildMinHeap(struct person* heap, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(heap, n, i);
}

void buildMaxHeap(struct person* heap, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(heap, n, i);
}

void insertMinHeap(struct person** heap, int* n, struct person newPerson) {
    *n += 1;
    *heap = realloc(*heap, *n * sizeof(struct person));
    int i = *n - 1;
    (*heap)[i] = newPerson;

    while (i != 0 && (*heap)[(i - 1) / 2].age > (*heap)[i].age) {
        swap(&(*heap)[i], &(*heap)[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}
void deleteOldest(struct person** minHeap, int* minHeapSize) {
    if (*minHeapSize == 0) {
        printf("Heap is empty.\n");
        return;
    }
    *minHeapSize -= 1;
    *minHeap = realloc(*minHeap, *minHeapSize * sizeof(struct person));
    if (*minHeapSize > 0) {
        minHeapify(*minHeap, *minHeapSize, 0);
    }
}

void displayYoungestPersonWeight(struct person* heap, int n) {
    if (n == 0) {
        printf("Heap is empty.\n");
        return;
    }
    printf("Weight of the youngest person: %d\n", heap[0].weight);
}

void printHeap(struct person* heap, int n) {
    printf("Heap state:\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Name: %s, Age: %d, Height: %d, Weight: %d\n", heap[i].id, heap[i].name, heap[i].age, heap[i].height, heap[i].weight);
    }
}

int main() {
    struct person* minHeap = NULL;
    struct person* maxHeap = NULL;
    int minHeapSize = 5;
    int maxHeapSize = 0;
    int maxHeapCreated = 0;
    int minHeapCreated = 0;
    
    struct person persons[] = {
        {1, "mani", 25, 160, 55},
        {2, "kushal", 30, 175, 70},
        {3, "kushagra", 22, 180, 69},
        {4, "keshav", 28, 165, 100},
        {5, "keshav ka pati", 26, 170, 66}
    };

    int option;
    do {
        printf("\nMAIN MENU (HEAP)\n");
        printf("1. Create a Min-heap based on the age\n");
        printf("2. Create a Max-heap based on the weight\n");
        printf("3. Display weight of the youngest person\n");
        printf("4. Insert a new person into the Min-heap\n");
        printf("5. Delete the oldest person\n");
        printf("6. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                minHeap = (struct person*)malloc(minHeapSize * sizeof(struct person));
                memcpy(minHeap, persons, minHeapSize * sizeof(struct person));
                buildMinHeap(minHeap, minHeapSize);
                printf("Min-heap created based on age.\n");
                minHeapCreated = 1;
                // printHeap(minHeap, minHeapSize);
                break;
            case 2:
                maxHeap = (struct person*)malloc(minHeapSize * sizeof(struct person));
                memcpy(maxHeap, minHeap, minHeapSize * sizeof(struct person));
                maxHeapSize = minHeapSize;
                buildMaxHeap(maxHeap, maxHeapSize);
                maxHeapCreated = 1;
                printf("Max-heap created based on weight.\n");
                // printHeap(maxHeap, maxHeapSize);
                break;
            case 3:
                if(minHeapCreated) displayYoungestPersonWeight(minHeap, minHeapSize);
                else printf("Min-heap not created yet.\n");
                break;
            case 4: {
                if(!minHeapCreated) {
                    printf("Min-heap not created yet.\n");
                    break;
                }
                struct person newPerson;
                printf("Enter ID, Name, Age, Height, Weight: ");
                scanf("%d %s %d %d %d", &newPerson.id, newPerson.name, &newPerson.age, &newPerson.height, &newPerson.weight);
                insertMinHeap(&minHeap, &minHeapSize, newPerson);
                printf("Person inserted into Min-heap.\n");
                // printHeap(minHeap, minHeapSize);
                break;
            }
            case 5:
                if(!minHeapCreated) {
                    printf("Min-heap not created yet.\n");
                    break;
                }
                deleteOldest(&minHeap, &minHeapSize);
                printf("Oldest person deleted from Min-heap.\n");
                // printHeap(minHeap, minHeapSize);
                break;
            case 6:
                break;
            default:
                printf("Invalid option. Try again.\n");
        }
    } while (option != 6);

    if (minHeap != NULL) {
        free(minHeap);
    }
    if (maxHeap != NULL) {
        free(maxHeap);
    }

    return 0;
}