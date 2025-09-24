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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } 
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } 
        else {
            // Found the node
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            } 
            else if (!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } 
            else if (!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            } 
            else {
                // Node with two children
                TreeNode* succ = findMin(root->right);
                root->val = succ->val;
                root->right = deleteNode(root->right, succ->val);
            }
        }
        return root;
    }

private:
    TreeNode* findMin(TreeNode* node) {
        while (node->left) node = node->left;
        return node;
    }
};
