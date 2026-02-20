#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    struct Node *head = NULL, *tail = NULL;

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);

        // 1. Allocate memory for new node
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;

        // 2. Link it to the list
        if (head == NULL) {
            head = newNode; // First node is the head
            tail = newNode;
        } else {
            tail->next = newNode; // Attach to the end
            tail = newNode;       // Update tail to the new end
        }
    }

    // 3. Traversal: Print the list
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d%s", temp->data, (temp->next == NULL) ? "" : " ");
        temp = temp->next;
    }
    printf("\n");

    // Clean up memory (Important in C!)
    temp = head;
    while (temp != NULL) {
        struct Node* next = temp->next;
        free(temp);
        temp = next;
    }

    return 0;
}
