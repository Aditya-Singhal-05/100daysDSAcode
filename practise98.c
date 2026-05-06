#include <stdio.h>
#include <stdlib.h>

// Structure for interval
typedef struct {
    int start, end;
} Interval;

// Sort by start time
int compare(const void *a, const void *b) {
    return ((Interval*)a)->start - ((Interval*)b)->start;
}

void mergeIntervals(Interval arr[], int n) {
    if (n == 0) return;

    // Step 1: Sort intervals
    qsort(arr, n, sizeof(Interval), compare);

    // Result array
    Interval result[n];
    int index = 0;

    result[0] = arr[0];

    // Step 2: Merge
    for (int i = 1; i < n; i++) {
        if (arr[i].start <= result[index].end) {
            // Overlapping → merge
            if (arr[i].end > result[index].end)
                result[index].end = arr[i].end;
        } else {
            // No overlap → new interval
            index++;
            result[index] = arr[i];
        }
    }

    // Print merged intervals
    for (int i = 0; i <= index; i++) {
        printf("%d %d\n", result[i].start, result[i].end);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    Interval arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    mergeIntervals(arr, n);

    return 0;
}