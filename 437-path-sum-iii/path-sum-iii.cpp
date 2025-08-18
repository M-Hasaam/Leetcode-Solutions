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
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> Prefix;
        Prefix[0] = 1;

        return rec(root, 0, targetSum, Prefix);
    }

    int rec(TreeNode* root, long long CurrSum, int target,
            unordered_map<long long, int>& Prefix) {

        if (!root)
            return 0;

        CurrSum += root->val;

        int count = 0;

        if (Prefix.count(CurrSum - target))
            count += Prefix[CurrSum - target];

        Prefix[CurrSum]++;

        count += rec(root->left, CurrSum, target, Prefix);
        count += rec(root->right, CurrSum, target, Prefix);

        Prefix[CurrSum]--;

        return count;
    }
};

class Solution2_18ms {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if (!root)
            return 0;

        return pathSum(root->left, targetSum) +
               pathSum(root->right, targetSum) + rec(root, targetSum);
    }

    int rec(TreeNode* root, long long CurrSum) {
        if (!root)
            return 0;

        int count = 0;

        if (root->val == CurrSum)
            count++;

        long long LeftSum = CurrSum - root->val;

        count += rec(root->left, LeftSum);
        count += rec(root->right, LeftSum);

        return count;
    }
};