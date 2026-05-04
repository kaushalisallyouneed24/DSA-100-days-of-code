#include <stdlib.h>

typedef struct {
    int value;
    int index;
} Pair;

void merge(Pair* arr, int left, int mid, int right, int* counts) {
    int n = right - left + 1;
    Pair* temp = (Pair*)malloc(n * sizeof(Pair));

    int i = left;
    int j = mid + 1;
    int k = 0;
    int rightCount = 0;

    while (i <= mid && j <= right) {
        if (arr[j].value < arr[i].value) {
            temp[k++] = arr[j++];
            rightCount++;
        } else {
            counts[arr[i].index] += rightCount;
            temp[k++] = arr[i++];
        }
    }

    while (i <= mid) {
        counts[arr[i].index] += rightCount;
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = 0; i < n; i++) {
        arr[left + i] = temp[i];
    }

    free(temp);
}

void mergeSort(Pair* arr, int left, int right, int* counts) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid, counts);
    mergeSort(arr, mid + 1, right, counts);
    merge(arr, left, mid, right, counts);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countSmaller(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    if (numsSize == 0) return NULL;

    Pair* arr = (Pair*)malloc(numsSize * sizeof(Pair));
    int* counts = (int*)calloc(numsSize, sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        arr[i].value = nums[i];
        arr[i].index = i;
    }

    mergeSort(arr, 0, numsSize - 1, counts);

    free(arr);
    return counts;
}
