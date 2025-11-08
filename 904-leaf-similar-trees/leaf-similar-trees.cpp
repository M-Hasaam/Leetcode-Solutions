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
    void rec(TreeNode* root, vector<int>& V) {
        if (!root)
            return;

        rec(root->left, V);

        if (!root->left && !root->right) {
            V.push_back(root->val);
        }

        rec(root->right, V);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {

        vector<int> V1, V2;

        rec(root1, V1);
        rec(root2, V2);

        int size1 = V1.size();
        int size2 = V2.size();

        if (size1 != size2)
            return false;

        for (int i = 0; i < size1; i++)
            if (V1[i] != V2[i])
                return false;

        return true;
    }
};