#include <stdio.h>
#include <stdlib.h>

// Queue Structure
typedef struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
} Queue;

// Function to create a queue
Queue* createQueue(unsigned capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1; // Circular queue
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

// Check if queue is full
int isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

// Check if queue is empty
int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

// Enqueue operation
void enqueue(Queue* queue, int item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
}

// Dequeue operation
int dequeue(Queue* queue) {
    if (isEmpty(queue))
        return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

// Reverse the first K elements of queue
void reverseFirstKElements(Queue* queue, int k) {
    if (queue->size < k || k <= 0)
        return;
    
    int stack[k];
    int i;
    
    // Push first K elements into stack
    for (i = 0; i < k; i++)
        stack[i] = dequeue(queue);

    // Push back stack elements into queue
    for (i = k - 1; i >= 0; i--)
        enqueue(queue, stack[i]);

    // Move remaining elements to back
    int remaining = queue->size - k;
    while (remaining--) {
        enqueue(queue, dequeue(queue));
    }
}

// Print queue
void printQueue(Queue* queue) {
    int i, index;
    for (i = 0; i < queue->size; i++) {
        index = (queue->front + i) % queue->capacity;
        printf("%d ", queue->array[index]);
    }
    printf("\n");
}

// Driver Code
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    Queue* queue = createQueue(n);
    
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        enqueue(queue, x);
    }
    
    reverseFirstKElements(queue, k);
    
    printQueue(queue);
    
    // Free allocated memory
    free(queue->array);
    free(queue);
    
    return 0;
}
