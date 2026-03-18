#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

// Standard BST Insertion
struct Node* insert(struct Node* root, int val) {
    if (root == NULL) return newNode(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

// LCA Function for BST
struct Node* findLCA(struct Node* root, int p, int q) {
    while (root != NULL) {
        // If both p and q are smaller, LCA is in left
        if (p < root->data && q < root->data)
            root = root->left;
        // If both p and q are larger, LCA is in right
        else if (p > root->data && q > root->data)
            root = root->right;
        // Otherwise, we found the split point
        else
            return root;
    }
    return NULL;
}

int main() {
    int n, val, p, q;
    struct Node* root = NULL;

    // Input Reading
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }
    scanf("%d %d", &p, &q);

    // Finding LCA
    struct Node* lca = findLCA(root, p, q);
    
    if (lca != NULL)
        printf("%d\n", lca->data);

    return 0;
}
