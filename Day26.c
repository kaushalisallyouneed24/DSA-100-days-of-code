#include <stdio.h>
#include <stdlib.h>

// Define the Doubly Linked List Node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    struct Node *head = NULL, *tail = NULL;

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);

        // Allocate memory for new node
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;
        newNode->prev = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            // Link the new node with the current tail
            tail->next = newNode;
            newNode->prev = tail;
            // Move tail to the new node
            tail = newNode;
        }
    }

    // Forward Traversal
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d%s", temp->data, (temp->next == NULL) ? "" : " ");
        temp = temp->next;
    }
    printf("\n");

    // Memory Cleanup
    temp = head;
    while (temp != NULL) {
        struct Node* nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }

    return 0;
}
