class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> graph(n);
        vector<int> indeg(n, 0);

        for (const auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            indeg[e[1]]++;
        }

        vector<vector<int>> dp(n, vector<int>(26, 0));

        queue<int> q;

        int MAX = -1;

        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) {
                q.push(i);
                dp[i][colors[i] - 'a'] = 1;
            }
        }

        int count = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            count++;

            for (int c = 0; c < 26; c++)
                MAX = max(MAX, dp[u][c]);

            for (int v : graph[u]) {

                for (int c = 0; c < 26; c++)
                    dp[v][c] = max(dp[v][c], dp[u][c] + (c == colors[v] - 'a'));

                // dp[v][colors[v] - 'a']++;

                if (--indeg[v] == 0) {
                    q.push(v);
                }
            }
        }

        return count == n ? MAX : -1;
    }
};
class Solution_TLE {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> graph(n);
        vector<int> indeg(n, 0);

        for (const auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            indeg[e[1]]++;
        }

        int arr[26] = {0};
        vector<int> visited(n, 0);

        int MAX = -1;
        function<bool(int)> dfs = [&](int curr) {
            MAX = max(++arr[colors[curr] - 'a'], MAX);

            if (visited[curr] == 1)
                return false;

            visited[curr] = 1;

            for (int nxt : graph[curr]) {
                if (!dfs(nxt))
                    return false;
            }

            visited[curr] = 2;

            --arr[colors[curr] - 'a'];

            return true;
        };

        for (int i = 0; i < n; i++)
            if (indeg[i] == 0)
                if (!dfs(i))
                    return -1;

        return MAX;
    }
};