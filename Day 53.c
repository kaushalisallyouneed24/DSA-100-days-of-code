#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 1000
#define OFFSET 500 // To handle negative Horizontal Distances

struct Node {
    int data;
    struct Node *left, *right;
};

// Simple linked list to store nodes in the same vertical column
struct ColumnNode {
    int data;
    struct ColumnNode* next;
};

struct Node* newNode(int val) {
    if (val == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Global array of linked lists for columns and track min/max HD
struct ColumnNode* map[1000]; 
int minHD = 0, maxHD = 0;

void addToMap(int hd, int val) {
    int index = hd + OFFSET;
    struct ColumnNode* newNode = (struct ColumnNode*)malloc(sizeof(struct ColumnNode));
    newNode->data = val;
    newNode->next = NULL;

    if (map[index] == NULL) {
        map[index] = newNode;
    } else {
        struct ColumnNode* temp = map[index];
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
    if (hd < minHD) minHD = hd;
    if (hd > maxHD) maxHD = hd;
}

// BFS to populate the vertical map
void verticalOrder(struct Node* root) {
    if (!root) return;

    struct { struct Node* node; int hd; } queue[MAX_NODES];
    int head = 0, tail = 0;

    queue[tail++] = (typeof(queue[0])){root, 0};

    while (head < tail) {
        struct Node* curr = queue[head].node;
        int hd = queue[head++].hd;

        addToMap(hd, curr->data);

        if (curr->left) queue[tail++] = (typeof(queue[0])){curr->left, hd - 1};
        if (curr->right) queue[tail++] = (typeof(queue[0])){curr->right, hd + 1};
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int* arr = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    // Build tree using level order (same logic as previous response)
    struct Node* root = newNode(arr[0]);
    struct Node* q[MAX_NODES];
    int h = 0, t = 0;
    if (root) q[t++] = root;
    int i = 1;
    while (i < n) {
        struct Node* curr = q[h++];
        if (i < n) {
            curr->left = newNode(arr[i++]);
            if (curr->left) q[t++] = curr->left;
        }
        if (i < n) {
            curr->right = newNode(arr[i++]);
            if (curr->right) q[t++] = curr->right;
        }
    }

    verticalOrder(root);

    // Print columns from leftmost to rightmost
    for (int j = minHD; j <= maxHD; j++) {
        struct ColumnNode* temp = map[j + OFFSET];
        while (temp) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }

    return 0;
}
