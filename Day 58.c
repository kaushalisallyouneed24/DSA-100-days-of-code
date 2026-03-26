#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper to create a new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Function to find index of value in inorder array
int findIndex(int* arr, int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) return i;
    }
    return -1;
}

// Recursive function to build the tree
struct TreeNode* buildTree(int* preorder, int* inorder, int inStart, int inEnd, int* preIdx) {
    if (inStart > inEnd) return NULL;

    // The current root is the element at preIdx in preorder array
    int rootVal = preorder[*preIdx];
    struct TreeNode* root = newNode(rootVal);
    (*preIdx)++;

    // Find the index of this root in inorder array to split subtrees
    int inIdx = findIndex(inorder, inStart, inEnd, rootVal);

    // Build Left subtree then Right subtree
    root->left = buildTree(preorder, inorder, inStart, inIdx - 1, preIdx);
    root->right = buildTree(preorder, inorder, inIdx + 1, inEnd, preIdx);

    return root;
}

// Function to print Postorder traversal (Left, Right, Root)
void printPostorder(struct TreeNode* root) {
    if (root == NULL) return;
    
    printPostorder(root->left);
    printPostorder(root->right);
    printf("%d ", root->val);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int* preorder = (int*)malloc(sizeof(int) * n);
    int* inorder = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) scanf("%d", &preorder[i]);
    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);

    int preIdx = 0;
    struct TreeNode* root = buildTree(preorder, inorder, 0, n - 1, &preIdx);

    printPostorder(root);
    printf("\n");

    // Clean up memory (Optional for short competitive programming scripts)
    free(preorder);
    free(inorder);

    return 0;
}
