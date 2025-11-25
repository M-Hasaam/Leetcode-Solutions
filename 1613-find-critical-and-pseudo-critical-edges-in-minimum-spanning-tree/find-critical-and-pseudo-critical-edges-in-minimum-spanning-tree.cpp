class Solution {
    struct DSU {
        vector<int> parent, rank;

        DSU(int n) : parent(n), rank(n, 0) {
            iota(parent.begin(), parent.end(), 0);
        }

        int find(int x) {
            return parent[x] == x ? x : parent[x] = find(parent[x]);
        }

        bool unite(int a, int b) {
            a = find(a);
            b = find(b);

            if (a == b)
                return false;

            if (rank[a] < rank[b])
                swap(a, b);

            parent[b] = a;

            if (rank[a] == rank[b])
                rank[a]++;

            return true;
        }
    };

    int kruskal(int n, vector<vector<int>>& edges, int skip, int force) {
        DSU dsu(n);
        int cost = 0, used = 0;

        if (force != -1) {
            auto& e = edges[force];
            dsu.unite(e[0], e[1]);
            cost += e[2];
            used++;
        }

        for (int i = 0; i < edges.size(); i++) {
            if (i == skip)
                continue;

            auto& e = edges[i];

            if (dsu.unite(e[0], e[1])) {
                cost += e[2];
                used++;
            }
        }

        return used == n - 1 ? cost : INT_MAX;
    }

public:
    vector<vector<int>>
    findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {

        int m = edges.size();

        for (int i = 0; i < m; i++)
            edges[i].push_back(i);

        sort(edges.begin(), edges.end(),
             [](auto& a, auto& b) { return a[2] < b[2]; });

        int mst = kruskal(n, edges, -1, -1);

        vector<int> critical, pseudo;

        for (int i = 0; i < m; i++) {

            if (kruskal(n, edges, i, -1) > mst)
                critical.push_back(edges[i][3]);

            else if (kruskal(n, edges, -1, i) == mst)
                pseudo.push_back(edges[i][3]);
        }

        return {critical, pseudo};
    }
};
