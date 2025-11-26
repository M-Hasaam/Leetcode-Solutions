class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        vector<vector<int>> graph(n);

        for (auto e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        queue<int> q;
        vector<bool> visited(n, false);

        q.push(source);
        visited[source] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            if (curr == destination)
                return true;

            for (int nxt : graph[curr]) {
                if (!visited[nxt]) {
                    visited[nxt] = true;
                    q.push(nxt);
                }
            }
        }

        return false;
    }
};