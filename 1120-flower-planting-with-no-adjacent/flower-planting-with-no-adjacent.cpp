class Solution {
    void encode_color(uint8_t& used, const int& color) {
        used |= 1 << (color - 1);
    }
    bool color_exist(const uint8_t& used, const int& color) {
        return used & (1 << (color - 1));
    }

public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {

        const int N = 10000; // 1 <= n <= 10000
        const int M = 3;     // All gardens have at most 3 paths

        int graph[N][M];
        uint8_t deg[N];

        for (int i = 0; i < n; i++) {
            deg[i] = 0;
            graph[i][0] = graph[i][1] = graph[i][2] = -1;
        }

        for (vector<int> p : paths) {
            int u = p[0] - 1, v = p[1] - 1;

            graph[u][deg[u]++] = v;
            graph[v][deg[v]++] = u;
        }

        vector<int> color(n, 0);

        for (int i = 0; i < n; i++) {

            // int used[4] = {false};

            uint8_t used = 0;
            for (int j = 0; j < deg[i]; j++) {
                int nb = graph[i][j];

                if (color[nb] != 0) {
                    encode_color(used, color[nb]);
                }
            }

            for (int k = 1; k <= 4; k++) {
                if (!color_exist(used, k)) {
                    color[i] = k;
                    break;
                }
            }
        }

        return color;
    }
};

class Solution_Vector_51ms {
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

class Solution_BFS_100ms {
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