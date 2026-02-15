#include <stdio.h>

// Helper function to reverse a portion of the array
void reverse(int* arr, int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int n, k;
    
    // Read array size
    if (scanf("%d", &n) != 1) return 0;
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Read rotation steps
    if (scanf("%d", &k) != 1) return 0;

    // Step 1: Normalize k
    k = k % n;
    if (k == 0) goto print; // No rotation needed

    // Step 2: Reverse the whole array
    reverse(arr, 0, n - 1);
    
    // Step 3: Reverse the first k elements
    reverse(arr, 0, k - 1);
    
    // Step 4: Reverse the rest
    reverse(arr, k, n - 1);

print:
    for (int i = 0; i < n; i++) {
        printf("%d%s", arr[i], (i == n - 1) ? "" : " ");
    }
    printf("\n");

    return 0;
}
