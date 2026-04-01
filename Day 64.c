#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Adjacency List Node
struct Node {
    int vertex;
    struct Node* next;
};

// Helper to create a new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void BFS(int startNode, int n, struct Node** adjList) {
    bool* visited = (bool*)calloc(n + 1, sizeof(bool));
    
    // Create a queue for BFS
    int* queue = (int*)malloc((n + 1) * sizeof(int));
    int front = 0, rear = 0;

    // 1. Mark the start node as visited and enqueue it
    visited[startNode] = true;
    queue[rear++] = startNode;

    printf("BFS Traversal starting from %d: ", startNode);

    while (front < rear) {
        // 2. Dequeue a vertex from queue and print it
        int curr = queue[front++];
        printf("%d ", curr);

        // 3. Get all adjacent vertices of the dequeued vertex
        struct Node* temp = adjList[curr];
        while (temp) {
            int neighbor = temp->vertex;

            // 4. If a neighbor has not been visited, mark it and enqueue
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                queue[rear++] = neighbor;
            }
            temp = temp->next;
        }
    }
    printf("\n");

    free(visited);
    free(queue);
}

int main() {
    int n, m, s;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    // Initialize Adjacency List
    struct Node** adjList = (struct Node**)malloc((n + 1) * sizeof(struct Node*));
    for (int i = 0; i <= n; i++) adjList[i] = NULL;

    // Build the graph (Undirected)
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        
        struct Node* nodeV = createNode(v);
        nodeV->next = adjList[u];
        adjList[u] = nodeV;

        struct Node* nodeU = createNode(u);
        nodeU->next = adjList[v];
        adjList[v] = nodeU;
    }

    // Starting vertex
    scanf("%d", &s);

    BFS(s, n, adjList);

    // Memory Cleanup
    for (int i = 1; i <= n; i++) {
        struct Node* temp = adjList[i];
