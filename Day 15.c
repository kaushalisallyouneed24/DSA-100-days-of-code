#include <stdio.h>

int main() {
    int m, n;
    
    // Read dimensions
    if (scanf("%d %d", &m, &n) != 2) return 0;

    int matrix[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    long sum = 0;
    // The diagonal exists only up to the smaller of the two dimensions
    int diagonalLimit = (m < n) ? m : n;

    // Optimized: Single loop O(min(m, n))
    for (int i = 0; i < diagonalLimit; i++) {
        sum += matrix[i][i];
    }

    printf("%ld\n", sum);

    return 0;
}
