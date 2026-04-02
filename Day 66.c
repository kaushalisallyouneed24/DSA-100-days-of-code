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

// Recursive DFS to detect cycle in Directed Graph
bool isCycleDFS(int curr, struct Node** adjList, bool* visited, bool* recStack) {
    // 1. Mark the current node as visited and add to recursion stack
    visited[curr] = true;
    recStack[curr] = true;

    struct Node* temp = adjList[curr];
    while (temp != NULL) {
        int neighbor = temp->vertex;

        // 2. If neighbor not visited, recurse
        if (!visited[neighbor]) {
            if (isCycleDFS(neighbor, adjList, visited, recStack)) {
                return true;
            }
        } 
        // 3. If neighbor is already in the current recursion stack, cycle found!
        else if (recStack[neighbor]) {
            return true;
        }
        temp = temp->next;
    }

    // 4. Remove the node from recursion stack before backtracking
    recStack[curr] = false;
    return false;
}

bool hasCycle(int n, struct Node** adjList) {
    bool* visited = (bool*)calloc(n + 1, sizeof(bool));
    bool* recStack = (bool*)calloc(n + 1, sizeof(bool));

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (isCycleDFS(i, adjList, visited, recStack)) {
                free(visited);
                free(recStack);
                return true;
            }
        }
    }

    free(visited);
    free(recStack);
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
        // Directed Graph: only u -> v
        struct Node* newNode = createNode(v);
        newNode->next = adjList[u];
        adjList[u] = newNode;
    }

    if (hasCycle(n, adjList)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
