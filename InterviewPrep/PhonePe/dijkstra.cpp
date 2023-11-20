#include <vector>
#include <queue>
#include <climits>
#include <iostream>

using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    vector<vector<int>> weightedGraph[vertices];

    for (int i = 0; i < vec.size(); i++) {
        int u = vec[i][0],
            v = vec[i][1],
            w = vec[i][2];
        weightedGraph[u].push_back({v, w});
        weightedGraph[v].push_back({u, w});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dist(vertices, INT_MAX);

    pq.push({0, source});
    dist[source] = 0;

    while (!pq.empty()) {
        int currentNode = pq.top().second, currentDist = pq.top().first;
        pq.pop();

        for (auto &neighbor : weightedGraph[currentNode]) {
            int neighborNode = neighbor[0], neighborDist = neighbor[1];

            if (currentDist + neighborDist < dist[neighborNode]) {
                dist[neighborNode] = currentDist + neighborDist;
                pq.push({dist[neighborNode], neighborNode});
            }
        }
    }

    return dist;
}

int main() {
    vector<vector<int>> vec{
        {0, 1, 7},
        {0, 2, 1},
        {0, 3, 2},
        {1, 2, 3},
        {1, 3, 5},
        {1, 4, 1},
        {3, 4, 7}
    };


    vector<int> ans = dijkstra(vec, 5, 7, 0);

    for (int i : ans)
        cout << i << " ";

    return 0;
}

