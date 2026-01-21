class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);

        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i])
                continue;

            queue<int> q;
            q.push(i);
            visited[i] = true;

            int nodes = 0;
            int edgeCount = 0;

            while (!q.empty()) {
                int u = q.front();
                q.pop();
                nodes++;
                edgeCount += graph[u].size();

                for (int v : graph[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }

            edgeCount /= 2;

            if (edgeCount == nodes * (nodes - 1) / 2) {
                ans++;
            }
        }

        return ans;
    }
};
