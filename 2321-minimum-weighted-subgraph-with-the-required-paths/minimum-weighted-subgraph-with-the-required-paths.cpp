class Solution {
public:
    const long long INF = 1e18;

    vector<long long> dijkstra(int start, vector<vector<pair<int,int>>>& graph) {
        int n = graph.size();
        vector<long long> dist(n, INF);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;

        dist[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue;

            for (auto [v, w] : graph[u]) {
                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }

    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int,int>>> graph(n), revGraph(n);

        for (auto &e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
            revGraph[e[1]].push_back({e[0], e[2]});
        }

        vector<long long> dist1 = dijkstra(src1, graph);
        vector<long long> dist2 = dijkstra(src2, graph);
        vector<long long> dist3 = dijkstra(dest, revGraph);

        long long ans = INF;

        for (int i = 0; i < n; i++) {
            if (dist1[i] == INF || dist2[i] == INF || dist3[i] == INF) continue;
            ans = min(ans, dist1[i] + dist2[i] + dist3[i]);
        }

        return ans == INF ? -1 : ans;
    }
};
