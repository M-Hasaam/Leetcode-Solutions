class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        deque<pair<int,int>> dq;
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        dq.push_front({0, 0});
        dist[0][0] = 0;

        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!dq.empty()) {
            auto [i, j] = dq.front();
            dq.pop_front();

            for (auto& d : dirs) {
                int ni = i + d[0], nj = j + d[1];
                if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;

                int w = grid[ni][nj];
                if (dist[i][j] + w < dist[ni][nj]) {
                    dist[ni][nj] = dist[i][j] + w;
                    if (w == 0)
                        dq.push_front({ni, nj});
                    else
                        dq.push_back({ni, nj});
                }
            }
        }
        return dist[m-1][n-1];
    }
};

class Solution_Dijkstra {
    struct Node {
        int d, i, j, pi, pj;

        Node(int a, int b, int c, int d, int e)
            : d(a), i(b), j(c), pi(d), pj(e) {}

        bool operator>(const Node& O) const { return d > O.d; }
        bool operator<(const Node& O) const { return d < O.d; }
    };

public:
    int minimumObstacles(vector<vector<int>>& grid) {
        // using T = pair<int, int>;
        int m = grid.size(), n = grid[0].size();

        priority_queue<Node, vector<Node>, greater<Node>> pq;
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        pq.push({0, 0, 0, -1, -1});
        dist[0][0] = 0;

        vector<vector<int>> D = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!pq.empty()) {
            Node curr = pq.top();
            pq.pop();

            if (dist[curr.i][curr.j] < curr.d)
                continue;

            for (const auto& d : D) {
                int ni = d[0] + curr.i, nj = d[1] + curr.j;

                if ((ni < 0 || ni >= m || nj < 0 || nj >= n) ||
                    (ni == curr.pi && nj == curr.pj))
                    continue;

                int nxt_d = curr.d + grid[ni][nj];
                if (nxt_d < dist[ni][nj]) {
                    dist[ni][nj] = nxt_d;
                    pq.push({nxt_d, ni, nj, curr.i, curr.j});
                }
            }
        }

        return dist[m - 1][n - 1];
    }
};