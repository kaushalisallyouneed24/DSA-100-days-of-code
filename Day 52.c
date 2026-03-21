#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Create a new node
struct Node* newNode(int val) {
    if (val == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Build tree from level-order traversal
struct Node* buildTree(int n, int* arr) {
    if (n == 0 || arr[0] == -1) return NULL;
    
    struct Node* root = newNode(arr[0]);
    struct Node** queue = malloc(sizeof(struct Node*) * n);
    int head = 0, tail = 0;
    queue[tail++] = root;

    int i = 1;
    while (i < n) {
        struct Node* curr = queue[head++];
        
        // Left child
        if (i < n) {
            curr->left = newNode(arr[i++]);
            if (curr->left) queue[tail++] = curr->left;
        }
        // Right child
        if (i < n) {
            curr->right = newNode(arr[i++]);
            if (curr->right) queue[tail++] = curr->right;
        }
    }
    free(queue);
    return root;
}

// LCA Function for General Binary Tree
struct Node* findLCA(struct Node* root, int p, int q) {
    if (root == NULL || root->data == p || root->data == q) {
        return root;
    }

    struct Node* leftLCA = findLCA(root->left, p, q);
    struct Node* rightLCA = findLCA(root->right, p, q);

    if (leftLCA && rightLCA) return root; // Found the split point
    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

int main() {
    int n, p, q;
    if (scanf("%d", &n) != 1) return 0;
    
    int* arr = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    scanf("%d %d", &p, &q);

    struct Node* root = buildTree(n, arr);
    struct Node* lca = findLCA(root, p, q);

    if (lca) printf("%d\n", lca->data);

    return 0;
}
