class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);
        vector<int> ideg(n, 0);

        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            ideg[e[1]]++;
        }

        vector<set<int>> ancester(n);

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (ideg[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int nxt : adj[curr]) {
                ancester[nxt].insert(curr);
                ancester[nxt].insert(ancester[curr].begin(),
                                     ancester[curr].end());
                if (--ideg[nxt] == 0) {
                    q.push(nxt);
                }
            }
        }

        vector<vector<int>> ans(n);

        for (int i = 0; i < n; i++) {
            ans[i] = vector<int>(ancester[i].begin(), ancester[i].end());
        }

        return ans;
    }
};