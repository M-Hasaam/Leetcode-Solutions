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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (!root)
            return nullptr;

        if (root->val < low)
            return trimBST(root->right, low, high);

        if (root->val > high)
            return trimBST(root->left, low, high);

        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);

        return root;
    }
};

class Solution_2 {
    int L = 0, H = 0;

    TreeNode* dfs(TreeNode* curr, TreeNode* parent) {
        if (!curr)
            return nullptr;

        if (L <= curr->val && curr->val <= H) {

            curr->left = dfs(curr->left, curr);
            curr->right = dfs(curr->right, curr);

            return curr;
        }

        if (!curr->left && !curr->right) {
            delete curr;
            curr = nullptr;
        } else if (!curr->left) {

            TreeNode* right = curr->right;

            delete curr;

            curr = right;
        } else if (!curr->right) {

            TreeNode* left = curr->left;

            delete curr;

            curr = left;
        } else {

            TreeNode* r_p = curr;
            TreeNode* right = curr->right;

            while (right->left) {
                r_p = right;
                right = right->left;
            }

            swap(curr->val, right->val);

            TreeNode* r_L_right = right->right;

            delete right;

            r_p->left = r_L_right;
        }

        curr->left = dfs(curr->left, curr);
        curr->right = dfs(curr->right, curr);

        return curr;
    }

public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        TreeNode* parent = nullptr;
        TreeNode* curr = root;

        L = low, H = high;

        return dfs(curr, parent);
    }
};