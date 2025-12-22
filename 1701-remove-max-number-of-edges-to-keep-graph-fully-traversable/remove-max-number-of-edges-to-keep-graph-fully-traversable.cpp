class Solution {
    class DSU {
    public:
        vector<int> parent, size;
        int components;

        DSU(int n) : parent(n + 1), size(n + 1, 1), components(n) {
            iota(parent.begin(), parent.end(), 0);
        }

        int find(int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        }

        bool unite(int a, int b) {
            a = find(a);
            b = find(b);

            if (a == b)
                return false;

            if (b > a)
                swap(a, b);

            parent[b] = a;
            components--;
            size[a] += size[b];

            return true;
        }
    };

public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {

        DSU A(n), B(n);
        int used = 0;

        for (auto e : edges) {
            if (e[0] == 3) {
                int u = e[1], v = e[2];
                if (A.unite(u, v) && B.unite(u, v))
                    used++;
            }
        }
        for (auto e : edges) {
            if (e[0] != 3) {
                int u = e[1], v = e[2];

                if (e[0] == 1 && A.unite(u, v))
                    used++;
                if (e[0] == 2 && B.unite(u, v))
                    used++;
            }
        }

        if (A.components != 1 || B.components != 1)
            return -1;

        return edges.size() - used;
    }
};

class Solution_342ms {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {

        vector<vector<int>> size(2, vector<int>(n, 1));
        vector<vector<int>> parent(2, vector<int>(n));

        for (int i = 0; i < 2; i++)
            iota(parent[i].begin(), parent[i].end(), 1);

        function<int(int, int)> find = [&](int x, int type) {
            if (parent[type][x - 1] != x)
                parent[type][x - 1] = find(parent[type][x - 1], type);
            return parent[type][x - 1];
        };

        auto unite = [&](int a, int b, int type) {
            int pa = find(a, type), pb = find(b, type);

            if (pa == pb)
                return false;

            if (pa < pb)
                swap(pa, pb);

            parent[type][pb - 1] = pa;
            size[type][pa - 1] += size[type][pb - 1];

            return true;
        };

        auto united = [&](int a, int b, int type) {
            if (find(a, type) == find(b, type))
                return false;
            return true;
        };

        int count = 0;
        for (auto e : edges) {
            if (e[0] == 3) {
                int u = e[1], v = e[2];

                if (!united(u, v, 0) || !united(u, v, 1))
                    count++;
                else {
                    unite(u, v, 0);
                    unite(u, v, 1);
                }
            }
        }

        for (auto e : edges) {
            if (e[0] != 3) {
                int u = e[1], v = e[2];

                if (!unite(u, v, e[0] - 1))
                    count++;
            }
        }

        int A = find(1, 0), B = find(1, 1);
        for (int i = 2; i <= n; i++) {
            if (A != find(i, 0) || B != find(i, 1))
                return -1;
        }

        return count;
    }
};