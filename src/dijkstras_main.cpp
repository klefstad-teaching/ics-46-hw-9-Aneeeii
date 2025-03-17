#include "../src/dijkstras.h"
#include <string>
#include <fstream>

int main() {
    std::string filename = "src/small.txt";
    Graph g;
    std::ifstream file(filename);

    file >> g.numVertices;
    g.resize(g.numVertices);

    int src, dst, weight;
    while (file >> src >> dst >> weight) {
        g[src].push_back({dst, weight});
        g[dst].push_back({src, weight});
    }

    file.close();
    std::vector<int> previous;
    std::vector<int> distances = dijkstra_shortest_path(g, 0, previous);
    std::vector<int> shortest = extract_shortest_path(distances, previous, 3);
    print_path(shortest, shortest.size());

    return 0;
}