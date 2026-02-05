#include <stdio.h>

int main() {
    int p, q;

    // Read log 1
    if (scanf("%d", &p) != 1) return 0;
    int log1[p];
    for (int i = 0; i < p; i++) scanf("%d", &log1[i]);

    // Read log 2
    if (scanf("%d", &q) != 1) return 0;
    int log2[q];
    for (int i = 0; i < q; i++) scanf("%d", &log2[i]);

    int result[p + q];
    int i = 0, j = 0, k = 0;

    // Compare elements from both logs
    while (i < p && j < q) {
        if (log1[i] <= log2[j]) {
            result[k++] = log1[i++];
        } else {
            result[k++] = log2[j++];
        }
    }

    // Add remaining elements from log 1 (if any)
    while (i < p) {
        result[k++] = log1[i++];
    }

    // Add remaining elements from log 2 (if any)
    while (j < q) {
        result[k++] = log2[j++];
    }

    // Print the final merged log
    for (int m = 0; m < p + q; m++) {
        printf("%d%s", result[m], (m == p + q - 1) ? "" : " ");
    }
    printf("\n");

    return 0;
}
