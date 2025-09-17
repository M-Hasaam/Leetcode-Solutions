class Solution {
public:
    bool dfs(int i, int j, vector<vector<char>>& board) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return false;

        if (board[i][j] != 'X')
            return false;

        board[i][j] = '#';

        dfs(i + 1, j, board);
        dfs(i - 1, j, board);
        dfs(i, j + 1, board);
        dfs(i, j - 1, board);

        return true;
    }

    int countBattleships(vector<vector<char>>& board) {
        int count = 0;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (dfs(i, j, board)) {
                    count++;
                }
            }
        }

        return count;
    }
};
