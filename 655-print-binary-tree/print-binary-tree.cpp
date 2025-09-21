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
    vector<vector<string>> printTree(TreeNode* root) {

        int height = 0;
        {
            queue<TreeNode*> q;
            q.push(root);

            while (!q.empty()) {
                int size = q.size();

                for (int i = 0; i < size; i++) {

                    TreeNode* curr = q.front();
                    q.pop();

                    if (curr->left) {
                        q.push(curr->left);
                    }

                    if (curr->right) {
                        q.push(curr->right);
                    }
                }

                height++;
            }
        }

        vector<vector<string>> ans(height,
                                   vector<string>(pow(2, height) - 1, ""));

      
      
        {
            using T = tuple<TreeNode*, int, int>;

            queue<T> q;

            q.emplace(root, 0, pow(2, height) - 1);

            int I = 0;

            while (!q.empty()) {
                int size = q.size();

                for (int i = 0; i < size; i++) {

                    auto [curr, left, right] = q.front();
                    q.pop();

                    int mid = (left + right) / 2;

                    ans[I][mid] = to_string(curr->val);

                    if (curr->left) {
                        q.emplace(curr->left, left, mid - 1);
                    }
                    if (curr->right) {
                        q.emplace(curr->right, mid + 1, right);
                    }
                }

                I++;
            }
        }

        return ans;
    }
};