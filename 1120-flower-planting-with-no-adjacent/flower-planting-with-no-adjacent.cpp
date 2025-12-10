class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {

        vector<vector<int>> graph(n + 1);

        for (auto p : paths) {
            graph[p[0]].push_back(p[1]);
            graph[p[1]].push_back(p[0]);
        }

        vector<int> color(n, 0);

        for (int i = 0; i < n; i++) {

            bool used[4] = {false};

            for (int v : graph[i + 1]) {
                if (color[v - 1] != 0)
                    used[color[v - 1] - 1] = true;
            }

            for (int j = 0; j < 4; j++) {
                if (!used[j]) {
                    color[i] = j + 1;
                    break;
                }
            }
        }

        return color;
    }
};

class Solution_BFS {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {

        vector<vector<int>> graph(n + 1);

        for (auto p : paths) {
            graph[p[0]].push_back(p[1]);
            graph[p[1]].push_back(p[0]);
        }

        vector<int> visited(n, 0);

        for (int i = 1; i <= n; i++) {
            if (visited[i - 1] == 0) {
                visited[i - 1] = 1;

                queue<int> q;
                q.push(i);

                while (!q.empty()) {
                    int curr = q.front();
                    q.pop();

                    // if (visited[i - 1])
                    //     continue;

                    bool n4[4] = {false};

                    for (int v : graph[curr]) {
                        if (visited[v - 1] != 0) {
                            n4[visited[v - 1] - 1] = true;
                        } else {
                            q.push(v);
                        }
                    }

                    for (int j = 0; j < 4; j++) {
                        if (!n4[j]) {
                            visited[curr - 1] = j + 1;
                            break;
                        }
                    }
                }
            }
        }

        return visited;
    }
};