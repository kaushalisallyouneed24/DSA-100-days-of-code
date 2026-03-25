#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    if (val == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Function to convert tree to its mirror
void mirror(struct Node* root) {
    if (root == NULL) return;

    // Recurse to the bottom
    mirror(root->left);
    mirror(root->right);

    // Swap the pointers
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
}

// Standard Inorder Traversal
void printInorder(struct Node* root) {
    if (root == NULL) return;
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    // Build tree using level-order input
    if (n == 0 || arr[0] == -1) return 0;
    
    struct Node* root = newNode(arr[0]);
    struct Node* q[1000];
    int h = 0, t = 0;
    q[t++] = root;
    
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

    // 1. Mirror the tree
    mirror(root);

    // 2. Print inorder traversal
    printInorder(root);
    printf("\n");

    return 0;
}
