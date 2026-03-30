#include <stdio.h>
#include <stdlib.h>

// 1. Structure for a node in the adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// 2. Helper to create a new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n, m;
    // Get number of vertices and edges
    if (scanf("%d %d", &n, &m) != 2) return 0;

    // 3. Initialize the array of pointers (heads) to NULL
    // Using n+1 for 1-based indexing
    struct Node** adjList = (struct Node**)malloc((n + 1) * sizeof(struct Node*));
    for (int i = 0; i <= n; i++) {
        adjList[i] = NULL;
    }

    // 4. Add m edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        // Add v to u's list
        struct Node* newNodeV = createNode(v);
        newNodeV->next = adjList[u];
        adjList[u] = newNodeV;

        // If undirected, add u to v's list as well
        struct Node* newNodeU = createNode(u);
        newNodeU->next = adjList[v];
        adjList[v] = newNodeU;
    }

    // 5. Output the Adjacency List
    printf("\nAdjacency List:\n");
    for (int i = 1; i <= n; i++) {
        struct Node* temp = adjList[i];
        printf("Vertex %d: ", i);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }

    // Cleanup: Free all nodes and the array
    for (int i = 1; i <= n; i++) {
        struct Node* temp = adjList[i];
        while (temp) {
            struct Node* toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
    }
    free(adjList);

    return 0;
}
