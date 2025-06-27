class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> M;

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (M.count(target - nums[i])) {
                return {M[target - nums[i]], i};
            }
            M[nums[i]] = i;
        }

        return {0, 0};
    }
};