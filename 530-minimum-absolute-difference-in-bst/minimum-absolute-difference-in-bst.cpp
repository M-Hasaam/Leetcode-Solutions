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
    int MIN = INT_MAX;
    TreeNode* pre = nullptr;

    int getMinimumDifference(TreeNode* root) {
        MIN = INT_MAX;
        pre = nullptr;

        rec(root);

        return MIN;
    }

    void rec(TreeNode* root) {

        if (!root)
            return;

        rec(root->left);

        if (pre) {
            MIN = min(MIN, abs(root->val - pre->val));
        }
        pre = root;

        rec(root->right);
    }
};