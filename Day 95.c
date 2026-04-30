#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    float value;
    struct Node* next;
} Node;

// Insert in sorted order
void insertSorted(Node** head, float value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    if (*head == NULL || (*head)->value >= value) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* curr = *head;
    while (curr->next != NULL && curr->next->value < value) {
        curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;
}

void bucketSort(float arr[], int n) {
    if (n <= 0) return;

    Node** buckets = (Node**)calloc(n, sizeof(Node*));

    // Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int index = (int)(arr[i] * n);
        insertSorted(&buckets[index], arr[i]);
    }

    // Concatenate buckets
    int k = 0;
    for (int i = 0; i < n; i++) {
        Node* curr = buckets[i];
        while (curr != NULL) {
            arr[k++] = curr->value;
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }

    free(buckets);
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    bucketSort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%.6f ", arr[i]);
    }

    return 0;
}
