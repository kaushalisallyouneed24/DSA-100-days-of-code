#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* rotateRight(struct Node* head, int k) {
    if (!head || !head->next || k == 0) return head;

    // 1. Find length and the actual tail
    struct Node* tail = head;
    int n = 1;
    while (tail->next) {
        tail = tail->next;
        n++;
    }

    // 2. Normalize k
    k = k % n;
    if (k == 0) return head;

    // 3. Make it circular
    tail->next = head;

    // 4. Find the new tail: (n - k) steps from head
    struct Node* newTail = head;
    for (int i = 0; i < n - k - 1; i++) {
        newTail = newTail->next;
    }

    // 5. Break the circle
    struct Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

// Helper to create list
struct Node* createList(int n) {
    if (n == 0) return NULL;
    struct Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;
        if (!head) head = tail = newNode;
        else { tail->next = newNode; tail = newNode; }
    }
    return head;
}

int main() {
    int n, k;
    if (scanf("%d", &n) != 1) return 0;
    struct Node* head = createList(n);
    if (scanf("%d", &k) != 1) k = 0;

    head = rotateRight(head, k);

    // Print result
    struct Node* temp = head;
    while (temp) {
        printf("%d%s", temp->data, (temp->next) ? " " : "");
        temp = temp->next;
    }
    printf("\n");

    return 0;
}
