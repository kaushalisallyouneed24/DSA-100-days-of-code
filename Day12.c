#include <stdio.h>
#include <stdbool.h>

int main() {
    int m, n;
    
    // Read dimensions
    if (scanf("%d %d", &m, &n) != 2) return 0;

    // Condition 1: Must be a square matrix
    if (m != n) {
        // Even if the dimensions aren't square, we must read the input 
        // to clear the buffer if this were part of a larger stream.
        printf("Not a Symmetric Matrix\n");
        return 0;
    }

    int matrix[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Condition 2: Check if element[i][j] == element[j][i]
    bool isSymmetric = true;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < i; j++) { // We only need to check one half (below the diagonal)
            if (matrix[i][j] != matrix[j][i]) {
                isSymmetric = false;
                break;
            }
        }
        if (!isSymmetric) break;
    }

    if (isSymmetric) {
        printf("Symmetric Matrix\n");
    } else {
        printf("Not a Symmetric Matrix\n");
    }

    return 0;
}
