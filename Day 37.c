#include <stdio.h>
#include <string.h>

#define MAX 1000

int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int x) {
    if (size >= MAX) return;
    
    heap[size] = x;
    int current = size;
    size++;

    // Bubble up: Maintain Min-Heap property
    while (current > 0 && heap[current] < heap[(current - 1) / 2]) {
        swap(&heap[current], &heap[(current - 1) / 2]);
        current = (current - 1) / 2;
    }
}

int deleteMin() {
    if (size == 0) return -1;

    int root = heap[0];
    heap[0] = heap[size - 1];
    size--;

    // Bubble down
    int current = 0;
    while (2 * current + 1 < size) {
        int leftChild = 2 * current + 1;
        int rightChild = 2 * current + 2;
        int smallest = leftChild;

        if (rightChild < size && heap[rightChild] < heap[leftChild]) {
            smallest = rightChild;
        }

        if (heap[current] <= heap[smallest]) break;

        swap(&heap[current], &heap[smallest]);
        current = smallest;
    }
    return root;
}

int peek() {
    if (size == 0) return -1;
    return heap[0];
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    char op[10];
    while (n--) {
        scanf("%s", op);
        if (strcmp(op, "insert") == 0) {
            int x;
            scanf("%d", &x);
            insert(x);
        } else if (strcmp(op, "delete") == 0) {
            printf("%d\n", deleteMin());
        } else if (strcmp(op, "peek") == 0) {
            printf("%d\n", peek());
        }
    }

    return 0;
}
