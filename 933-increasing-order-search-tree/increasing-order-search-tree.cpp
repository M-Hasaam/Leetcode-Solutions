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
    struct L_R {
        TreeNode* left_most = nullptr;
        TreeNode* right_most = nullptr;

        L_R(TreeNode* l = nullptr, TreeNode* r = nullptr)
            : left_most(l), right_most(r) {}
    };

    L_R rec(TreeNode* node) {

        if (!node)
            return L_R();

        if (!node->left && !node->right)
            return L_R(node, node);

        if (!node->right) {
            L_R left = rec(node->left);

            left.right_most->right = node;
            node->right = nullptr;
            node->left = nullptr;

            return L_R(left.left_most, node);
        }
        if (!node->left) {
            L_R right = rec(node->right);

            node->right = right.left_most;
            node->left = nullptr;

            return L_R(node, right.right_most);
        }

        L_R left = rec(node->left);
        L_R right = rec(node->right);

        left.right_most->right = node;
        node->right = right.left_most;
        node->left = nullptr;

        return L_R(left.left_most, right.right_most);
    }

public:
    TreeNode* increasingBST(TreeNode* root) {

        L_R ans = rec(root);

        return ans.left_most;
    }
};