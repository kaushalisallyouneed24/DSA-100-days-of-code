#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the adjacency list
struct Node {
    int dest;
    struct Node* next;
};

// Structure for the Graph
struct Graph {
    int numVertices;
    struct Node** adjLists;
    int* visited;
};

// Create a new node
struct Node* createNode(int d) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->dest = d;
    newNode->next = NULL;
    return newNode;
}

// Create a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(struct Node*));
    graph->visited = malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

// Add edge (Directed)
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

// Recursive DFS function
void topologicalSortUtil(int v, struct Graph* graph, int stack[], int* stackIndex) {
    graph->visited[v] = 1;

    struct Node* temp = graph->adjLists[v];
    while (temp) {
        int connectedVertex = temp->dest;
        if (!graph->visited[connectedVertex]) {
            topologicalSortUtil(connectedVertex, graph, stack, stackIndex);
        }
        temp = temp->next;
    }

    // Push current vertex to stack
    stack[(*stackIndex)++] = v;
}

// Main function to perform Topological Sort
void topologicalSort(struct Graph* graph) {
    int* stack = malloc(graph->numVertices * sizeof(int));
    int stackIndex = 0;

    for (int i = 0; i < graph->numVertices; i++) {
        if (!graph->visited[i]) {
            topologicalSortUtil(i, graph, stack, &stackIndex);
        }
    }

    printf("Topological Ordering: ");
    while (stackIndex > 0) {
        printf("%d ", stack[--stackIndex]);
    }
    printf("\n");

    free(stack);
}

int main() {
    int vertices = 6;
    struct Graph* graph = createGraph(vertices);

    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);

    topologicalSort(graph);

    return 0;
}
