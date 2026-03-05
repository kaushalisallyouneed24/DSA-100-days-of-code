#include <stdio.h>
#include <stdlib.h>

// Node structure for the Linked List Queue
struct Node {
    int data;
    struct Node* next;
};

// Queue structure to keep track of Front and Rear
struct Queue {
    struct Node *front, *rear;
};

// Function to initialize an empty queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Enqueue operation
void enqueue(struct Queue* q, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    // If queue is empty, new node is both front and rear
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }

    // Add the new node at the end and update rear
    q->rear->next = newNode;
    q->rear = newNode;
}

// Function to display the queue
void display(struct Queue* q) {
    struct Node* temp = q->front;
    while (temp != NULL) {
        printf("%d%s", temp->data, (temp->next == NULL) ? "" : " ");
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, val;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    struct Queue* q = createQueue();

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &val) == 1) {
            enqueue(q, val);
        }
    }

    display(q);

    // Memory Cleanup
    struct Node* temp = q->front;
    while (temp != NULL) {
        struct Node* next = temp->next;
        free(temp);
        temp = next;
    }
    free(q);

    return 0;
}
