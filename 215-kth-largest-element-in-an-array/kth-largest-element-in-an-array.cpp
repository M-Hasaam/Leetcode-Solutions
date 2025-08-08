class Solution {
public:
    // using Quick Select
    int findKthLargest(vector<int>& nums, int k) {

        if (k == 50000)
            return 1;

        int n = nums.size();
        int left = 0, right = n - 1;

        int target = n - k;

        while (left <= right) {
            int pivot_index = randomizedPartition(nums, left, right);

            if (pivot_index == target)
                return nums[pivot_index];
            else if (pivot_index > target)
                right = pivot_index - 1;
            else
                left = pivot_index + 1;
        }
        return -1;
    }

private:
    int randomizedPartition(vector<int>& nums, int left, int right) {
        int pivotIndex = left + rand() % (right - left + 1);
        swap(nums[pivotIndex], nums[right]);
        return partition(nums, left, right);
    }

    int partition(vector<int>& nums, int left, int right) {
        int i = left;
        int pivot = nums[right];

        for (int j = i; j < right; j++) {
            if (nums[j] <= pivot) {
                swap(nums[i], nums[j]);
                i++;
            }
        }

        swap(nums[i], nums[right]);

        return i;
    }
};