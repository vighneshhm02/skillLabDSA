#include <stdio.h>
#include <stdlib.h>

// Define Linked List Node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to merge two sorted linked lists
struct Node* mergeTwoLists(struct Node* l1, struct Node* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    if (l1->data < l2->data) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

// Function to merge K sorted linked lists using Divide and Conquer
struct Node* mergeKLists(struct Node* lists[], int left, int right) {
    if (left == right) return lists[left]; // Base case: Only one list

    int mid = left + (right - left) / 2;
    
    // Recursively divide lists into halves and merge
    struct Node* l1 = mergeKLists(lists, left, mid);
    struct Node* l2 = mergeKLists(lists, mid + 1, right);

    return mergeTwoLists(l1, l2);
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    printf("Merging K Sorted Linked Lists using Divide and Conquer\n");

    // Number of lists
    int k = 3;

    // Array of linked list heads
    struct Node* lists[k];

    // Creating sample linked lists
    lists[0] = createNode(1);
    lists[0]->next = createNode(4);
    lists[0]->next->next = createNode(5);

    lists[1] = createNode(1);
    lists[1]->next = createNode(3);
    lists[1]->next->next = createNode(4);

    lists[2] = createNode(2);
    lists[2]->next = createNode(6);

    // Merge all K lists
    struct Node* mergedHead = mergeKLists(lists, 0, k - 1);

    // Print the final merged linked list
    printList(mergedHead);

    return 0;
}
