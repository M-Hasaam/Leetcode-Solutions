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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        unordered_map<int, int> inMap;

        for (int i = 0; i < inorder.size(); i++)
            inMap[inorder[i]] = i;

        int post_index = postorder.size() - 1;

        return build(inorder, postorder, inMap,  post_index, 0,
                     (int)inorder.size() - 1);
    }

private:
    TreeNode* build(const vector<int>& inorder, const vector<int>& postorder,
                    const unordered_map<int, int>& inMap, int& post_index,
                    int start, int end) {

        if (start > end)
            return nullptr;

        int mid_root_val = postorder[post_index--];
        int mid_root_index = inMap.at(mid_root_val);

        TreeNode* root = new TreeNode(mid_root_val);

        root->right = build(inorder, postorder, inMap, post_index,
                            mid_root_index + 1, end);
        root->left = build(inorder, postorder, inMap, post_index, start,
                           mid_root_index - 1);

        return root;
    }
};