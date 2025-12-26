class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> Po(m, vector<bool>(n, false));
        vector<vector<bool>> Ao(m, vector<bool>(n, false));

        int dist[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        auto bfs = [&](queue<pair<int, int>>& q, vector<vector<bool>>& ocean) {
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int dx = dist[i][0], dy = dist[i][1];
                    int nx = x + dx, ny = y + dy;

                    if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                        continue;
                    else if (ocean[nx][ny])
                        continue;
                    else if (heights[nx][ny] < heights[x][y])
                        continue;

                    ocean[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        };

        queue<pair<int, int>> qA, qP;

        for (int i = 0; i < m; i++) {
            Po[i][0] = true;
            qP.push({i, 0});
            Ao[i][n - 1] = true;
            qA.push({i, n - 1});
        }
        for (int j = 0; j < n ; j++) {
            Po[0][j] = true;
            qP.push({0, j});
            Ao[m - 1][j] = true;
            qA.push({m - 1, j});
        }

        bfs(qP, Po);
        bfs(qA, Ao);

        vector<vector<int>> ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // cout << " [" << Po[i][j] << "][" << Ao[i][j] << "]";
                if (Po[i][j] && Ao[i][j]) {
                    ans.push_back({i, j});
                }
            }
            cout << endl;
        }

        return ans;
    }
};

//==============================================================

class Solution_direct_BFS2 {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> visited_A(m, vector<bool>(n, false));
        vector<vector<bool>> visited_P(m, vector<bool>(n, false));

        auto bfs = [&](int I, int J) {
            queue<pair<int, int>> q;
            vector<vector<bool>> visited(m, vector<bool>(n, false));

            q.push({I, J});
            visited[I][J] = true;

            bool P = false, A = false;

            int dd[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int dx = dd[k][0], dy = dd[k][1];

                    int nx = x + dx, ny = y + dy;

                    if (nx < 0 || ny < 0) {
                        P = true;
                        if (A && P)
                            return true;
                    } else if (nx >= m || ny >= n) {
                        A = true;
                        if (A && P)
                            return true;
                    } else {

                        if (!visited[nx][ny] &&
                            heights[nx][ny] <= heights[x][y]) {
                            bool V_A = visited_A[nx][ny],
                                 V_P = visited_P[nx][ny];

                            if (V_A && V_P) {
                                return true;
                            } else if (V_A) {
                                A = true;
                                if (A && P)
                                    return true;
                            } else if (V_P) {
                                P = true;
                                if (A && P)
                                    return true;
                            }
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
            }

            visited_A[I][J] = A;
            visited_P[I][J] = P;
            return false;
        };

        vector<vector<int>> ans;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (bfs(i, j)) {
                    ans.push_back({i, j});
                    visited_A[i][j] = true;
                    visited_P[i][j] = true;
                }
            }
        }

        return ans;
    }
};

class Solution_direct_BFS {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();

        auto bfs = [&](int I, int J) {
            queue<pair<int, int>> q;
            vector<vector<bool>> visited(m, vector<bool>(n, false));

            q.push({I, J});
            visited[I][J] = true;

            bool P = false, A = false;

            int dd[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int dx = dd[k][0], dy = dd[k][1];

                    int nx = x + dx, ny = y + dy;

                    if (nx < 0 || ny < 0) {
                        P = true;
                        if (A && P)
                            return true;
                    } else if (nx >= m || ny >= n) {
                        A = true;
                        if (A && P)
                            return true;
                    } else {
                        if (!visited[nx][ny] &&
                            heights[nx][ny] <= heights[x][y]) {
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
            }
            return false;
        };

        vector<vector<int>> ans;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (bfs(i, j)) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};

class Solution_Old {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        auto bfs = [&](queue<pair<int, int>>& q, vector<vector<bool>>& ocean) {
            while (!q.empty()) {
                auto [i, j] = q.front();
                q.pop();
                for (auto [di, dj] : dirs) {
                    int ni = i + di, nj = j + dj;
                    if (ni < 0 || nj < 0 || ni >= m || nj >= n)
                        continue;
                    if (ocean[ni][nj])
                        continue;
                    if (heights[ni][nj] < heights[i][j])
                        continue;
                    ocean[ni][nj] = true;
                    q.push({ni, nj});
                }
            }
        };

        queue<pair<int, int>> qP, qA;
        for (int i = 0; i < m; i++) {
            pacific[i][0] = true;
            qP.push({i, 0});
            atlantic[i][n - 1] = true;
            qA.push({i, n - 1});
        }
        for (int j = 0; j < n; j++) {
            pacific[0][j] = true;
            qP.push({0, j});
            atlantic[m - 1][j] = true;
            qA.push({m - 1, j});
        }

        bfs(qP, pacific);
        bfs(qA, atlantic);

        vector<vector<int>> res;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};
