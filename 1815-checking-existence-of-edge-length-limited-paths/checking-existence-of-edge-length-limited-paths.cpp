class Solution {
public:
    struct DSU {
        vector<int> parent;
        DSU(int size) {
            parent = vector<int>(size, 0);
            iota(parent.begin(), parent.end(), 0);
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
            if (a < b)
                swap(a, b);

            parent[b] = a;
            // size[a] += size[b];

            return true;
        }
    };

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList,
                                           vector<vector<int>>& queries) {

        sort(edgeList.begin(), edgeList.end(),
             [&](const auto& a, const auto& b) { return a[2] < b[2]; });

        DSU D(n);

        int qs=queries.size();

        vector<vector<int>> queries_i(qs);
        {
            int i = 0;
            for (const auto& q : queries) {
                queries_i[i] = {i, q[0], q[1], q[2]};
                i++;
            }
        }

        sort(queries_i.begin(), queries_i.end(),
             [&](const auto& a, const auto& b) { return a[3] < b[3]; });

        int m = queries.size();
        vector<bool> ans(m);

        int I = 0;
        for (const auto& q : queries_i) {
            int i = q[0];
            int l = q[3];

            while (I < edgeList.size() && edgeList[I][2] < l) {
                D.unite(edgeList[I][0], edgeList[I][1]);
                I++;
            }

            ans[i] = D.find(q[1]) == D.find(q[2]);
        }

        return ans;
    }
};
class Solution_ {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList,
                                           vector<vector<int>>& queries) {
        vector<vector<pair<int, int>>> graph(n);
        vector<bool> ans;
        ans.reserve(n);

        for (auto& e : edgeList) {
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }

        for (auto& que : queries) {
            int u = que[0], v = que[1], l = que[2];

            queue<int> q;
            vector<bool> vis(n, false);

            q.push(u);
            vis[u] = true;

            bool found = false;

            while (!q.empty()) {
                int curr = q.front();
                q.pop();

                for (auto& [nxt, d] : graph[curr]) {
                    if (d >= l || vis[nxt])
                        continue;
                    if (nxt == v) {
                        found = true;
                        break;
                    }
                    vis[nxt] = true;
                    q.push(nxt);
                }
                if (found)
                    break;
            }

            ans.push_back(found);
        }

        return ans;
    }
};