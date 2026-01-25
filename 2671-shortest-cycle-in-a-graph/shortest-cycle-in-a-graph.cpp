class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        int ans = INT_MAX;

        for (int start = 0; start < n; start++) {
            vector<int> dist(n, -1);
            vector<int> parent(n, -1);
            queue<int> q;

            q.push(start);
            dist[start] = 0;

            while (!q.empty()) {
                int u = q.front(); q.pop();

                for (int v : graph[u]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        parent[v] = u;
                        q.push(v);
                    }
                    else if (parent[u] != v) {
                        ans = min(ans, dist[u] + dist[v] + 1);
                    }
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
