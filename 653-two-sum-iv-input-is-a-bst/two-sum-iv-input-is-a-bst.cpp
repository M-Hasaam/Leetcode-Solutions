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
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder_Array;
        inorder(root, inorder_Array);

        int l = 0, r = inorder_Array.size() - 1;

        while (l < r) {
            int sum = inorder_Array[l] + inorder_Array[r];
            if (sum == k)
                return true;
            else if (sum < k)
                l++;
            else if (sum > k)
                r--;
        }

        return false;
    }

private:
    void inorder(TreeNode* node, vector<int>& inorder_Array) {
        if (node) {
            inorder(node->left,inorder_Array);
            inorder_Array.push_back(node->val);
            inorder(node->right,inorder_Array);
        }
    }
};

class Solution_DFS {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> SET;
        return dfs(root, k, SET);
    }

private:
    bool dfs(TreeNode* node, const int& k, unordered_set<int>& SET) {

        if (!node)
            return false;

        if (SET.count(k - node->val))
            return true;

        SET.insert(node->val);

        return dfs(node->left, k, SET) || dfs(node->right, k, SET);
    }
};