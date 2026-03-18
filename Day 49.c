#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new BST node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Recursive function to insert a value into the BST
struct Node* insert(struct Node* root, int data) {
    // If the tree/branch is empty, return a new node
    if (root == NULL) {
        return createNode(data);
    }

    // Otherwise, recur down the tree
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    // Return the (unchanged) node pointer
    return root;
}

// Inorder traversal to verify the BST (should print in ascending order)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    int n, val;
    struct Node* root = NULL;

    // Input: Number of elements followed by the elements
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &val) == 1) {
            root = insert(root, val);
        }
    }

    // Output the resulting BST using Inorder Traversal
    inorder(root);
    printf("\n");

    return 0;
}
