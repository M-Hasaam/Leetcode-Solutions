class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {

        int n = numCourses;

        vector<vector<int>> graph(n);
        vector<int> indeg(n, 0);

        for (auto p : prerequisites) {
            int u = p[0], v = p[1];
            graph[u].push_back(v);
            indeg[v]++;
        }

        vector<vector<bool>> reachable(n, vector<bool>(n, false));
        
        {
            queue<int> q;

            for (int i = 0; i < n; i++)
                if (indeg[i] == 0)
                    q.push(i);

            while (!q.empty()) {
                int curr = q.front();
                q.pop();

                for (int nxt : graph[curr]) {
                    indeg[nxt]--;

                    reachable[curr][nxt] = true;

                    for (int i = 0; i < n; i++)
                        if (reachable[i][curr])
                            reachable[i][nxt] = true;

                    if (indeg[nxt] == 0)
                        q.push(nxt);
                }
            }
        }

        vector<bool> ans;
        ans.reserve(n);

        for (auto q : queries)
            ans.push_back(reachable[q[0]][q[1]]);

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