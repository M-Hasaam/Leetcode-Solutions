class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxi1(n, 0), maxi2(n, 0);

        maxi1[0] = height[0];
        maxi2[n - 1] = height[n - 1];

        for (int i = 1; i < n; i++) {
            maxi1[i] = max(maxi1[i - 1], height[i]);
            maxi2[n - i - 1] = max(maxi2[n - i], height[n - i]);
        }

        int ans = 0;
        for (int i = 1; i < n - 1; i++) {
            ans += max(min(maxi1[i], maxi2[i]) - height[i],0);
        }

        return ans;
    }
};