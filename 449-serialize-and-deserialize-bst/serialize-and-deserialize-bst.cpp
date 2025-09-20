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
    // Serialize using stringstream 
    string serialize(TreeNode* root) {
        stringstream ss;
        buildString(root, ss);
        return ss.str();
    }

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
    void buildString(TreeNode* root, stringstream& ss) {
        if (!root) {
            ss << "null,";
            return;
        }
        ss << root->val << ",";
        buildString(root->left, ss);
        buildString(root->right, ss);
    }

    TreeNode* build(vector<string>& nodes, int& idx) {
        if (idx >= nodes.size() || nodes[idx] == "null") {
            idx++;
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(nodes[idx++]));
        node->left = build(nodes, idx);
        node->right = build(nodes, idx);
        return node;
    }
};

class Codec_39ms {
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