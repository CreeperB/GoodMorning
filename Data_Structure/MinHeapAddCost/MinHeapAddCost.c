#include <stdio.h>
#include <stdlib.h>

#define swap(a, b) \ // swap two elements
    {              \
        int t = a; \
        a = b;     \
        b = t;     \
    }

typedef struct minHeap {
    int *arr;
    int size;
} MinHeap;

void Heapify(MinHeap *heap, int i) {
    int l = 2 * i + 1;  // left child
    int r = 2 * i + 2;  // right child
    int min = i;
    if (l < heap->size && heap->arr[l] < heap->arr[min])  // if left child is smaller than root
        min = l;
    if (r < heap->size && heap->arr[r] < heap->arr[min])  // if right child is smaller than root
        min = r;
    if (min != i) {  // if min is not root
        swap(heap->arr[i], heap->arr[min]);
        Heapify(heap, min);  // recursively heapify the affected sub-tree
    }
}

int popTopHeap(MinHeap *heap) {
    int top = heap->arr[0];                  // store the top element
    heap->arr[0] = heap->arr[--heap->size];  // replace top element with last element
    Heapify(heap, 0);                        // heapify the root
    return top;
}

void heapInsert(MinHeap *heap, int val) {
    int i = heap->size++;                                                     // get index of last element
    heap->arr[i] = val;                                                       // insert at the end
    for (; i != 0 && heap->arr[(i - 1) / 2] > heap->arr[i]; i = (i - 1) / 2)  // if parent is greater than child
        swap(heap->arr[i], heap->arr[(i - 1) / 2]);
}

int main() {
    FILE *input = fopen("input.txt", "r");
    int len;
    while (fscanf(input, "%d", &len) != EOF) {
        // min heap insert
        MinHeap *heap = (MinHeap *)malloc(sizeof(MinHeap));
        heap->arr = (int *)malloc(sizeof(int) * len);
        heap->size = 0;
        while (len--) {
            int val;
            fscanf(input, "%d", &val);
            heapInsert(heap, val);
        }
        // additional cost
        int cost = 0;
        while (heap->size > 1) {
            int min = popTopHeap(heap) + popTopHeap(heap);
            cost += min;
            heapInsert(heap, min);
        }
        printf("%d\n", cost);
    }
}


// 69!!!