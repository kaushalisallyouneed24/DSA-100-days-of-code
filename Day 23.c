#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Helper to create a new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// Function to merge two sorted lists
struct Node* mergeSortedLists(struct Node* l1, struct Node* l2) {
    struct Node dummy; // Stack-allocated dummy node
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    // Attach remaining nodes
    if (l1 != NULL) tail->next = l1;
    else tail->next = l2;

    return dummy.next;
}

int main() {
    int n, m, val;
    struct Node *head1 = NULL, *tail1 = NULL;
    struct Node *head2 = NULL, *tail2 = NULL;

    // Read First List
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if (!head1) head1 = tail1 = newNode;
        else { tail1->next = newNode; tail1 = newNode; }
    }

    // Read Second List
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if (!head2) head2 = tail2 = newNode;
        else { tail2->next = newNode; tail2 = newNode; }
    }

    // Merge and Print
    struct Node* result = mergeSortedLists(head1, head2);
    while (result != NULL) {
        printf("%d%s", result->data, (result->next) ? " " : "");
        result = result->next;
    }
    printf("\n");

    return 0;
}
