#include <queue>
#include <vector>
using namespace std;

class Solution {
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
