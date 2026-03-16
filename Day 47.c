#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Helper to create a new node
struct Node* createNode(int data) {
    if (data == -1) return NULL;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Build the tree from level-order input using a queue
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* root = createNode(arr[0]);
    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * n);
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

// Main recursive function to find height
int getHeight(struct Node* root) {
    if (root == NULL) return 0; // Base case: empty tree has height 0

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    // Return the maximum of the two subtrees + 1 for the current node
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);
    printf("%d\n", getHeight(root));

    return 0;
}
