#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Helper to create and link nodes
struct Node* createList(int n) {
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

struct Node* deleteFirstOccurrence(struct Node* head, int key) {
    if (head == NULL) return NULL;

    // Case 1: The head itself holds the key
    if (head->data == key) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    // Case 2: Search for the key in the rest of the list
    struct Node* prev = head;
    struct Node* current = head->next;

    while (current != NULL) {
        if (current->data == key) {
            prev->next = current->next; // Bypass the current node
            free(current);             // Free the memory
            return head;               // Return after first occurrence
        }
        prev = current;
        current = current->next;
    }

    return head; // Key not found
}

int main() {
    int n, key;
    if (scanf("%d", &n) != 1) return 0;
    
    struct Node* head = createList(n);
    scanf("%d", &key);

    head = deleteFirstOccurrence(head, key);

    // Print the list
    struct Node* temp = head;
    while (temp) {
        printf("%d%s", temp->data, (temp->next) ? " " : "");
        temp = temp->next;
    }
    printf("\n");

    return 0;
}
