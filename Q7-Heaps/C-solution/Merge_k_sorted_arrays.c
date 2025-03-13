#include <stdio.h>
#include <stdlib.h>

// Structure to store elements in the min heap
typedef struct {
    int value;
    int arrayIndex; 
    int elementIndex; 
} HeapNode;

// Min Heap structure
typedef struct {
    HeapNode *heapArray;
    int size;
} MinHeap;

// Swap function for heap
void swap(HeapNode *x, HeapNode *y) {
    HeapNode temp = *x;
    *x = *y;
    *y = temp;
}

// Min Heapify function
void minHeapify(MinHeap *heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->heapArray[left].value < heap->heapArray[smallest].value)
        smallest = left;

    if (right < heap->size && heap->heapArray[right].value < heap->heapArray[smallest].value)
        smallest = right;

    if (smallest != index) {
        swap(&heap->heapArray[index], &heap->heapArray[smallest]);
        minHeapify(heap, smallest);
    }
}

// Function to extract the minimum element from heap
HeapNode extractMin(MinHeap *heap) {
    HeapNode root = heap->heapArray[0];
    heap->heapArray[0] = heap->heapArray[heap->size - 1];
    heap->size--;
    minHeapify(heap, 0);
    return root;
}

// Function to insert a new node into the heap
void insertMinHeap(MinHeap *heap, HeapNode node) {
    heap->size++;
    int i = heap->size - 1;
    heap->heapArray[i] = node;

    while (i > 0 && heap->heapArray[i].value < heap->heapArray[(i - 1) / 2].value) {
        swap(&heap->heapArray[i], &heap->heapArray[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to merge K sorted arrays
int* mergeKSortedArrays(int arr[][3], int k, int n, int *resultSize) {
    MinHeap heap;
    heap.size = k;
    heap.heapArray = (HeapNode*)malloc(k * sizeof(HeapNode));

    int *result = (int*)malloc(k * n * sizeof(int));
    int resultIndex = 0;

    // Insert first element of each array into the heap
    for (int i = 0; i < k; i++) {
        heap.heapArray[i].value = arr[i][0];
        heap.heapArray[i].arrayIndex = i;
        heap.heapArray[i].elementIndex = 0;
    }

    // Build the heap
    for (int i = (k - 1) / 2; i >= 0; i--) {
        minHeapify(&heap, i);
    }

    // Extract elements one by one and insert next elements
    while (heap.size > 0) {
        HeapNode minNode = extractMin(&heap);
        result[resultIndex++] = minNode.value;

        int nextIndex = minNode.elementIndex + 1;
        if (nextIndex < n) {
            HeapNode newNode;
            newNode.value = arr[minNode.arrayIndex][nextIndex];
            newNode.arrayIndex = minNode.arrayIndex;
            newNode.elementIndex = nextIndex;
            insertMinHeap(&heap, newNode);
        }
    }

    free(heap.heapArray);
    *resultSize = resultIndex;
    return result;
}

int main() {
    int k = 3, n = 3;
    int arr[3][3] = {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}};

    int resultSize;
    int *mergedArray = mergeKSortedArrays(arr, k, n, &resultSize);

    printf("Merged Sorted Array: ");
    for (int i = 0; i < resultSize; i++) {
        printf("%d ", mergedArray[i]);
    }
    printf("\n");

    free(mergedArray);
    return 0;
}
