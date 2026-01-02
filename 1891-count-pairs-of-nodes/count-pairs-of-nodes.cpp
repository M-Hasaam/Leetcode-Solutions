class Solution {
    long long find_key(int u, int v) { return (long long)u << 32 | v; }
    pair<int, int> get_u_v(long long key) {
        return {key >> 32, key & ((1LL << 32) - 1)};
    }

public:
    vector<int> countPairs(int n, vector<vector<int>>& edges,
                           vector<int>& queries) {
        vector<int> deg(n + 1, 0);
        unordered_map<long long, int> Com;

        for (const auto& e : edges) {
            int u = e[0], v = e[1];
            if (u > v)
                swap(u, v);
            Com[find_key(u, v)]++;
            deg[u]++;
            deg[v]++;
        }

        int m = queries.size();
        vector<int> ans;
        ans.reserve(m);

        vector<int> sDeg(n);
        for (int i = 1; i <= n; i++)
            sDeg[i - 1] = deg[i];
        sort(sDeg.begin(), sDeg.end());

        for (const int& q : queries) {
            int l = 0, r = n - 1;
            int total = 0;

            while (l < r) {
                if (sDeg[l] + sDeg[r] <= q) {
                    l++;
                } else {
                    total += r - l;
                    r--;
                }
            }

            for (auto& [key, c] : Com) {
                auto [u, v] = get_u_v(key);
                if (deg[u] + deg[v] > q)
                    if (deg[u] + deg[v] - c <= q) {
                        total--;
                    }
            }

            ans.push_back(total);
        }

        return ans;
    }
};