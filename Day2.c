#include <stdio.h>

int main() {
    int n, pos;

    // Read the number of elements
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];

    // Read the array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Read the 1-based position to delete
    scanf("%d", &pos);

    // Shift elements to the left starting from the deletion point
    // We stop at n-1 to avoid accessing an index out of bounds (i+1)
    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Print the updated array (now with n-1 elements)
    for (int i = 0; i < n - 1; i++) {
        printf("%d%s", arr[i], (i == n - 2) ? "" : " ");
    }
    printf("\n");

    return 0;
}
