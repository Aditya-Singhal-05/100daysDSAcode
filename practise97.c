#include <stdio.h>
#include <stdlib.h>

// Structure for meeting
typedef struct {
    int start, end;
} Meeting;

// Sort by start time
int compare(const void *a, const void *b) {
    return ((Meeting*)a)->start - ((Meeting*)b)->start;
}

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify (min-heap)
void heapify(int heap[], int size, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;
    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, size, smallest);
    }
}

// Insert into heap
void insertHeap(int heap[], int *size, int value) {
    heap[*size] = value;
    int i = *size;
    (*size)++;

    while (i != 0 && heap[(i-1)/2] > heap[i]) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

// Remove min (root)
int extractMin(int heap[], int *size) {
    int root = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;

    heapify(heap, *size, 0);
    return root;
}

int minRooms(Meeting arr[], int n) {
    // Sort meetings by start time
    qsort(arr, n, sizeof(Meeting), compare);

    int heap[n];
    int size = 0;

    // Add first meeting
    insertHeap(heap, &size, arr[0].end);

    for (int i = 1; i < n; i++) {
        // If earliest meeting finished
        if (heap[0] <= arr[i].start) {
            extractMin(heap, &size);
        }

        // Add current meeting
        insertHeap(heap, &size, arr[i].end);
    }

    return size;
}

int main() {
    int n;
    scanf("%d", &n);

    Meeting arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    printf("%d\n", minRooms(arr, n));
    return 0;
}