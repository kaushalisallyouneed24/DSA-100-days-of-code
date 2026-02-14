#include <stdio.h>
#include <stdbool.h>

int main() {
    int n;
    
    // Read the dimension of the square matrix
    if (scanf("%d", &n) != 1) return 0;

    int matrix[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    bool isIdentity = true;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                // Check diagonal elements
                if (matrix[i][j] != 1) {
                    isIdentity = false;
                    break;
                }
            } else {
                // Check non-diagonal elements
                if (matrix[i][j] != 0) {
                    isIdentity = false;
                    break;
                }
            }
        }
        if (!isIdentity) break;
    }

    if (isIdentity) {
        printf("Identity Matrix\n");
    } else {
        printf("Not an Identity Matrix\n");
    }

    return 0;
}
