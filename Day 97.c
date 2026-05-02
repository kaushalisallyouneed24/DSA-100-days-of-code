#include <stdlib.h>

int compare(const void* a, const void* b) {
    int* x = *(int**)a;
    int* y = *(int**)b;
    return x[0] - y[0];
}

int minMeetingRooms(int** intervals, int intervalsSize, int* intervalsColSize) {
    if (intervalsSize == 0) return 0;

    qsort(intervals, intervalsSize, sizeof(int*), compare);

    int* heap = (int*)malloc(intervalsSize * sizeof(int));
    int heapSize = 0;

    // Insert first meeting's end time
    heap[heapSize++] = intervals[0][1];

    for (int i = 1; i < intervalsSize; i++) {
        int start = intervals[i][0];
        int end = intervals[i][1];

        // If earliest ending meeting is over, reuse room
        if (start >= heap[0]) {
            heap[0] = end;
        } else {
            heap[heapSize++] = end;
        }

        // Heapify up/down
        int idx = heapSize - 1;
        while (idx > 0) {
            int parent = (idx - 1) / 2;
            if (heap[parent] <= heap[idx]) break;

            int temp = heap[parent];
            heap[parent] = heap[idx];
            heap[idx] = temp;
            idx = parent;
        }

        // Heapify down from root
        idx = 0;
        while (1) {
            int smallest = idx;
            int left = 2 * idx + 1;
            int right = 2 * idx + 2;

            if (left < heapSize && heap[left] < heap[smallest])
                smallest = left;
            if (right < heapSize && heap[right] < heap[smallest])
                smallest = right;

            if (smallest == idx) break;

            int temp = heap[idx];
            heap[idx] = heap[smallest];
            heap[smallest] = temp;
            idx = smallest;
        }
    }

    int result = heapSize;
    free(heap);
    return result;
}
