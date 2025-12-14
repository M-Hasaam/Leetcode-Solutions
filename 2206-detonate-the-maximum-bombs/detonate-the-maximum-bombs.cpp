class Solution {
    bool isPointInCircle(int Px, int Py, int X, int Y,
                         long long unsigned int R) {
        long long unsigned int dx = Px - X;
        long long unsigned int dy = Py - Y;
        return (dx * dx + dy * dy) <= (R * R);
    }

    bool isIn(vector<int> Point, vector<int> Circle) {
        return isPointInCircle(Point[0], Point[1], Circle[0], Circle[1],
                               Circle[2]);
    }

public:
    int maximumDetonation(vector<vector<int>>& bombs) {

        int n = bombs.size();

        vector<vector<int>> graph(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && isIn(bombs[j], bombs[i]))
                    graph[i].push_back(j);
            }
        }

        vector<bool> visited(n, false);

        function<int(int)> dfs = [&](int curr) {
            int count = 1;

            visited[curr] = true;
            for (int nxt : graph[curr]) {
                if (!visited[nxt])
                    count += dfs(nxt);
            }

            return count;
        };

        int M = 0;

        for (int i = 0; i < n; i++) {
            M = max(M, dfs(i));
            for (int j = 0; j < n; j++)
                visited[j] = false;
        }

        return M;
    }
};

class Solution_For {
    bool isPointInCircle(int Px, int Py, int X, int Y,
                         long long unsigned int R) {
        long long unsigned int dx = Px - X;
        long long unsigned int dy = Py - Y;
        return (dx * dx + dy * dy) <= (R * R);
    }

    bool isIn(vector<int> Point, vector<int> Circle) {
        return isPointInCircle(Point[0], Point[1], Circle[0], Circle[1],
                               Circle[2]);
    }

public:
    int maximumDetonation(vector<vector<int>>& bombs) {

        int n = bombs.size();

        auto detonate = [&](int I) {
            queue<int> q;
            vector<bool> visited(n, false);
            q.push(I);
            visited[I] = true;

            int count = 0;
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                count++;

                for (int i = 0; i < n; i++) {
                    if (!visited[i])
                        if (isIn(bombs[i], bombs[curr])) {
                            visited[i] = true;
                            q.push(i);
                        }
                }
            }

            return count;
        };

        int M = 0;
        for (int i = 0; i < n; i++)
            M = max(M, detonate(i));

        return M;
    }
};