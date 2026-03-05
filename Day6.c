#include <stdio.h>

int main() {
    int n;

    // Read the size of the array
    if (scanf("%d", &n) != 1 || n == 0) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Index of the last unique element
    int j = 0;

    // Start checking from the second element (index 1)
    for (int i = 1; i < n; i++) {
        // If current element is different from the last unique element
        if (arr[i] != arr[j]) {
            j++;             // Move the unique pointer forward
            arr[j] = arr[i]; // Update the next unique spot with the new value
        }
    }

    // The number of unique elements is (j + 1)
    for (int k = 0; k <= j; k++) {
        printf("%d%s", arr[k], (k == j) ? "" : " ");
    }
    printf("\n");

    return 0;
}
