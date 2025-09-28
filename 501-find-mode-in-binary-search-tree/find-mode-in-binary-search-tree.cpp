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
    vector<int> findMode(TreeNode* root) {

        int count = 0;
        int maxCount = 0;

        TreeNode* pre = nullptr;

        vector<int> ans;

        function<void(TreeNode*)> inorder = [&](TreeNode* curr) {
            if (!curr)
                return;

            inorder(curr->left);

            if (pre && pre->val == curr->val) {
                count++;
            } else {
                count = 1;
            }

            if (count > maxCount) {
                maxCount = count;

                ans.clear();
                ans.push_back(curr->val);
            } else if (count == maxCount) {
                ans.push_back(curr->val);
            }

            pre = curr;

            inorder(curr->right);
        };

        inorder(root);
        return ans;
    }
};