#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for a node in the adjacency list
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

// Recursive DFS Function
void DFS(int curr, struct Node** adjList, bool* visited) {
    // 1. Mark the current node as visited and print it
    visited[curr] = true;
    printf("%d ", curr);

    // 2. Traverse all neighbors of the current vertex
    struct Node* temp = adjList[curr];
    while (temp != NULL) {
        int neighbor = temp->vertex;
        
        // 3. If neighbor is not visited, recurse
        if (!visited[neighbor]) {
            DFS(neighbor, adjList, visited);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m, s;
    // n: vertices, m: edges
    if (scanf("%d %d", &n, &m) != 2) return 0;

    // Initialize Adjacency List
    struct Node** adjList = (struct Node**)malloc((n + 1) * sizeof(struct Node*));
    for (int i = 0; i <= n; i++) adjList[i] = NULL;

    // Read edges (assuming undirected for this example)
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        
        struct Node* newNodeV = createNode(v);
        newNodeV->next = adjList[u];
        adjList[u] = newNodeV;

        struct Node* newNodeU = createNode(u);
        newNodeU->next = adjList[v];
        adjList[v] = newNodeU;
    }

    // Read starting vertex
    scanf("%d", &s);

    // Initialize visited array
    bool* visited = (bool*)calloc(n + 1, sizeof(bool));

    printf("DFS Traversal starting from %d: ", s);
    DFS(s, adjList, visited);
    printf("\n");

    // Cleanup memory
    for (int i = 1; i <= n; i++) {
        struct Node* temp = adjList[i];
        while (temp) {
            struct Node* toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
    }
    free(adjList);
    free(visited);

    return 0;
}
