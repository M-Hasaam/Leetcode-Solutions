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
    int depth = 1;
    vector<int> ans;

    void rec(TreeNode* root, int d) {
        if (root) {
            if (d == depth) {
                ans.push_back(root->val);
                depth++;
            }

            rec(root->right, d + 1);
            rec(root->left, d + 1);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        rec(root, 1);

        return ans;
    }
};