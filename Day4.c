#include <stdio.h>

int main() {
    int n;

    // Read the size of the array
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];

    // Read the array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Two-pointer reversal logic
    int left = 0;
    int right = n - 1;

    while (left < right) {
        // Swap elements at left and right
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        // Move pointers towards the center
        left++;
        right--;
    }

    // Print the reversed array
    for (int i = 0; i < n; i++) {
        printf("%d%s", arr[i], (i == n - 1) ? "" : " ");
    }
    printf("\n");

    return 0;
}
