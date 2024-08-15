// implement min and max heap
#include <stdio.h>
struct person {
	int id;
	char *name;
	int age;
	int height;
	int weight;
}; 
struct heap {
    struct person *arr;
    int size;
    int capacity;
};
struct heap *createHeap(int capacity){
    struct heap *h = (struct heap *)malloc(sizeof(struct heap));
    h->arr = (struct person *)malloc(sizeof(struct person) * capacity);
    h->size = 0;
    h->capacity = capacity;
    return h;
}
int main(){
    // menu ops 
    // create min heap
    // create max heap
    // 1. insert
    // 2. delete
    // 3. display min/max
    // 4. exit


}