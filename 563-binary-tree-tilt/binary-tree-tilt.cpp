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
    int tilt = 0;
    int sum(TreeNode* root) {
        if (!root)
            return 0;

        int left = sum(root->left);
        int right = sum(root->right);

        tilt += abs(right - left);

        return root->val + left + right;
    }

public:
    int findTilt(TreeNode* root) {
        tilt = 0;
        sum(root);
        return tilt;
    }
};