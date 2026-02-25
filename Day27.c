#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Helper to create list from input
struct Node* createList(int size) {
    if (size == 0) return NULL;
    struct Node *head = NULL, *tail = NULL;
    for (int i = 0; i < size; i++) {
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

// Function to get length of list
int getLength(struct Node* head) {
    int len = 0;
    while (head) { len++; head = head->next; }
    return len;
}

int main() {
    int n, m;
    
    // Read and create List 1
    scanf("%d", &n);
    struct Node* head1 = createList(n);
    
    // Read and create List 2
    scanf("%d", &m);
    struct Node* head2 = createList(m);

    // Note: In a real "intersection" problem, the lists share 
    // the same node objects. In competitive programming, 
    // usually we compare values or the problem defines 
    // a specific intersection node.
    
    int len1 = getLength(head1);
    int len2 = getLength(head2);
    
    struct Node *ptr1 = head1, *ptr2 = head2;
    int diff = abs(len1 - len2);

    // Align pointers
    if (len1 > len2) {
        for (int i = 0; i < diff; i++) ptr1 = ptr1->next;
    } else {
        for (int i = 0; i < diff; i++) ptr2 = ptr2->next;
    }

    // Traverse and find intersection
    int found = 0;
    while (ptr1 && ptr2) {
        // In actual memory-based intersection, we check (ptr1 == ptr2)
        // Here we check data based on common platform problem constraints
        if (ptr1->data == ptr2->data) {
            printf("%d\n", ptr1->data);
            found = 1;
            break;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    if (!found) printf("No Intersection\n");

    return 0;
}
