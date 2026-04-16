#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void floydWarshall(vector<vector<int>>& graph) {
        int n = graph.size();
        const int INF = 1e9;

        // Replace -1 with INF (except diagonal)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][j] == -1 && i != j) {
                    graph[i][j] = INF;
                }
            }
        }

        // Floyd-Warshall Algorithm
        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (graph[i][via] < INF && graph[via][j] < INF) {
                        graph[i][j] = min(graph[i][j],
                                          graph[i][via] + graph[via][j]);
                    }
                }
            }
        }

        // Convert INF back to -1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][j] == INF) {
                    graph[i][j] = -1;
                }
            }
        }
    }
};

int main() {
    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    Solution obj;
    obj.floydWarshall(graph);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
