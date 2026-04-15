#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

// Structure to represent an adjacency list node
struct Node {
    int target, weight;
    struct Node* next;
};

// Structure for the Min-Heap
struct HeapNode {
    int v, dist;
};

struct MinHeap {
    int size, capacity;
    int *pos; // To keep track of node positions in heap
    struct HeapNode **array;
};

// --- Helper Functions for Adjacency List ---
void addEdge(struct Node** adj, int u, int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->target = v;
    newNode->weight = w;
    newNode->next = adj[u];
    adj[u] = newNode;
}

// --- Helper Functions for Min-Heap ---
struct HeapNode* newHeapNode(int v, int dist) {
    struct HeapNode* node = (struct HeapNode*)malloc(sizeof(struct HeapNode));
    node->v = v;
    node->dist = dist;
    return node;
}

void swapNodes(struct HeapNode** a, struct HeapNode** b) {
    struct HeapNode* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && heap->array[left]->dist < heap->array[smallest]->dist)
        smallest = left;
    if (right < heap->size && heap->array[right]->dist < heap->array[smallest]->dist)
        smallest = right;

    if (smallest != idx) {
        heap->pos[heap->array[smallest]->v] = idx;
        heap->pos[heap->array[idx]->v] = smallest;
        swapNodes(&heap->array[smallest], &heap->array[idx]);
        minHeapify(heap, smallest);
    }
}

struct HeapNode* extractMin(struct MinHeap* heap) {
    if (heap->size == 0) return NULL;
    struct HeapNode* root = heap->array[0];
    struct HeapNode* lastNode = heap->array[heap->size - 1];
    heap->array[0] = lastNode;
    heap->pos[root->v] = heap->size - 1;
    heap->pos[lastNode->v] = 0;
    --heap->size;
    minHeapify(heap, 0);
    return root;
}

void decreaseKey(struct MinHeap* heap, int v, int dist) {
    int i = heap->pos[v];
    heap->array[i]->dist = dist;
    while (i && heap->array[i]->dist < heap->array[(i - 1) / 2]->dist) {
        heap->pos[heap->array[i]->v] = (i - 1) / 2;
        heap->pos[heap->array[(i - 1) / 2]->v] = i;
        swapNodes(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// --- Main Dijkstra Logic ---
void dijkstra(int n, struct Node** adj, int src) {
    int dist[n + 1];
    struct MinHeap* heap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    heap->pos = (int*)malloc((n + 1) * sizeof(int));
    heap->size = n;
    heap->capacity = n;
    heap->array = (struct HeapNode**)malloc(n * sizeof(struct HeapNode*));

    for (int v = 1; v <= n; ++v) {
        dist[v] = INF;
        heap->array[v - 1] = newHeapNode(v, dist[v]);
        heap->pos[v] = v - 1;
    }

    dist[src] = 0;
    decreaseKey(heap, src, dist[src]);

    while (heap->size != 0) {
        struct HeapNode* minNode = extractMin(heap);
        int u = minNode->v;

        struct Node* temp = adj[u];
        while (temp != NULL) {
            int v = temp->target;
            if (heap->pos[v] < heap->size && dist[u] != INF && temp->weight + dist[u] < dist[v]) {
                dist[v] = dist[u] + temp->weight;
                decreaseKey(heap, v, dist[v]);
            }
            temp = temp->next;
        }
        free(minNode);
    }

    for (int i = 1; i <= n; ++i) printf("%d ", dist[i]);
    printf("\n");
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    struct Node* adj[n + 1];
    for (int i = 0; i <= n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(adj, u, v, w);
        addEdge(adj, v, u, w); // Undirected
    }

    int source;
    scanf("%d", &source);
    dijkstra(n, adj, source);

    return 0;
}
