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
    unordered_map<int, int> M;
    int pre_idx = 0;

    TreeNode* rec(vector<int>& preorder, vector<int>& inorder,int left,int right) {
        if (left > right)
            return nullptr;

        int val = preorder[pre_idx++];
        int in_idx = M[val];

        TreeNode* root = new TreeNode(val);

        root->left = rec(preorder,inorder,left,in_idx-1);
        root->right = rec(preorder,inorder,in_idx+1,right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        for (int i = 0; i < inorder.size(); i++) {
            M[inorder[i]] = i;
        }

        return rec(preorder,inorder,0,inorder.size()-1);
    }
};