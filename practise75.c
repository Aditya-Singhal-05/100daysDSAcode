#include <stdio.h>

#define MAX 100000

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int prefixSum = 0;
    int maxLen = 0;

    // Simple array-based hashing (shift index for negatives)
    int hash[MAX * 2];
    for (int i = 0; i < MAX * 2; i++)
        hash[i] = -2;

    // To handle prefixSum = 0
    hash[MAX] = -1;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        int index = prefixSum + MAX;

        if (hash[index] != -2) {
            int len = i - hash[index];
            if (len > maxLen)
                maxLen = len;
        } else {
            hash[index] = i;
        }
    }

    printf("%d\n", maxLen);

    return 0;
}