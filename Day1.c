#include <stdio.h>

int main() {
    int n, pos, x;

    // Read the initial size of the array
    if (scanf("%d", &n) != 1) return 0;

    // Declare array with extra space for the new element
    int arr[n + 1];

    // Read n integers into the array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Read the 1-based position and the element to insert
    scanf("%d", &pos);
    scanf("%d", &x);

    // Shift elements to the right to make room
    // We start from the new last index and move backwards
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the element at the 0-indexed position (pos - 1)
    arr[pos - 1] = x;

    // Print the updated array
    for (int i = 0; i <= n; i++) {
        printf("%d%s", arr[i], (i == n) ? "" : " ");
    }
    printf("\n");

    return 0;
}
