#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000

int heap[MAX_SIZE];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Restore heap property by moving a node up
void siftUp(int index) {
    while (index > 0 && heap[index] < heap[(index - 1) / 2]) {
        swap(&heap[index], &heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

// Restore heap property by moving a node down
void siftDown(int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;
    
    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        siftDown(smallest);
    }
}

void insert(int x) {
    if (size >= MAX_SIZE) return;
    heap[size] = x;
    siftUp(size);
    size++;
}

int extractMin() {
    if (size <= 0) return -1;
    
    int minVal = heap[0];
    heap[0] = heap[size - 1];
    size--;
    siftDown(0);
    
    return minVal;
}

int peek() {
    if (size <= 0) return -1;
    return heap[0];
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    char op[20];
    while (n--) {
        scanf("%s", op);
        if (strcmp(op, "insert") == 0) {
            int x;
            scanf("%d", &x);
            insert(x);
        } else if (strcmp(op, "extractMin") == 0) {
            printf("%d\n", extractMin());
        } else if (strcmp(op, "peek") == 0) {
            printf("%d\n", peek());
        }
    }
    return 0;
}
