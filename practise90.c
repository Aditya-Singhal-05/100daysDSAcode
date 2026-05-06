#include <stdio.h>

// Find maximum element
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

// Find sum of array
int findSum(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return sum;
}

// Check if possible within given time
int isPossible(int arr[], int n, int k, int maxTime) {
    int painters = 1;
    int total = 0;

    for (int i = 0; i < n; i++) {
        if (total + arr[i] <= maxTime) {
            total += arr[i];
        } else {
            painters++;
            total = arr[i];
        }

        if (painters > k)
            return 0; // Not possible
    }
    return 1; // Possible
}

// Main function
int minTime(int arr[], int n, int k) {
    int low = findMax(arr, n);
    int high = findSum(arr, n);
    int result = high;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(arr, n, k, mid)) {
            result = mid;
            high = mid - 1; // Try smaller time
        } else {
            low = mid + 1;  // Increase time
        }
    }

    return result;
}

int main() {
    int n, k;

    scanf("%d %d", &n, &k);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d\n", minTime(arr, n, k));

    return 0;
}