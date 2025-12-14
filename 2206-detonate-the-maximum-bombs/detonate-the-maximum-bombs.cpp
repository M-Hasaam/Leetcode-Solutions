class Solution {
    bool canDetonate(const vector<int>& a, const vector<int>& b) {
        long long dx = (long long)a[0] - b[0];
        long long dy = (long long)a[1] - b[1];
        long long r = (long long)a[2];
        return dx * dx + dy * dy <= r * r;
    }

public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> graph(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && canDetonate(bombs[i], bombs[j])) {
                    graph[i].push_back(j);
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            vector<bool> visited(n, false);
            stack<int> st;
            st.push(i);
            visited[i] = true;

            int cnt = 0;
            while (!st.empty()) {
                int cur = st.top();
                st.pop();
                cnt++;

                for (int nxt : graph[cur]) {
                    if (!visited[nxt]) {
                        visited[nxt] = true;
                        st.push(nxt);
                    }
                }
            }

            ans = max(ans, cnt);
        }

        return ans;
    }
};

class Solution_DFS {
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