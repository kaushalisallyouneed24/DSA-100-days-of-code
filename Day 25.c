#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create a linked list from input
struct Node* createList(int n) {
    if (n <= 0) return NULL;
    struct Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

// Function to count occurrences of a key
int countKey(struct Node* head, int key) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            count++;
        }
        current = current->next;
    }
    return count;
}

// Cleanup function to prevent memory leaks
void freeList(struct Node* head) {
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n, key;
    
    // Read number of nodes
    if (scanf("%d", &n) != 1) return 0;
    
    // Create the list
    struct Node* head = createList(n);
    
    // Read the key to search for
    if (scanf("%d", &key) != 1) return 0;

    // Output the result
    printf("%d\n", countKey(head, key));

    // Free memory
    freeList(head);

    return 0;
}
