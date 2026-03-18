#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void printZigZag(struct Node* root) {
    if (!root) return;

    // Two stacks for alternating levels
    struct Node* s1[1000]; // Left to Right
    struct Node* s2[1000]; // Right to Left
    int top1 = -1, top2 = -1;

    s1[++top1] = root;

    while (top1 >= 0 || top2 >= 0) {
        // Process Level: Left to Right
        while (top1 >= 0) {
            struct Node* curr = s1[top1--];
            printf("%d ", curr->data);

            // Push children to s2: Left then Right
            if (curr->left) s2[++top2] = curr->left;
            if (curr->right) s2[++top2] = curr->right;
        }

        // Process Level: Right to Left
        while (top2 >= 0) {
            struct Node* curr = s2[top2--];
            printf("%d ", curr->data);

            // Push children to s1: Right then Left
            if (curr->right) s1[++top1] = curr->right;
            if (curr->left) s1[++top1] = curr->left;
        }
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    // Build tree using level order queue
    struct Node* root = newNode(arr[0]);
    struct Node* q[1000];
    int head = 0, tail = 0;
    if (root) q[tail++] = root;
    
    int i = 1;
    while (i < n) {
        struct Node* curr = q[head++];
        if (i < n) {
            curr->left = newNode(arr[i++]);
            if (curr->left) q[tail++] = curr->left;
        }
        if (i < n) {
            curr->right = newNode(arr[i++]);
            if (curr->right) q[tail++] = curr->right;
        }
    }

    printZigZag(root);
    printf("\n");
