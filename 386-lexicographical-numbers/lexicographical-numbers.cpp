class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        ans.reserve(n);

        long long curr = 1;

        for (int i = 1; i <= n; i++) {
            ans.push_back((int)curr);

            if (curr * 10 <= n) {   
                curr *= 10;
            } else {
                if (curr >= n)
                    curr /= 10;

                curr++;

                while (curr % 10 == 0)
                    curr /= 10;
            }
        }
        return ans;
    }
};
