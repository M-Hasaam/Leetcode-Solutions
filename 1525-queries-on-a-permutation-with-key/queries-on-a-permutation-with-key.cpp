class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {

        int n = queries.size();

        unordered_map<int, int> Map;
        for (int i = 1; i <= m; i++)
            Map[i] = i - 1;

        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++) {
            ans[i] = Map[queries[i]];

            for (int j = 1; j <= m; j++)
                if (Map[j] < ans[i])
                    Map[j]++;

            Map[queries[i]] = 0;
        }

        return ans;
    }
};