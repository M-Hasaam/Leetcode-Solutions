class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int X = board.size(), Y = board[0].size();

        using P = pair<int, int>;

        queue<P> q;

        for (int i = 0; i < X; i++) {

            if (board[i][0] == 'O') {
                q.emplace(i, 0);
                board[i][0] = 'S';
            }

            if (board[i][Y - 1] == 'O') {
                q.emplace(i, Y - 1);
                board[i][Y - 1] = 'S';
            }
        }
        for (int j = 0; j < Y; j++) {

            if (board[0][j] == 'O') {
                q.emplace(0, j);
                board[0][j] = 'S';
            }

            if (board[X - 1][j] == 'O') {
                q.emplace(X - 1, j);
                board[X - 1][j] = 'S';
            }
        }

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto [I, J] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nI = I + dx[i], nJ = J + dy[i];

                if (0 <= nI && nI < X && 0 <= nJ && nJ < Y &&
                    board[nI][nJ] == 'O') {

                    q.emplace(nI, nJ);
                    board[nI][nJ] = 'S';
                }
            }
        }

        for (int i = 0; i < X; i++) {
            for (int j = 0; j < Y; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                if (board[i][j] == 'S')
                    board[i][j] = 'O';
            }
        }
    }
};
