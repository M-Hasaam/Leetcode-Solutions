class Solution {
public:
    vector<int> grayCode(int n) {
        int total = 1 << n;
        vector<int> ans(total, 0);

        for (int i = 0; i < total; i++)
            ans[i] = i ^ (i >> 1);

        return ans;
    }
};