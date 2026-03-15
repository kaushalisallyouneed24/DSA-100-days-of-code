#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Standard node creation
struct Node* createNode(int data) {
    if (data == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Build tree from Level-Order input (Queue-based)
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* root = createNode(arr[0]);
    struct Node* queue[n];
    int front = 0, rear = 0;
    queue[rear++] = root;
    int i = 1;
    while (i < n) {
        struct Node* curr = queue[front++];
        if (i < n) {
            curr->left = createNode(arr[i++]);
            if (curr->left) queue[rear++] = curr->left;
        }
        if (i < n) {
            curr->right = createNode(arr[i++]);
            if (curr->right) queue[rear++] = curr->right;
        }
    }
    return root;
}

// The Level Order Traversal Function
void levelOrder(struct Node* root, int n) {
    if (root == NULL) return;

    struct Node* queue[n]; // Using array-based queue
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct Node* curr = queue[front++];
        
        printf("%d ", curr->data);

        if (curr->left != NULL) {
            queue[rear++] = curr->left;
        }
        if (curr->right != NULL) {
            queue[rear++] = curr->right;
        }
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);
    
    levelOrder(root, n);
    printf("\n");

    return 0;
}
