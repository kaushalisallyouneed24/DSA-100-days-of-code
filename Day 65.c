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

// Recursive DFS to detect cycle
bool isCycleRecursive(int curr, int parent, struct Node** adjList, bool* visited) {
    visited[curr] = true;

    struct Node* temp = adjList[curr];
    while (temp != NULL) {
        int neighbor = temp->vertex;

        // If the neighbor is not visited, recurse
        if (!visited[neighbor]) {
            if (isCycleRecursive(neighbor, curr, adjList, visited)) {
                return true;
            }
        }
        // If the neighbor IS visited and is NOT the parent, cycle found
        else if (neighbor != parent) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

bool hasCycle(int n, struct Node** adjList) {
    bool* visited = (bool*)calloc(n + 1, sizeof(bool));

    // Loop through all nodes to handle disconnected components
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            // Initial call has parent as -1
            if (isCycleRecursive(i, -1, adjList, visited)) {
                free(visited);
                return true;
            }
        }
    }

    free(visited);
    return false;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    struct Node** adjList = (struct Node**)malloc((n + 1) * sizeof(struct Node*));
    for (int i = 0; i <= n; i++) adjList[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        // Undirected graph edges
        struct Node* newNodeV = createNode(v);
        newNodeV->next = adjList[u];
        adjList[u] = newNodeV;

        struct Node* newNodeU = createNode(u);
        newNodeU->next = adjList[v];
        adjList[v] = newNodeU;
    }

    if (hasCycle(n, adjList)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    // Cleanup omitted for brevity
    return 0;
}
