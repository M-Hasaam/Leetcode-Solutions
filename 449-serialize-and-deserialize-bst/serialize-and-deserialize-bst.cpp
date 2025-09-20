/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return "null";
        return to_string(root->val) + "," + serialize(root->left) + "," +
               serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        vector<string> nodes;
        string token;
        stringstream ss(data);

        while (getline(ss, token, ',')) {
            nodes.push_back(token);
        }

        int idx = 0;

        return build(nodes, idx);
    }

private:
    TreeNode* build(const vector<string>& nodes, int& idx) {
        if (nodes[idx] == "null") {
            idx++;
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(nodes[idx++]));
        root->left = build(nodes, idx);
        root->right = build(nodes, idx);

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;