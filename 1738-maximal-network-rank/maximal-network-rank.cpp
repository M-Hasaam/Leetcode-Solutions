class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);
        vector<vector<bool>> connected(n, vector<bool>(n, false));

        for (auto road : roads) {
            int u = road[0], v = road[1];

            connected[u][v] = connected[v][u] = true;
            degree[u]++;
            degree[v]++;
        }

        int rank = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int count = degree[i] + degree[j];
                if (connected[i][j])
                    count--;
                rank = max(count, rank);
            }
        }

        return rank;
    }
};