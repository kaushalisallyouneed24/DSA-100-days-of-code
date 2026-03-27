#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Linear search for root index in inorder array
int findIndex(int* arr, int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) return i;
    }
    return -1;
}

// Recursive function to build tree from Inorder and Postorder
struct TreeNode* buildTree(int* inorder, int* postorder, int inStart, int inEnd, int* postIdx) {
    if (inStart > inEnd) return NULL;

    // Root is the current last element in the postorder range
    int rootVal = postorder[*postIdx];
    struct TreeNode* root = newNode(rootVal);
    (*postIdx)--; // Move to the next root (for the right subtree)

    int inIdx = findIndex(inorder, inStart, inEnd, rootVal);

    // Build Right Subtree then Left Subtree (Postorder: Left, Right, Root)
    // Moving backwards from Root, we hit Right then Left.
    root->right = buildTree(inorder, postorder, inIdx + 1, inEnd, postIdx);
    root->left = buildTree(inorder, postorder, inStart, inIdx - 1, postIdx);

    return root;
}

// Preorder Traversal: Root -> Left -> Right
void printPreorder(struct TreeNode* root) {
    if (root == NULL) return;
    
    printf("%d ", root->val);
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int* inorder = (int*)malloc(sizeof(int) * n);
    int* postorder = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);
    for (int i = 0; i < n; i++) scanf("%d", &postorder[i]);

    int postIdx = n - 1; // Start from the last element of postorder
    struct TreeNode* root = buildTree(inorder, postorder, 0, n - 1, &postIdx);

    printPreorder(root);
    printf("\n");

    free(inorder);
    free(postorder);
    return 0;
}  
