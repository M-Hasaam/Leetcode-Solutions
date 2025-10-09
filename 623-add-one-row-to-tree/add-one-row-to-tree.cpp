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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {

        int h = 0;

        TreeNode dummy(0, root, nullptr);

        queue<TreeNode*> q;

        q.push(&dummy);

        while (!q.empty()) {

            int size = q.size();

            for (int i = 0; i < size; i++) {

                TreeNode* curr = q.front();
                q.pop();

                if (h == depth - 1) {

                    // if (curr->left) {
                    TreeNode* left = curr->left;
                    curr->left = new TreeNode(val);
                    curr->left->left = left;
                    // }
                    // if (curr->right) {
                    TreeNode* right = curr->right;
                    curr->right = new TreeNode(val);
                    curr->right->right = right;
                    // }

                } else {

                    if (curr->left) {
                        q.push(curr->left);
                    }
                    if (curr->right) {
                        q.push(curr->right);
                    }
                }
            }

            h++;
        }

        delete dummy.right;
        dummy.right = nullptr;

        return dummy.left;
    }
};