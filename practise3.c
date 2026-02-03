//Implement linear search to find key k in an array. Count and display the number of comparisons performed

#include <stdio.h>

int main() {
    int n, k;
    
    // Input size
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    
    // Input array
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Input key
    printf("Enter key to search: ");
    scanf("%d", &k);
    
    int comparisons = 0;
    int found = -1;
    
    // Linear Search
    for(int i = 0; i < n; i++) {
        comparisons++;                 // one comparison
        if(arr[i] == k) {
            found = i;
            break;
        }
    }
    
    if(found != -1) {
        printf("Key found at position %d\n", found + 1);   // 1-based position
    } else {
        printf("Key not found\n");
    }
    
    printf("Number of comparisons: %d\n", comparisons);
    
    return 0;
}
