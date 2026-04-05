#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Pair format: {distance, node_index}
typedef pair<int, int> pii;

vector<int> dijkstra(int numNodes, vector<vector<pii>>& adj, int source) {
    // Distance array initialized to infinity
    vector<int> dist(numNodes, INT_MAX);
    
    // Min-priority queue: higher priority given to smaller distances
    // priority_queue<Type, Container, Comparator>
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    // Start with the source
    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // If we found a shorter path to u already, skip this outdated entry
        if (d > dist[u]) continue;

        // Traverse neighbors
        for (auto& neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            // Relaxation step
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    int n = 5; // Number of nodes
    vector<vector<pii>> adj(n);

    // Graph Construction: {neighbor, weight}
    adj[0].push_back({1, 2});
    adj[0].push_back({4, 1});
    adj[1].push_back({2, 3});
    adj[4].push_back({2, 2});
    adj[4].push_back({3, 1});
    adj[3].push_back({2, 1});

    int source = 0;
    vector<int> result = dijkstra(n, adj, source);

    cout << "Shortest distances from source " << source << ":" << endl;
    for (int i = 0; i < n; i++) {
        cout << "To " << i << " : " << (result[i] == INT_MAX ? -1 : result[i]) << endl;
    }

    return 0;
}
