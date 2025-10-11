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
    vector<TreeNode*> ans;
    unordered_map<string, int> freq;

    string rec(TreeNode* node){
        if(!node)return "#";

        string key=to_string(node->val)+","+rec(node->left)+","+rec(node->right);

        if(++freq[key]==2){
            ans.push_back(node);
        }

        return key;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        rec(root);

        return ans;
    }
};