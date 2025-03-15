#include "../src/dijkstras.h"
#include <vector>
#include <queue>

// G is a vector of vectors of edges
std::vector<int> dijkstras_shortest_path(const Graph& G, int source, std::vector<int>& previous) {
    std::vector<int> distances(G.numVertices, INF);
    std::vector<bool> visited(G.numVertices, false);
    distances[source] = 0;
    previous[source] = -1;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> minHeap;
    minHeap.push({source, 0});
    while (!minHeap.empty()) {
        int u = minHeap.top().first;
        minHeap.pop();
        if (visited[u]) continue;
        visited[u] = true;
        for (Edge edge : G[u]) {
            int v = edge.dst;
            int weight = edge.weight;
            if (!visited[v] && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                previous[v] = u;
                minHeap.push({v, distances[v]});
            }
        }
    }
    return distances;
}

std::vector<int> extract_shortest_path(const std::vector<int>& distances, const std::vector<int>& previous, int destination) {
    
}