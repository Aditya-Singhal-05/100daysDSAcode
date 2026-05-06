#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int low = 0, high = n, ans = 0;

    while (low <= high) {
        long long mid = (low + high) / 2;
        long long sq = mid * mid;

        if (sq == n) {
            printf("%lld\n", mid);
            return 0;
        }

        if (sq < n) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    printf("%d\n", ans);

    return 0;
}