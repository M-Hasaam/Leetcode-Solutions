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
    int ans = INT_MIN;

    int rec(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int right = rec(root->right);
        int left = rec(root->left);
        int val = root->val;

        ans = max(val, max(ans, max(val + right + left,
                                    max(val + left, val + right))));

        return max(val, val + max(right, left));
    }
    int maxPathSum(TreeNode* root) {

        rec(root);

        return ans;
    }
};