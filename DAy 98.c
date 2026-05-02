#include <stdlib.h>

int compare(const void* a, const void* b) {
    int* x = *(int**)a;
    int* y = *(int**)b;
    return x[0] - y[0];
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** merge(int** intervals, int intervalsSize, int* intervalsColSize,
            int* returnSize, int** returnColumnSizes) {
    if (intervalsSize == 0) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    qsort(intervals, intervalsSize, sizeof(int*), compare);

    int** result = (int**)malloc(intervalsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(intervalsSize * sizeof(int));

    int index = 0;
    result[0] = (int*)malloc(2 * sizeof(int));
    result[0][0] = intervals[0][0];
    result[0][1] = intervals[0][1];
    (*returnColumnSizes)[0] = 2;

    for (int i = 1; i < intervalsSize; i++) {
        if (intervals[i][0] <= result[index][1]) {
            if (intervals[i][1] > result[index][1]) {
                result[index][1] = intervals[i][1];
            }
        } else {
            index++;
            result[index] = (int*)malloc(2 * sizeof(int));
            result[index][0] = intervals[i][0];
            result[index][1] = intervals[i][1];
            (*returnColumnSizes)[index] = 2;
        }
    }

    *returnSize = index + 1;
    return result;
}
