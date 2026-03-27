#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isMinHeap(int* arr, int n) {
    // We only need to check nodes that have at least one child.
    // These are nodes from index 0 up to (n-2)/2.
    for (int i = 0; i <= (n - 2) / 2; i++) {
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;

        // Check Left Child
        if (leftChild < n && arr[i] > arr[leftChild]) {
            return false;
        }

        // Check Right Child
        if (rightChild < n && arr[i] > arr[rightChild]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    // Handle empty tree case
    if (n == 0) {
        printf("YES\n");
        return 0;
    }

    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (isMinHeap(arr, n)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    free(arr);
    return 0;
}
