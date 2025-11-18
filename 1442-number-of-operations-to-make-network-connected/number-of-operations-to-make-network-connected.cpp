class Solution {

public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        if (connections.size() < n - 1)
            return -1;

        vector<vector<int>> graph(n);

        for (auto con : connections) {
            int u = con[0], v = con[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<bool> visited(n, false);

        int components = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                visited[i] = true;
                components++;

                queue<int> q;
                q.push(i);

                while (!q.empty()) {
                    int curr = q.front();
                    q.pop();

                    for (auto nxt : graph[curr]) {
                        if (!visited[nxt]) {
                            visited[nxt] = true;

                            q.push(nxt);
                        }
                    }
                }
            }
        }

        return components - 1;
    }
};