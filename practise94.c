#include <stdio.h>
#include <stdlib.h>

// Function to find maximum element
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void countingSort(int arr[], int n) {
    int max = findMax(arr, n);

    // Create count array
    int *count = (int *)calloc(max + 1, sizeof(int));
    int *output = (int *)malloc(n * sizeof(int));

    // Step 1: Frequency
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    // Step 2: Prefix sum
    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    // Step 3: Build output (right to left for stability)
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy back to original array
    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    free(count);
    free(output);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    countingSort(arr, n);

    // Print sorted array
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}