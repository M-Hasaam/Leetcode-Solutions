class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        using P = pair<int, int>;

        vector<vector<P>> graph(n);

        for (auto edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];

            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        auto dijkstra = [&](int node) {
            vector<int> dist(n, INT_MAX);
            priority_queue<P, vector<P>, greater<P>> pq;

            pq.push({0, node});
            dist[node] = 0;

            while (!pq.empty()) {
                auto [d, u] = pq.top();
                pq.pop();

                if (dist[u] != d)
                    continue;

                for (auto [v, w] : graph[u]) {
                    if (d + w < dist[v]) {
                        dist[v] = d + w;
                        pq.push({dist[v], v});
                    }
                }
            }

            return dist;
        };

        int bestCity = -1;
        int minReachable = INT_MAX;

        for (int city = 0; city < n; city++) {
            vector<int> dist = dijkstra(city);

            int reachableCount = 0;
            for (int d : dist) {
                if (d <= distanceThreshold)
                    reachableCount++;
            }

            if (reachableCount <= minReachable) {
                minReachable = reachableCount;
                bestCity = city;
            }
        }

        return bestCity;
    }
};