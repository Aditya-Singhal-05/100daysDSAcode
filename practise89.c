#include <stdio.h>

// Function to find max element
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

// Function to find sum of array
int findSum(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return sum;
}

// Check if allocation is possible with maxPages limit
int isPossible(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int pages = 0;

    for (int i = 0; i < n; i++) {
        if (pages + arr[i] <= maxPages) {
            pages += arr[i];
        } else {
            students++;
            pages = arr[i];
        }

        if (students > m)
            return 0; // Not possible
    }
    return 1; // Possible
}

// Main function
int allocateBooks(int arr[], int n, int m) {
    if (m > n)
        return -1; // Not possible

    int low = findMax(arr, n);
    int high = findSum(arr, n);
    int result = high;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(arr, n, m, mid)) {
            result = mid;
            high = mid - 1; // Try smaller value
        } else {
            low = mid + 1;  // Increase limit
        }
    }

    return result;
}

int main() {
    int n, m;

    scanf("%d %d", &n, &m);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d\n", allocateBooks(arr, n, m));

    return 0;
}