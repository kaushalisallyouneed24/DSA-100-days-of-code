#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    // Get number of vertices and edges
    if (scanf("%d %d", &n, &m) != 2) return 0;

    // 1. Allocate and Initialize the Matrix to 0
    // We use n+1 to accommodate 1-based indexing easily
    int** adjMatrix = (int**)malloc((n + 1) * sizeof(int*));
    for (int i = 0; i <= n; i++) {
        adjMatrix[i] = (int*)calloc((n + 1), sizeof(int));
    }

    // 2. Read m edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        
        // Mark the connection
        adjMatrix[u][v] = 1;
        
        // If undirected, mark the reverse as well
        adjMatrix[v][u] = 1; 
    }

    // 3. Output the Matrix (skipping index 0 for 1-based display)
    printf("\nAdjacency Matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }

    // Cleanup
    for (int i = 0; i <= n; i++) free(adjMatrix[i]);
    free(adjMatrix);

    return 0;
}
