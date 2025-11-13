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
    int rec(TreeNode* node, const int minV) {
        if (!node)
            return -1;

        if (node->val > minV)
            return node->val;

        int Left = rec(node->left, minV);
        int Right = rec(node->right, minV);

        if (Left != -1 && Right != -1)
            return min(Left, Right);

        return Left != -1 ? Left : Right;
    }

public:
    int findSecondMinimumValue(TreeNode* root) {
        if (!root)
            return -1;

        return rec(root, root->val);
    }
};

class Solution_For_BST {
    int rec(TreeNode* node, const int minV) {

        if (!node)
            return minV;

        int Left = rec(node->left, minV);

        if (Left != minV)
            return Left;
        else if (node->val != minV) {
            return node->val;
        }

        int Right = rec(node->right, minV);

        if (Right != minV)
            return Right;

        return minV;
    }

public:
    int findSecondMinimumValue(TreeNode* root) {
        TreeNode* minN = root;
        while (minN->left)
            minN = minN->left;

        int minV = minN->val;

        int secondMin = rec(root, minV);

        return secondMin != minV ? secondMin : -1;
    }
};