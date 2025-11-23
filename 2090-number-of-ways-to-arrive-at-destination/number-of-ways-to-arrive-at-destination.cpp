class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        const int MOD = 1e9 + 7;
        vector<vector<pair<int, int>>> graph(n);

        for (auto road : roads) {
            int u = road[0], v = road[1], w = road[2];

            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        using P = pair<long long, int>;
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<long long> dist(n, LLONG_MAX);
        vector<int> way(n, 0);

        pq.push({0, 0});
        dist[0] = 0;
        way[0] = 1;

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d != dist[u])
                continue;

            for (auto [v, w] : graph[u]) {
                // int v = nxt[0], w = nxt[1];

                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    way[v] = way[u];
                    pq.push({dist[v], v});
                } else if (dist[v] == dist[u] + w) {
                    way[v] += way[u];
                    way[v] %= MOD;
                }
            }
        }
        return way[n - 1];
    }
};