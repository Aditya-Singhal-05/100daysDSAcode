#include <stdio.h>
#include <stdlib.h>

// Node for linked list (bucket)
typedef struct Node {
    float data;
    struct Node* next;
} Node;

// Insert into sorted linked list (Insertion Sort inside bucket)
Node* insertSorted(Node* head, float value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    // Insert at beginning or empty list
    if (head == NULL || value < head->data) {
        newNode->next = head;
        return newNode;
    }

    Node* curr = head;
    while (curr->next != NULL && curr->next->data < value)
        curr = curr->next;

    newNode->next = curr->next;
    curr->next = newNode;

    return head;
}

// Bucket Sort function
void bucketSort(float arr[], int n) {
    // Create array of buckets
    Node* buckets[n];

    for (int i = 0; i < n; i++)
        buckets[i] = NULL;

    // Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int index = n * arr[i];   // bucket index
        buckets[index] = insertSorted(buckets[index], arr[i]);
    }

    // Concatenate buckets
    int k = 0;
    for (int i = 0; i < n; i++) {
        Node* curr = buckets[i];
        while (curr != NULL) {
            arr[k++] = curr->data;
            curr = curr->next;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[n];
    for (int i = 0; i < n; i++)
        scanf("%f", &arr[i]);

    bucketSort(arr, n);

    // Print sorted array
    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);

    return 0;
}