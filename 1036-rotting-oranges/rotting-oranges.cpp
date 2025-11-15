class Solution {
    using P = pair<int, int>;

    bool inRange(int i, int j, int n, int m) {
        if (0 <= i && 0 <= j && i < n && j < m)
            return true;

        return false;
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<P> q;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    visited[i][j] = true;
                }

        int dx[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        int level = 0;

        while (!q.empty()) {
            int size = q.size();

            while (0 < size) {
                size--;

                auto [i, j] = q.front();
                q.pop();

                for (int k = 0; k < 4; k++) {

                    int ni = i + dx[k][0], nj = j + dx[k][1];
                    if (inRange(ni, nj, n, m))
                        if (!visited[ni][nj])
                            if (grid[ni][nj] == 1) {
                                visited[ni][nj] = true;
                                grid[ni][nj] = 2;
                                q.push({ni, nj});
                            }
                }
            }

            if (!q.empty())
                level++;
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 1)
                    return -1;

        return level;
    }
};