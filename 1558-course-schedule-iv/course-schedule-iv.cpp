class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {

        int n = numCourses;

        vector<vector<int>> graph(n);

        for (auto p : prerequisites) {
            int u = p[0], v = p[1];
            graph[u].push_back(v);
        }

        int m = queries.size();

        vector<bool> ans(m, false);

        auto dfs = [&](int u, int v) {
            queue<int> q;
            vector<bool> visited(n, false);
            q.push(u);
            visited[u] = true;
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                for (int nxt : graph[curr])
                    if (!visited[nxt]) {
                        if (nxt == v)
                            return true;
                        visited[nxt] = true;
                        q.push(nxt);
                    }
            }
            return false;
        };

        for (int i = 0; i < m; i++) {
            ans[i] = dfs(queries[i][0], queries[i][1]);
        }

        return ans;
    }
};
class Solution_2084ms {
public:
    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {

        int n = numCourses;

        vector<vector<bool>> path(n, vector<bool>(n, false));

        for (int I = 0; I < n; I++)
            for (auto p : prerequisites) {
                int u = p[0], v = p[1];

                path[u][v] = true;

                for (int i = 0; i < n; i++) {
                    if (path[i][u]) {
                        path[i][v] = true;
                    }
                }
            }

        int m = queries.size();

        vector<bool> ans(m, false);

        for (int i = 0; i < m; i++) {
            ans[i] = path[queries[i][0]][queries[i][1]];
        }

        return ans;
    }
};