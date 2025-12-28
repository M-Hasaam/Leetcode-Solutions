class Solution {

public:
    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>>& connections) {

        vector<vector<int>> graph(n);

        for (const auto& e : connections) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<int> disc(n, -1), low(n, -1), parent(n, -1);
        vector<bool> visited(n, false);
        int timer = 0;

        vector<vector<int>> ans;
        function<void(int, int)> dfs = [&](int index, int parent) {
            disc[index] = low[index] = timer++;
            visited[index] = true;

            for (auto nbr : graph[index]) {
                if (parent == nbr)
                    continue;

                if (!visited[nbr]) {
                    dfs(nbr, index);
                    low[index] = min(low[index], low[nbr]);

                    if (low[nbr] > disc[index]) {
                        ans.push_back({index, nbr});
                    }
                } else {
                    low[index] = min(low[index], disc[nbr]);
                }
            }
        };

        dfs(0, -1);

        return ans;
    }
};
class Solution_Union_Method_TLE {
    struct DSU {
        vector<int> parent;
        vector<int> size;
        int count = 0;

        DSU(int s) {
            parent = vector<int>(s);
            iota(parent.begin(), parent.end(), 0);
            size = vector<int>(s, 1);
        }

        int find(int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        }

        bool unite(int a, int b) {
            a = find(a), b = find(b);

            if (a == b)
                return false;

            if (b > a)
                swap(a, b);

            parent[b] = a;
            size[a] += size[b];
            count++;
            return true;
        }
    };

public:
    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>>& connections) {

        int m = connections.size();
        vector<vector<int>> ans;
        for (int i = 0; i < m; i++) {
            DSU dsu(n);
            for (int j = 0; j < m; j++) {
                if (j == i)
                    continue;
                dsu.unite(connections[j][0], connections[j][1]);
            }
            if (dsu.count != n - 1)
                ans.push_back(connections[i]);
        }

        return ans;
    }
};