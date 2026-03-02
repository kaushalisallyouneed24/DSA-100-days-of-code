#include <stdio.h>

#define MAX 1000

int main() {
    int stack[MAX];
    int top = -1;
    int n, m, val;

    // 1. Read number of elements to push
    if (scanf("%d", &n) != 1) return 0;

    // Push n elements
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &val) == 1) {
            if (top < MAX - 1) {
                stack[++top] = val;
            }
        }
    }

    // 2. Read number of elements to pop
    if (scanf("%d", &m) != 1) return 0;

    // Pop m elements
    for (int i = 0; i < m; i++) {
        if (top != -1) {
            top--; // We don't need to print the popped value here, just move the index
        }
    }

    // 3. Print remaining elements (Top to Bottom)
    if (top == -1) {
        // Optional: handle empty stack if required by your platform
        return 0;
    }

    for (int i = top; i >= 0; i--) {
        printf("%d%s", stack[i], (i == 0) ? "" : " ");
    }
    printf("\n");

    return 0;
}
