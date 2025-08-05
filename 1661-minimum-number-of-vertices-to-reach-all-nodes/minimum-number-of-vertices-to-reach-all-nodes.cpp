class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) 
    {
        vector<bool> is_pointed(n, false);
        vector<int> answer;

        for (const auto& edge : edges) {
            is_pointed[edge[1]] = true;
        }

        for (int i = 0; i < n; i++) {
            if (!is_pointed[i])
                answer.push_back(i);
        }

        return answer;
    }
};