#include <stdio.h>

int main() {
    int m, n;
    
    // Read dimensions: m (rows) and n (columns)
    if (scanf("%d %d", &m, &n) != 2) return 0;

    int matrix1[m][n];
    int matrix2[m][n];
    int sum[m][n];

    // Input elements for the first matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    // Input elements for the second matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Perform Addition and Print Output
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // Addition: C[i][j] = A[i][j] + B[i][j]
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
            
            printf("%d", sum[i][j]);
            
            // Print space between elements, but not after the last element of the row
            if (j < n - 1) {
                printf(" ");
            }
        }
        printf("\n"); // New line after each row
    }

    return 0;
}
