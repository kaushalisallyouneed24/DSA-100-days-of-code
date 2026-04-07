#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Edge {
    int u, v, w;
};

void bellmanFord(int n, int m, struct Edge edges[], int src) {
    long* dist = (long*)malloc(n * sizeof(long));
    for (int i = 0; i < n; i++) dist[i] = INT_MAX;
    dist[src] = 0;

    // 1. Relax edges n-1 times
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // 2. Detect Negative Cycle (n-th iteration)
    int hasCycle = 0;
    for (int j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            hasCycle = 1;
            break;
        }
    }

    // 3. Output results
    if (hasCycle) {
        printf("NEGATIVE CYCLE\n");
    } else {
        printf("Shortest distances from source %d:\n", src);
        for (int i = 0; i < n; i++) {
            if (dist[i] == INT_MAX) printf("%d: INF\n", i);
            else printf("%d: %ld\n", i, dist[i]);
        }
    }

    free(dist);
}

int main() {
    int n = 4, m = 4;
    struct Edge edges[] = {
        {0, 1, 1},
        {1, 2, -1},
        {2, 3, -1},
        {3, 0, -1} // This creates a cycle: 0->1->2->3->0 (Sum = -2)
    };

    bellmanFord(n, m, edges, 0);
    return 0;
}
