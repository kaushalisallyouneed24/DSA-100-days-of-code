#include <stdio.h>

int main() {
    int r, c;
    if (scanf("%d %d", &r, &c) != 2) return 0;

    int matrix[r][c];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int top = 0, bottom = r - 1;
    int left = 0, right = c - 1;
    bool first = true;

    while (top <= bottom && left <= right) {
        // 1. Traverse Right
        for (int i = left; i <= right; i++) {
            printf("%s%d", first ? "" : " ", matrix[top][i]);
            first = false;
        }
        top++;

        // 2. Traverse Down
        for (int i = top; i <= bottom; i++) {
            printf(" %d", matrix[i][right]);
        }
        right--;

        // 3. Traverse Left (Check if row still exists)
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                printf(" %d", matrix[bottom][i]);
            }
            bottom--;
        }

        // 4. Traverse Up (Check if column still exists)
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                printf(" %d", matrix[i][left]);
            }
            left++;
        }
    }
    printf("\n");

    return 0;
}
