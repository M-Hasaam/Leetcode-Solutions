class Solution_1st_16ms {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        vector<vector<int>> graph(n + 1);

        vector<int> Trust_factor(n + 1, 0);

        for (const auto& A_B : trust) {
            graph[A_B[0]].emplace_back(A_B[1]);
            Trust_factor[A_B[1]]++;
        }

        for (int i = 1; i <= n; i++)
            if (Trust_factor[i] == n - 1 && graph[i].size() == 0)
                return i;

        return -1;
    }
};

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> degree(n + 1, 0);

        for (const auto& t : trust) {
            degree[t[0]]--; // trusts someone -> out-degree
            degree[t[1]]++; // is trusted by someone -> in-degree
        }

        for (int i = 1; i <= n; ++i) {
            if (degree[i] == n - 1)
                return i;
        }

        return -1;
    }
};
