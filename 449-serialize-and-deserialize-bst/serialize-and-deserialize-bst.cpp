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

        queue<string> Q_nodes;
        string token;
        stringstream ss(data);

        while (getline(ss, token, ',')) {
            Q_nodes.push(token);
        }

        return build(Q_nodes);
    }

private:
    TreeNode* build(queue<string>& Q_nodes) {
        if (Q_nodes.front() == "null") {
            Q_nodes.pop();
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(Q_nodes.front()));
        Q_nodes.pop();

        root->left = build(Q_nodes);
        root->right = build(Q_nodes);

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;