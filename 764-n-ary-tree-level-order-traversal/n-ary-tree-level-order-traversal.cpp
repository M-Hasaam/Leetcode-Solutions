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

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {

        if (!root)
            return {};

        queue<Node*> Q;
        Q.push(root);

        vector<vector<int>> answer;

        while (!Q.empty()) {

            queue<Node*> q;
            swap(Q, q);

            vector<int> ans;

            while (!q.empty()) {

                Node* node = q.front();
                q.pop();

                if (node) {

                    ans.push_back(node->val);

                    for (Node* child : node->children)
                        Q.push(child);
                }
            }

            answer.push_back(ans);
        }

        return answer;
    }
};