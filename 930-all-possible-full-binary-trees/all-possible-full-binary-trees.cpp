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
    unordered_map<int, vector<TreeNode*>> Mem;

public:
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> result;

        if (n % 2 == 0)
            return {};

        if (Mem.count(n)) {
            return Mem[n];
        }

        if (n == 1) {
            return Mem[n] = {new TreeNode(0)};
        }

        for (int L = 1; L < n; L += 2) {
            int R = n - 1 - L;

            auto left = allPossibleFBT(L);
            auto right = allPossibleFBT(R);

            for (auto& l : left) {
                for (auto& r : right) {
                    TreeNode* root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    result.push_back(root);
                }
            }
        }
        return Mem[n] = result;
    }
};