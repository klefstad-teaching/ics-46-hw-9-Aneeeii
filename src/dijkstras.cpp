#include "../src/dijkstras.h"
#include <vector>
#include <queue>

std::vector<int> dijkstra_shortest_path(const Graph& G, int source, std::vector<int>& previous) {
    std::vector<int> distances(G.numVertices, INF);
    std::vector<bool> visited(G.numVertices, false);
    distances[source] = 0;
    previous[source] = -1;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> minHeap;
    minHeap.push({0, source});
    while (!minHeap.empty()) {
        int u = minHeap.top().second;
        minHeap.pop();
        if (visited[u]) continue;
        visited[u] = true;
        for (Edge edge : G[u]) {
            int v = edge.dst;
            int weight = edge.weight;
            if (!visited[v] && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                previous[v] = u;
                minHeap.push({distances[v], v});
            }
        }
    }
    return distances;
}

std::vector<int> extract_shortest_path(const std::vector<int>& distances, const std::vector<int>& previous, int destination) {
    std::vector<int> result;
    if (distances[destination] == INF)
        return {};
    for (int current = destination; current != -1; current = previous[current])
        result.push_back(current);
    std::reverse(result.begin(), result.end());
    return result;
}

void print_path(const std::vector<int>& v, int total) {
    for (int i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl << "Total cost is " << total << std::endl;
}