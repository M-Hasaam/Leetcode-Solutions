class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (string str : strs) {
            int zeros = 0, ones = 0;
            for (char ch : str) {
                if (ch == '0')
                    zeros++;
                else
                    ones++;
            }

            for (int i = m; i >= zeros; i--) {
                for (int j = n; j >= ones; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
                }
            }
        }

        return dp[m][n];
    }
};

class Solution_2 {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int count = 0;

        for (string str : strs) {

            if (str.size() > m + n)
                continue;

            int ones = 0, zeros = 0;

            for (char ch : str) {
                if (ch == '0')
                    zeros++;
                else if (ch == '1')
                    ones++;
            }

            if (ones <= n && zeros <= m)
                count++;
        }
        return count;
    }
};