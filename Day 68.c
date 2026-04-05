#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {
    int* inDegree = (int*)calloc(numCourses, sizeof(int));
    int** adj = (int**)malloc(numCourses * sizeof(int*));
    int* adjSize = (int*)calloc(numCourses, sizeof(int));

    // 1. Build Adjacency List and Calculate In-Degrees
    for (int i = 0; i < prerequisitesSize; i++) {
        int course = prerequisites[i][0];
        int pre = prerequisites[i][1];
        adjSize[pre]++;
    }

    for (int i = 0; i < numCourses; i++) {
        adj[i] = (int*)malloc(adjSize[i] * sizeof(int));
        adjSize[i] = 0; // Reset to use as index for filling
    }

    for (int i = 0; i < prerequisitesSize; i++) {
        int course = prerequisites[i][0];
        int pre = prerequisites[i][1];
        adj[pre][adjSize[pre]++] = course;
        inDegree[course]++;
    }

    // 2. Initialize Queue with nodes having 0 in-degree
    int* queue = (int*)malloc(numCourses * sizeof(int));
    int head = 0, tail = 0;
    for (int i = 0; i < numCourses; i++) {
        if (inDegree[i] == 0) {
            queue[tail++] = i;
        }
    }

    // 3. Process the Queue (BFS)
    int* result = (int*)malloc(numCourses * sizeof(int));
    int count = 0;

    while (head < tail) {
        int u = queue[head++];
        result[count++] = u;

        for (int i = 0; i < adjSize[u]; i++) {
            int v = adj[u][i];
            inDegree[v]--;
            if (inDegree[v] == 0) {
                queue[tail++] = v;
            }
        }
    }

    // 4. Cleanup and Cycle Check
    free(inDegree);
    free(queue);
    for (int i = 0; i < numCourses; i++) free(adj[i]);
    free(adj);
    free(adjSize);

    if (count == numCourses) {
        *returnSize = numCourses;
        return result;
    } else {
        // Cycle detected: return empty array
        free(result);
        *returnSize = 0;
        return NULL;
    }
}
