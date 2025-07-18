/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

// 7 ms 
// class Solution {
// public:
//     vector<vector<int>> levelOrder(Node* root) {

//         if (!root)
//             return {};

//         queue<Node*> Q;
//         Q.push(root);

//         vector<vector<int>> answer;

//         while (!Q.empty()) {

//             queue<Node*> q;
//             swap(Q, q);

//             vector<int> ans;

//             while (!q.empty()) {

//                 Node* node = q.front();
//                 q.pop();

//                 if (node) {

//                     ans.push_back(node->val);

//                     for (Node* child : node->children)
//                         Q.push(child);
//                 }
//             }

//             answer.push_back(ans);
//         }

//         return answer;
//     }
// };

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root)
            return {};

        queue<Node*> q;
        q.push(root);

        vector<vector<int>> result;

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> level;

            for (int i = 0; i < levelSize; ++i) {
                Node* node = q.front();
                q.pop();

                level.push_back(node->val);

                for (Node* child : node->children) {
                    if (child)
                        q.push(child);
                }
            }

            result.push_back(level);
        }

        return result;
    }
};
