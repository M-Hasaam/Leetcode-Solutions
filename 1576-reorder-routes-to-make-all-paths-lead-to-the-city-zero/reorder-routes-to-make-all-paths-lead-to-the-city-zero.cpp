class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> out(n), in(n);

        for (auto con : connections) {
            int u = con[0], v = con[1];

            out[u].push_back(v);
            in[v].push_back(u);
        }

        vector<bool> visited(n, false);

        function<int(int)> dfs = [&](int curr) {
            visited[curr] = true;
            int count = 0;

            for (int o : out[curr]) {
                if (!visited[o]) {
                    count++;
                    count += dfs(o);
                }
            }

            for (int i : in[curr]) {
                if (!visited[i]) {
                    count += dfs(i);
                }
            }

            return count;
        };

        return dfs(0);
    }
};

class Solution_143ms {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);

        for (auto con : connections) {
            int u = con[0], v = con[1];

            graph[u].push_back(v);
            graph[v].push_back(~u);
        }

        queue<int> q;
        vector<bool> visited(n, false);

        q.push(0);
        visited[0] = true;

        int count = 0;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int nx : graph[curr]) {
                if (!visited[nx < 0 ? ~nx : nx]) {
                    count += (nx < 0 ? 0 : 1);
                    q.push(nx < 0 ? ~nx : nx);
                    visited[nx < 0 ? ~nx : nx] = true;
                }
            }
        }

        return count;
    }
};