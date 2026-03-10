#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Define the Queue structure to hold front and rear pointers
struct Queue {
    struct Node *front, *rear;
};

// Function to initialize the queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Enqueue: Add element to the rear
void enqueue(struct Queue* q, int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;

    // If queue is empty, new node is both front and rear
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }

    // Add at the end and update rear
    q->rear->next = newNode;
    q->rear = newNode;
}

// Dequeue: Remove element from the front
int dequeue(struct Queue* q) {
    // Check for empty queue
    if (q->front == NULL) {
        return -1;
    }

    struct Node* temp = q->front;
    int val = temp->data;

    q->front = q->front->next;

    // If front becomes NULL, rear must also be NULL
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return val;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    struct Queue* q = createQueue();
    char op[20];

    while (n--) {
        scanf("%s", op);
        if (strcmp(op, "enqueue") == 0) {
            int x;
            scanf("%d", &x);
            enqueue(q, x);
        } else if (strcmp(op, "dequeue") == 0) {
            printf("%d\n", dequeue(q));
        }
    }

    return 0;
}
