#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    struct Node *head = NULL, *tail = NULL;

    // 1. Creation and Linking
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            newNode->next = head; // Point to itself initially
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head; // Always point back to head
        }
    }

    // 2. Traversal
    if (head != NULL) {
        struct Node* temp = head;
        do {
            printf("%d%s", temp->data, (temp->next == head) ? "" : " ");
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    }

    // 3. Memory Cleanup (Careful with the loop!)
    if (head != NULL) {
        struct Node* current = head;
        struct Node* nextNode;
        for (int i = 0; i < n; i++) {
            nextNode = current->next;
            free(current);
            current = nextNode;
        }
    }

    return 0;
}
