#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node *next, *prev;
};

struct Deque {
    struct Node *front, *rear;
    int size;
};

struct Deque* createDeque() {
    struct Deque* dq = (struct Deque*)malloc(sizeof(struct Deque));
    dq->front = dq->rear = NULL;
    dq->size = 0;
    return dq;
}

void push_front(struct Deque* dq, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = dq->front;

    if (dq->front == NULL) 
        dq->rear = newNode;
    else 
        dq->front->prev = newNode;
    
    dq->front = newNode;
    dq->size++;
}

void push_back(struct Deque* dq, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = dq->rear;

    if (dq->rear == NULL)
        dq->front = newNode;
    else
        dq->rear->next = newNode;

    dq->rear = newNode;
    dq->size++;
}

int pop_front(struct Deque* dq) {
    if (dq->front == NULL) return -1;
    struct Node* temp = dq->front;
    int data = temp->data;
    dq->front = dq->front->next;

    if (dq->front == NULL)
        dq->rear = NULL;
    else
        dq->front->prev = NULL;

    free(temp);
    dq->size--;
    return data;
}

int pop_back(struct Deque* dq) {
    if (dq->rear == NULL) return -1;
    struct Node* temp = dq->rear;
    int data = temp->data;
    dq->rear = dq->rear->prev;

    if (dq->rear == NULL)
        dq->front = NULL;
    else
        dq->rear->next = NULL;

    free(temp);
    dq->size--;
    return data;
}

void display(struct Deque* dq) {
    struct Node* temp = dq->front;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
