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
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> SET;
        return dfs(root, k, SET);
    }

private:
    bool dfs(TreeNode* node, const int& k, unordered_set<int>& SET) {

        if (!node)
            return false;

        if (SET.count(k - node->val))
            return true;

        SET.insert(node->val);

        return dfs(node->left, k, SET) || dfs(node->right, k, SET);
    }
};