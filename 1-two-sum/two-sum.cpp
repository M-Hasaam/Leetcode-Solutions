class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> M;

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int first = nums[i], second =target - first;
            if (M.count(second)) {
                return {M[second], i};
            }
            M[first] = i;
        }

        return {0, 0};
    }
};