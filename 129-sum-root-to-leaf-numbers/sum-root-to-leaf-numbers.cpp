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
    int ans = 0;
    void rec(TreeNode* root, int val) {

        if (root) {
            if (!root->left && !root->right) {
                ans += val * 10 + root->val;
                return;
            } else {
                rec(root->left, val * 10 + root->val);
                rec(root->right, val * 10 + root->val);
            }
        }
    }
    int sumNumbers(TreeNode* root) {
        rec(root,0);
        return ans;
    }
};