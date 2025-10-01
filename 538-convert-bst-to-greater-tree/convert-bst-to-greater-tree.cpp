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
class Solution { // using sum 
    int sum = 0;
    void rec(TreeNode* root) {
        if (!root)
            return;

        rec(root->right);

        sum += root->val;
        root->val = sum;

        rec(root->left);
    }

public:
    TreeNode* convertBST(TreeNode* root) {
        rec(root);

        return root;
    }
};

class Solution_using_pre {
    TreeNode* pre = nullptr;
    void rec(TreeNode* root) {
        if (!root)
            return;

        TreeNode* temp_pre = pre;

        pre = nullptr;
        rec(root->right);
        pre = temp_pre;

        root->val +=
            (root->right ? root->right->val : 0) + (pre ? pre->val : 0);

        pre = root;

        rec(root->left);
    }

public:
    TreeNode* convertBST(TreeNode* root) {
        rec(root);

        return root;
    }
};