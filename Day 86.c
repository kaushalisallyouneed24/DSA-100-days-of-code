#include <stdio.h>

int integerSquareRoot(int n) {
    if (n == 0 || n == 1)
        return n;

    long long low = 1, high = n, ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (mid * mid <= n) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return (int)ans;
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d", integerSquareRoot(n));

    return 0;
}
