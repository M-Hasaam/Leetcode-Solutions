class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {

        vector<vector<int>> graph(n);

        for (auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> count(n, 1); // count of the node in its subtree
        vector<int> ans(n, 0);   // sum of distance

        function<void(int, int, int)> dfs1 = [&](int node, int parent,
                                                 int dept) {
            ans[0] += dept;
            for (auto nxt : graph[node]) {
                if (nxt == parent)
                    continue;

                dfs1(nxt, node, dept + 1);

                count[node] += count[nxt];
            }
        };

        dfs1(0, -1, 0);

        function<void(int, int)> dfs2 = [&](int node, int parent) {
            for (int nxt : graph[node]) {
                if (nxt == parent)
                    continue;
                
                // Re-rooting DP transition:
                //
                // Let S(u) = sum of distances from node u to all other nodes.
                // Let C(v) = size of subtree rooted at v.
                // Let N = total number of nodes.
                //
                // When we move the "root" from a parent u to its child v:
                //
                // 1) All nodes inside v's subtree become 1 step closer.
                //      → total distance decreases by C(v)
                //
                // 2) All other nodes (N - C(v)) become 1 step farther.
                //      → total distance increases by (N - C(v))
                //
                // Therefore:
                //
                //      S(v) = S(u) - C(v) + (N - C(v))
                //
                // This allows computing all S(*) values in O(N) using a second
                // DFS.

                ans[nxt] = ans[node] - count[nxt] + (n - count[nxt]);

                dfs2(nxt, node);
            }
        };

        dfs2(0, -1);

        return ans;
    }
};

class Solution_TLE {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {

        vector<vector<bool>> graph(n, vector<bool>(n, false));

        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         graph[i][j] = -1;
        //     }
        // }

        for (auto edge : edges) {
            graph[edge[0]][edge[1]] = true;
            graph[edge[1]][edge[0]] = true;
        }

        using P = pair<int, int>;

        auto find_S = [&](const int I) {
            queue<P> q;
            q.push(P(I, 0));

            vector<int> d(n, -1);

            // for (int i = 0; i < n; i++)
            //     d[i] = -1;

            d[I] = 0;

            while (!q.empty()) {
                auto [node, dist] = q.front();
                q.pop();

                for (int i = 0; i < n; i++) {
                    if (graph[node][i] != false) {
                        if (d[i] == -1) {
                            d[i] = dist + 1;
                            q.push(P(i, d[i]));
                        }
                    }
                }
            }

            int sum = 0;
            for (int i = 0; i < n; i++)
                sum += d[i];

            return sum;
        };

        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++)
            ans[i] = find_S(i);

        return ans;
    }
};