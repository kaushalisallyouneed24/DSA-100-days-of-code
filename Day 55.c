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

void printRightView(struct Node* root) {
    if (!root) return;

    struct Node* queue[1000];
    int head = 0, tail = 0;
    queue[tail++] = root;

    while (head < tail) {
        // Number of nodes at the current level
        int levelSize = tail - head;

        for (int i = 0; i < levelSize; i++) {
            struct Node* curr = queue[head++];

            // If it's the last node in the current level, print it
            if (i == levelSize - 1) {
                printf("%d ", curr->data);
            }

            // Standard BFS child enrollment
            if (curr->left) queue[tail++] = curr->left;
            if (curr->right) queue[tail++] = curr->right;
        }
    }
    printf("\n");
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    // Build the tree from level-order input
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

    printRightView(root);

    return 0;
}
