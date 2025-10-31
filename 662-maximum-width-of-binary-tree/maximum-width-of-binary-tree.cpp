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
    int widthOfBinaryTree(TreeNode* root) {

        if (!root)
            return 0;

        long long maxWidth = 0;

        queue<pair<TreeNode*, long long>> q;

        q.emplace(root, 0);

        while (!q.empty()) {

            int size = q.size();

            long long left = q.front().second;
            long long right = 0;

            for (int i = 0; i < size; i++) {

                auto [curr, index] = q.front();

                right = index;

                q.pop();

                if (curr->left)
                    // q.emplace(curr->left, (2 * index) + 1);
                    q.emplace(curr->left, (2 * index) + 1 - (left + 1));
                // to prevent overflow
                if (curr->right)
                    // q.emplace(curr->right, (2 * index) + 2);
                    q.emplace(curr->right, (2 * index) + 2 - (left + 1));
            }

            maxWidth = max(maxWidth, right - left + 1);
        }

        return maxWidth;
    }
};