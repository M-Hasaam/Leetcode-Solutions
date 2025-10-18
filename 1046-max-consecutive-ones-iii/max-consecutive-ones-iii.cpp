class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int left = 0, right = 0;
        int zeroCount = 0;
        int size = nums.size();

        int maxOnes = 0;

        while (right < size) {

            if (nums[right] == 0)
                zeroCount++;

            while (k < zeroCount) {
                if (nums[left] == 0)
                    zeroCount--;
                left++;
            }

            maxOnes = max(maxOnes, right - left + 1);
            right++;
        }

        return maxOnes;
    }
};