//A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.

#include <stdio.h>

int main() {
    int p, q;

    scanf("%d", &p);
    int A[p];
    for(int i = 0; i < p; i++) {
        scanf("%d", &A[i]);
    }

    scanf("%d", &q);
    int B[q];
    for(int i = 0; i < q; i++) {
        scanf("%d", &B[i]);
    }

    int i = 0, j = 0;

    while(i < p && j < q) {
        if(A[i] <= B[j]) {
            printf("%d ", A[i]);
            i++;
        } else {
            printf("%d ", B[j]);
            j++;
        }
    }

    while(i < p) {
        printf("%d ", A[i]);
        i++;
    }

    while(j < q) {
        printf("%d ", B[j]);
        j++;
    }

    return 0;
}