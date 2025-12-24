class Solution {

public:
    int minCost(vector<vector<int>>& grid) {

        int m = grid.size(), n = grid[0].size();

        auto exist = [&](int i, int j, int val) {
            if (i < 0 || i >= m || j < 0 || j >= n)
                return false;

            switch (val) {
            case 1:
                return j + 1 < n;
            case 2:
                return j - 1 >= 0;
            case 3:
                return i + 1 < m;
            case 4:
                return i - 1 >= 0;
            }

            return false;
        };

        function<pair<int, int>(int, int, int)> new_ij = [&](int i, int j,
                                                             int val) {
            using P = pair<int, int>;

            if (i < 0 || i >= m || j < 0 || j >= n)
                return P{0, 0};

            switch (val) {
            case 1:
                return P{i, j + 1};
            case 2:
                return P{i, j - 1};
            case 3:
                return P{i + 1, j};
            case 4:
                return P{i - 1, j};
            }

            return P{0, 0};
        };

        using T = tuple<int, int, int>; // w,i,j
        priority_queue<T, vector<T>, greater<>> pq;
        vector<vector<int>> visited(m, vector<int>(n, INT_MAX));

        pq.push({0, 0, 0});
        visited[0][0] = 0;

        while (!pq.empty()) {
            const auto [W, I, J] = pq.top();
            pq.pop();

            if (W > visited[I][J])
                continue;

            int val = grid[I][J];

            for (int i = 1; i <= 4; i++) {
                int Add = 1;
                if (i == val)
                    Add = 0;

                if (exist(I, J, i)) {
                    auto [nI, nJ] = new_ij(I, J, i);
                    if ((W + Add) < visited[nI][nJ]) {
                        visited[nI][nJ] = W + Add;
                        pq.push({W + Add, nI, nJ});
                    }
                }
            }
        }
        return visited[m - 1][n - 1];
    }
};