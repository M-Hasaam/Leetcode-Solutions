class Solution {
    vector<int> topologySort(int k, vector<vector<int>>& Conditions) {
        vector<vector<int>> adj(k + 1);
        for (int i = 1; i <= k; i++)
            adj[i].reserve(10);

        vector<int> indeg(k + 1, 0);

        for (auto& C : Conditions) {
            adj[C[0]].push_back(C[1]);
            indeg[C[1]]++;
        }

        queue<int> q;

        for (int i = 1; i <= k; i++)
            if (indeg[i] == 0)
                q.push(i);

        vector<int> order;
        order.reserve(k);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            order.push_back(curr);

            for (int nxt : adj[curr]) {
                indeg[nxt]--;

                if (indeg[nxt] == 0)
                    q.push(nxt);
            }
        }

        return order;
    }

public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions,
                                    vector<vector<int>>& colConditions) {
        vector<int> R = topologySort(k, rowConditions);
        vector<int> C = topologySort(k, colConditions);

        if (R.size() != k || C.size() != k)
            return {};

        vector<int> Rm(k + 1, 0), Cm(k + 1, 0);

        for (int i = 0; i < k; i++) {
            Rm[R[i]] = i;
            Cm[C[i]] = i;
        }

        vector<vector<int>> matrix(k, vector<int>(k, 0));

        for (int num = 1; num <= k; num++)
            matrix[Rm[num]][Cm[num]] = num;

        return matrix;
    }
};