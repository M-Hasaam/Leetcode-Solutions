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

    struct TwoCases {
        int rob_it;
        int skip_it;
    };

    TwoCases dfs(TreeNode* root) {

        if (!root)
            return {0, 0};

        auto left_Case = dfs(root->left);
        auto right_Case = dfs(root->right);

        int rob_this_Node = root->val + left_Case.skip_it + right_Case.skip_it;

        int skip_this_Node = max(left_Case.rob_it, left_Case.skip_it) +
                             max(right_Case.rob_it, right_Case.skip_it);

        return {rob_this_Node, skip_this_Node};
    }

public:
    int rob(TreeNode* root) {
        auto this_root = dfs(root);

        return max(this_root.rob_it, this_root.skip_it);
    }
};

class Solution_correct_until_60_testcases {
public:
    int rob(TreeNode* root) {

        if (!root)
            return 0;

        queue<pair<TreeNode*, bool>> q; // 1 0
        int sum[2] = {0, 0};

        q.emplace(root, 0);

        while (!q.empty()) {

            auto [curr, color] = q.front();
            q.pop();

            sum[color] += curr->val;

            if (curr->left) {
                q.emplace(curr->left, !color);
            }
            if (curr->right) {
                q.emplace(curr->right, !color);
            }
        }

        return max(sum[0], sum[1]);
    }
};
