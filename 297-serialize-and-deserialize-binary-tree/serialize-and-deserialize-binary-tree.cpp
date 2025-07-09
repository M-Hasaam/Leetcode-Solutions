/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// // 52ms
// class Codec {
// public:
//     // Encodes a tree to a single string.
//     string serialize(TreeNode* root) {
//         if (!root)
//             return "[]";

//         if (!root->left && !root->right)
//             return "[" + to_string(root->val) + "]";

//         string left_data = serialize(root->left);
//         string right_data = serialize(root->right);

//         return "[" + to_string(root->val) + "(" +
//                to_string(left_data.length()) + "-" +
//                to_string(right_data.length()) + ")" + left_data + right_data
//                +
//                "]";
//     }

//     // Decodes your encoded data to tree.
//     TreeNode* deserialize(string data) {

//         if (data == "[]")
//             return nullptr;

//         int length = data.length();
//         int b_i = 0, d_i = 0, e_i = 0;

//         while (data[b_i] != '(' && b_i < length)
//             b_i++;

//         if (b_i < length - 1) {

//             d_i = b_i + 1;
//             while (data[d_i] != '-')
//                 d_i++;
//             e_i = d_i + 1;
//             while (data[e_i] != ')')
//                 e_i++;

//             int left_len = stoi(data.substr(b_i + 1)),
//                 right_len = stoi(data.substr(d_i + 1));
//             int left_data_idx = e_i + 1,
//                 right_data_idx = left_data_idx + left_len;

//             string left_data = data.substr(left_data_idx, left_len);
//             string right_data = data.substr(right_data_idx, right_len);

//             TreeNode* root = new TreeNode(stoi(data.substr(1, b_i - 1)));

//             root->left = deserialize(left_data);
//             root->right = deserialize(right_data);

//             return root;
//         }

//         return new TreeNode(stoi(data.substr(1)));
//     }
// };

// 52ms
class Codec {

    string serialize_rec(TreeNode* root, int& count) {
        count++;

        if (!root)
            return "null";

        return to_string(root->val) + "," + serialize_rec(root->left, count) +
               "," + serialize_rec(root->right, count);
    }

    TreeNode* deserialize_rec(const vector<string>& nodes, int& index,
                              const int& count) {

        if (nodes[index] == "null" || index >= count) {
            index++;
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(nodes[index++]));

        root->left = deserialize_rec(nodes, index, count);
        root->right = deserialize_rec(nodes, index, count);

        return root;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        int count = 0;
        string node_data = serialize_rec(root, count);

        return to_string(count) + "-" + node_data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        int d_i = data.find('-');
        int n = stoi(data);

        vector<string> nodes(n);

        stringstream ss(data.substr(d_i + 1));

        int i = 0;
        string node_data;
        while (getline(ss, node_data, ',')) {
            nodes[i++] = node_data;
        }

        int index = 0;
        return deserialize_rec(nodes, index, n);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));