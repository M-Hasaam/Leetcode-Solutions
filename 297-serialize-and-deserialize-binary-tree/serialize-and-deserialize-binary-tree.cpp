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
            return "[]";

        if (!root->left && !root->right)
            return "[" + to_string(root->val) + "]";

        string left_data = serialize(root->left);
        string right_data = serialize(root->right);

        return "[" + to_string(root->val) + "(" +
               to_string(left_data.length()) + "-" +
               to_string(right_data.length()) + ")" + left_data + right_data +
               "]";
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        if (data == "[]")
            return nullptr;

        int length = data.length();
        int b_i = 0, d_i = 0, e_i = 0;

        while (data[b_i] != '(' && b_i < length)
            b_i++;

        if (b_i < length - 1) {

            d_i = b_i + 1;
            while (data[d_i] != '-')
                d_i++;
            e_i = d_i + 1;
            while (data[e_i] != ')')
                e_i++;

            int left_len = stoi(data.substr(b_i + 1)),
                right_len = stoi(data.substr(d_i + 1));
            int left_data_idx = e_i + 1,
                right_data_idx = left_data_idx + left_len;

            string left_data = data.substr(left_data_idx, left_len);
            string right_data = data.substr(right_data_idx, right_len);

            TreeNode* root = new TreeNode(stoi(data.substr(1, b_i - 1)));

            root->left = deserialize(left_data);
            root->right = deserialize(right_data);

            return root;
        }

        return new TreeNode(stoi(data.substr(1)));
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));