class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges,
                                         vector<vector<int>>& blueEdges) {

        const int BLUE = 0;
        const int RED = 1;

        // graph[color][node] = array of connected nodes
        vector<vector<vector<int>>> graph(2, vector<vector<int>>(n));

        for (auto& e : blueEdges) {
            int u = e[0], v = e[1];
            graph[BLUE][u].push_back(v);
        }
        for (auto& e : redEdges) {
            int u = e[0], v = e[1];
            graph[RED][u].push_back(v);
        }

        // dist[node][color] = min distance
        vector<vector<int>> dist(n, vector<int>(2, INT_MAX));

        dist[0][BLUE] = dist[0][RED] = 0;

        // <node,color>
        queue<pair<int, int>> q;

        q.push({0, BLUE});
        q.push({0, RED});

        while (!q.empty()) {
            auto [curr_node, curr_color] = q.front();
            q.pop();

            int nxt_color = !curr_color;
            for (auto nxt_node : graph[nxt_color][curr_node]) {
                if (dist[nxt_node][nxt_color] == INT_MAX) {
                    dist[nxt_node][nxt_color] = dist[curr_node][curr_color] + 1;

                    q.push({nxt_node, nxt_color});
                }
            }
        }

        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            ans[i] = min(dist[i][BLUE], dist[i][RED]);
            if (ans[i] == INT_MAX)
                ans[i] = -1;
        }

        return ans;
    }
};