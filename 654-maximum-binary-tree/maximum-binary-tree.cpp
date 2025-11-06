/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructMaximumBinaryTree(nums, 0, nums.size() - 1);
    }
    
private:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums, int left, int right) {
        if (left > right)
            return nullptr;
        if (left == right)
            return new TreeNode(nums[left]);

        int max_i = left;
        for (int i = left + 1; i <= right; i++) {
            if (nums[i] > nums[max_i]) {
                max_i = i;
            }
        }

        TreeNode* root = new TreeNode(nums[max_i]);
        root->left = constructMaximumBinaryTree(nums, left, max_i - 1);
        root->right = constructMaximumBinaryTree(nums, max_i + 1, right);

        return root;
    }
};