class Solution {

    class DSU {
        vector<int> parent, size;
        vector<int> P_parent, P_size;

    public:
        DSU(int n) : parent(n), size(n, 1) {
            iota(parent.begin(), parent.end(), 0);
        }

        int find(int x) {
            while (parent[x] != x)
                x = parent[x];
            return x;
        }

        bool unite(int a, int b) {
            P_parent = parent;
            P_size = size;

            a = find(a);
            b = find(b);

            if (a == b)
                return false;

            if (size[a] < size[b])
                swap(a, b);

            parent[b] = a;
            size[a] += size[b];

            return true;
        }

        void undo() {
            parent = P_parent;
            size = P_size;
        }

        bool isUnite(int a, int b) { return find(a) == find(b); }
    };

public:
   vector<bool> friendRequests(int n, vector<vector<int>>& restrictions,
                            vector<vector<int>>& requests) {
    vector<bool> ans;
    ans.reserve(requests.size());
    DSU Set(n);

    for (const auto& r : requests) {
        int a = r[0], b = r[1];

        // already friends → accept
        if (Set.isUnite(a, b)) {
            ans.push_back(true);
            continue;
        }

        Set.unite(a, b);

        bool ok = true;
        for (const auto& rs : restrictions) {
            if (Set.isUnite(rs[0], rs[1])) {
                Set.undo();
                ans.push_back(false);
                ok = false;
                break;
            }
        }

        if (ok)
            ans.push_back(true);
    }

    return ans;
}

};