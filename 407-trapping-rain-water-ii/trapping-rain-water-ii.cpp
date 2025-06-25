// class Solution {
// public:
//     int trapRainWater(vector<vector<int>>& heightMap) {
//         int r = heightMap.size(), c = heightMap[0].size();

//         vector<vector<int>> maxi1(r, vector<int>(c, 0)),
//             maxi2(r, vector<int>(c, 0)), maxi3(r, vector<int>(c, 0)),
//             maxi4(r, vector<int>(c, 0));

//         for (int i = 0; i < r; i++) {
//             for (int j = 0; j < c; j++) {
//                 maxi1[i][j] = max((i ? maxi1[i - 1][j] : 0),
//                 heightMap[i][j]); maxi2[r - i - 1][j] =
//                     max((i ? maxi2[r - i][j] : 0), heightMap[r - i - 1][j]);

//                 maxi3[i][j] = max((j ? maxi3[i][j - 1] : 0),
//                 heightMap[i][j]); maxi4[i][c - j - 1] =
//                     max((j ? maxi4[i][c - j] : 0), heightMap[i][c - j - 1]);
//             }
//         }

//         int ans = 0;

//         for (int i = 1; i < r - 1; i++) {
//             for (int j = 1; j < c - 1; j++) {
//                 ans += min(min(maxi1[i][j], maxi2[i][j]),
//                            min(maxi3[i][j], maxi4[i][j])) -
//                        heightMap[i][j];
//             }
//         }
//         return ans;
//     }
// };

// // 190ms
// class Solution {
// public:
//     int trapRainWater(vector<vector<int>>& heightMap) {
//         int m = heightMap.size(), n = heightMap[0].size();

//         priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
//         vector<vector<bool>> visited(m, vector<bool>(n, false));

//         for (int i = 0; i < m; i++) {
//             pq.push({heightMap[i][0], i, 0});
//             visited[i][0] = true;

//             pq.push({heightMap[i][n - 1], i, n - 1});
//             visited[i][n - 1] = true;
//         }

//         for (int j = 1; j < n; j++) {
//             pq.push({heightMap[0][j], 0, j});
//             visited[0][j] = true;

//             pq.push({heightMap[m - 1][j], m - 1, j});
//             visited[m - 1][j] = true;
//         }

//         vector<vector<int>> dx = {{1, 0}, {-1, 0}, {0, 1}, {0 ,- 1}};

//         int water = 0;

//         while (!pq.empty()) {
//             vector<int> cell = pq.top();
//             pq.pop();

//             int height = cell[0], i = cell[1], j = cell[2];

//             for (vector d : dx) {
//                 int ii = i + d[0], jj = j + d[1];

//                 if (0 <= ii && ii < m && 0 <= jj && jj < n &&
//                     !visited[ii][jj]) {
//                     visited[ii][jj] = true;

//                     water += max(0, height - heightMap[ii][jj]);
//                     pq.push({max(height, heightMap[ii][jj]), ii, jj});
//                 }
//             }
//         }
//         return water;
//     }
// };

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size();

        struct T {
            int height, row, col;
            bool operator>(const T& other) const {
                return height > other.height;
            }
        };

        priority_queue<T, vector<T>, greater<>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            pq.emplace(heightMap[i][0], i, 0);
            visited[i][0] = true;

            pq.emplace(heightMap[i][n - 1], i, n - 1);
            visited[i][n - 1] = true;
        }

        for (int j = 1; j < n; j++) {
            pq.emplace(heightMap[0][j], 0, j);
            visited[0][j] = true;

            pq.emplace(heightMap[m - 1][j], m - 1, j);
            visited[m - 1][j] = true;
        }

        int dx[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        int water = 0;

        while (!pq.empty()) {

            auto [height, i, j] = pq.top();
            pq.pop();

            for (int k = 0; k < 4; ++k) {
                int ii = i + dx[k][0], jj = j + dx[k][1];

                if (0 <= ii && ii < m && 0 <= jj && jj < n &&
                    !visited[ii][jj]) {
                    visited[ii][jj] = true;

                    water += max(0, height - heightMap[ii][jj]);
                    pq.emplace(max(height, heightMap[ii][jj]), ii, jj);
                }
            }
        }
        return water;
    }
};
