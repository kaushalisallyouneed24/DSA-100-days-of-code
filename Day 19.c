#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

// Comparison function for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n < 2) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Step 1: Sort the array O(n log n)
    qsort(arr, n, sizeof(int), compare);

    int left = 0, right = n - 1;
    int min_sum = INT_MAX;
    int res_l = 0, res_r = n - 1;

    // Step 2: Two-Pointer approach O(n)
    while (left < right) {
        int sum = arr[left] + arr[right];

        // Update result if this sum is closer to zero
        if (abs(sum) < abs(min_sum)) {
            min_sum = sum;
            res_l = arr[left];
            res_r = arr[right];
        }

        if (sum < 0) {
            left++;
        } else if (sum > 0) {
            right--;
        } else {
            // sum == 0 is the closest possible
            break;
        }
    }

    printf("%d %d\n", res_l, res_r);

    return 0;
}
