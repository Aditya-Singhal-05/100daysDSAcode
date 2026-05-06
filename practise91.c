#include <stdio.h>

// Check feasibility
int isPossible(int arr[], int n, int k, int mid) {
    int painters = 1, sum = 0;

    for (int i = 0; i < n; i++) {
        if (sum + arr[i] <= mid) {
            sum += arr[i];
        } else {
            painters++;
            sum = arr[i];
        }
        if (painters > k) return 0;
    }
    return 1;
}

// Main logic
int minTime(int arr[], int n, int k) {
    int max = arr[0], sum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > max) max = arr[i];
        sum += arr[i];
    }

    int low = max, high = sum, ans = sum;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(arr, n, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("%d\n", minTime(arr, n, k));
    return 0;
}