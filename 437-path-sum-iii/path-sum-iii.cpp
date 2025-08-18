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
    int pathSum(TreeNode* root, int targetSum) {
        if (!root)
            return 0;

        return pathSum(root->left, targetSum) +
               pathSum(root->right, targetSum) + rec(root, targetSum);
    }

    int rec(TreeNode* root, long long CurrSum) {
        if (!root)
            return 0;

        int count = 0;

        if (root->val == CurrSum)
            count++;

        long long LeftSum = CurrSum - root->val;

        count += rec(root->left, LeftSum);
        count += rec(root->right, LeftSum);

        return count;
    }
};