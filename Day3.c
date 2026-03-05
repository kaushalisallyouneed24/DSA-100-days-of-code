#include <stdio.h>

int main() {
    int n, k, found = 0, comparisons = 0, index = -1;

    // Read the size of the array
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];
    // Read the array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Read the key to search for
    scanf("%d", &k);

    // Linear Search Logic
    for (int i = 0; i < n; i++) {
        comparisons++; // Increment comparison count for every check
        if (arr[i] == k) {
            index = i;
            found = 1;
            break; // Stop searching once the key is found
        }
    }

    // Output the results
    if (found) {
        printf("Found at index %d\n", index);
    } else {
        printf("Not Found\n");
    }
    printf("Comparisons = %d\n", comparisons);

    return 0;
}
