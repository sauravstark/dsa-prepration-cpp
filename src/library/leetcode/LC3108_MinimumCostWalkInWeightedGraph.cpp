#include <algorithm>
#include <queue>
#include <library/leetcode/LC3108_MinimumCostWalkInWeightedGraph.h>

class UndirectedWeightedMultiEdgeGraph {
public:
    explicit UndirectedWeightedMultiEdgeGraph(const int size) : adjList(size) {
    }

    void addEdge(int node1, int node2, int weight) {
        adjList[node1].emplace_back(node2, weight);
        adjList[node2].emplace_back(node1, weight);
    }

    const std::vector<std::pair<int, int> > &getAdjList(const int node) {
        return adjList[node];
    }

private:
    std::vector<std::vector<std::pair<int, int> > > adjList;
};

std::vector<int> Library::LeetCode::LC3108::minimumCost(const int n, std::vector<std::vector<int> > &edges,
                                                         std::vector<std::vector<int> > &queries) {
    UndirectedWeightedMultiEdgeGraph graph(n);
    for (const auto &edge: edges)
        graph.addEdge(edge[0], edge[1], edge[2]);

    std::vector visited(n, false);
    std::vector<int> componentIds(n);
    std::vector<int> componentDist;
    std::queue<int> q;

    int currentId = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i])
            continue;
        visited[i] = true;
        q.push(i);
        componentDist.push_back(-1);
        while (!q.empty()) {
            const int node = q.front();
            q.pop();
            componentIds[node] = currentId;
            for (const auto &[neighbor, weight]: graph.getAdjList(node)) {
                componentDist.back() &= weight;
                if (visited[neighbor])
                    continue;
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
        currentId++;
    }

    std::vector<int> result(queries.size());

    std::ranges::transform(queries, result.begin(), [&componentIds, &componentDist](const std::vector<int> &query) {
        if (componentIds[query[0]] != componentIds[query[1]])
            return -1;
        return componentDist[componentIds[query[0]]];
    });

    return result;
}
