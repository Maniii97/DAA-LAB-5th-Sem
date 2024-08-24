#include <stdio.h>
#include <stdlib.h>

typedef struct SYMBOL {
    char alphabet;
    int frequency;
    struct SYMBOL *left, *right;
} SYMBOL;

SYMBOL* createNode(char alphabet, int frequency) {
    SYMBOL* newNode = (SYMBOL*)malloc(sizeof(SYMBOL));
    newNode->alphabet = alphabet;
    newNode->frequency = frequency;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void swap(SYMBOL** a, SYMBOL** b) {
    SYMBOL* temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(SYMBOL* arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left]->frequency < arr[smallest]->frequency)
        smallest = left;

    if (right < n && arr[right]->frequency < arr[smallest]->frequency)
        smallest = right;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        heapify(arr, n, smallest);
    }
}

SYMBOL* extractMin(SYMBOL* arr[], int* n) {
    SYMBOL* root = arr[0];
    arr[0] = arr[*n - 1];
    (*n)--;
    heapify(arr, *n, 0);
    return root;
}

void insertMinHeap(SYMBOL* arr[], int* n, SYMBOL* node) {
    (*n)++;
    int i = *n - 1;
    while (i && node->frequency < arr[(i - 1) / 2]->frequency) {
        arr[i] = arr[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    arr[i] = node;
}

void buildMinHeap(SYMBOL* arr[], int n) {
    int startIdx = (n / 2) - 1;
    for (int i = startIdx; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

SYMBOL* buildHuffmanTree(SYMBOL* arr[], int n) {
    buildMinHeap(arr, n);
    while (n > 1) {
        SYMBOL* left = extractMin(arr, &n);
        SYMBOL* right = extractMin(arr, &n);
        SYMBOL* top = createNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
        insertMinHeap(arr, &n, top);
    }
    return extractMin(arr, &n);
}

void inorderTraversal(SYMBOL* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    if (root->alphabet != '$') {
        printf("%c ", root->alphabet);
    }
    inorderTraversal(root->right);
}

int main() {
    int n;
    printf("Enter the number of distinct alphabets: ");
    scanf("%d", &n);

    SYMBOL* arr[n];
    char alphabet;
    int frequency;

    printf("Enter the alphabets: ");
    for (int i = 0; i < n; i++) {
        scanf(" %c", &alphabet);
        arr[i] = createNode(alphabet, 0);
    }

    printf("Enter its frequencies: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &frequency);
        arr[i]->frequency = frequency;
    }

    SYMBOL* root = buildHuffmanTree(arr, n);

    printf("In-order traversal of the tree (Huffman): ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}