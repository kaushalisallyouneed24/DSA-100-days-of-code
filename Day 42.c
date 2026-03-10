#include <stdio.h>
#include <stdlib.h>

// Simple Node for both Stack and Queue
struct Node {
    int data;
    struct Node* next;
};

// Stack Operations
void push(struct Node** top, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}

int pop(struct Node** top) {
    if (*top == NULL) return -1;
    struct Node* temp = *top;
    int val = temp->data;
    *top = (*top)->next;
    free(temp);
    return val;
}

// Queue Operations
struct Queue {
    struct Node *front, *rear;
};

void enqueue(struct Queue* q, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

int dequeue(struct Queue* q) {
    if (q->front == NULL) return -1;
    struct Node* temp = q->front;
    int val = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return val;
}

void reverseQueue(struct Queue* q) {
    struct Node* stack = NULL;

    // Step 1: Queue -> Stack
    while (q->front != NULL) {
        push(&stack, dequeue(q));
    }

    // Step 2: Stack -> Queue
    while (stack != NULL) {
        enqueue(q, pop(&stack));
    }
}

int main() {
    int n, val;
    if (scanf("%d", &n) != 1) return 0;

    struct Queue q = {NULL, NULL};
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(&q, val);
    }

    reverseQueue(&q);

    // Print reversed queue
    struct Node* temp = q.front;
    while (temp != NULL) {
        printf("%d%s", temp->data, (temp->next == NULL) ? "" : " ");
        temp = temp->next;
    }
    printf("\n");

    return 0;
}
