#include <stdio.h>
#include <stdlib.h>

// Comparison function for sorting
int compare(const void* a, const void* b) {
    long long arg1 = *(const long long*)a;
    long long arg2 = *(const long long*)b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    long long* prefixSums = (long long*)malloc(sizeof(long long) * (n + 1));
    prefixSums[0] = 0; // The sum before any elements is 0
    
    long long currentSum = 0;
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        currentSum += val;
        prefixSums[i + 1] = currentSum;
    }

    // Sort prefix sums to group identical values O(n log n)
    qsort(prefixSums, n + 1, sizeof(long long), compare);

    long long totalCount = 0;
    long long currentFrequency = 1;

    for (int i = 1; i < n + 1; i++) {
        if (prefixSums[i] == prefixSums[i - 1]) {
            currentFrequency++;
        } else {
            // If a sum appears 'k' times, it forms k*(k-1)/2 subarrays
            totalCount += (currentFrequency * (currentFrequency - 1)) / 2;
            currentFrequency = 1;
        }
    }
    // Add count for the last group
    totalCount += (currentFrequency * (currentFrequency - 1)) / 2;

    printf("%lld\n", totalCount);

    free(prefixSums);
    return 0;
}
