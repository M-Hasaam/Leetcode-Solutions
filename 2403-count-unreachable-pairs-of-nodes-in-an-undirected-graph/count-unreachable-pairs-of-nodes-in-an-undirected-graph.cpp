class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);
        long long ans = 0;
        long long remaining = n;

        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;

            // BFS to find component size
            queue<int> q;
            q.push(i);
            visited[i] = true;
            long long size = 1;

            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : graph[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                        size++;
                    }
                }
            }

            remaining -= size;
            ans += size * remaining;
        }

        return ans;
    }
};


class Solution_ {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {

        vector<vector<int>> graph(n);

        for (const auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            queue<int> q;
            vector<bool> visited(n, false);

            q.push(i);
            visited[i] = true;
            int count = n - 1 - i;

            while (!q.empty()) {
                int curr = q.front();
                q.pop();

                for (int nxt : graph[curr]) {
                    if (!visited[nxt]) {
                        visited[nxt] = true;
                        q.push(nxt);

                        if (nxt > i) {
                            count--;
                        }
                    }
                }
            }

            ans += count;
        }

        return ans;
    }
};