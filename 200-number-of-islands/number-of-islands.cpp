class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        int X = grid.size(), Y = grid[0].size();

        int count = 0;

        for (int i = 0; i < X; i++) {
            for (int j = 0; j < Y; j++) {
                if (grid[i][j] == '1') {
                    count++;

                    {
                        queue<pair<int, int>> q;
                        q.emplace(i, j);
                        grid[i][j] = 'X';

                        int dx[] = {1, -1, 0, 0};
                        int dy[] = {0, 0, 1, -1};

                        while (!q.empty()) {

                            auto [fi, fj] = q.front();
                            q.pop();

                            for (int k = 0; k < 4; k++) {
                                int ni = fi + dx[k];
                                int nj = fj + dy[k];

                                if (0 <= ni && ni < X && 0 <= nj && nj < Y &&
                                    grid[ni][nj] == '1') {

                                    q.emplace(ni, nj);
                                    grid[ni][nj] = 'X';
                                }
                            }
                        }
                    }
                }
            }
        }

        return count;
    }
};