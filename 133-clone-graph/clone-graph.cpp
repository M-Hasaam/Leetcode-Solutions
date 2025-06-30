/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> M;

    Node* rec(Node* node) {

        if (!node)
            return nullptr;

        else if (!M.count(node)) {

            Node* nnode = new Node(node->val);
            M[node] = nnode;

            int n = node->neighbors.size();
            nnode->neighbors.assign(n, nullptr);

            for (int i = 0; i < n; i++) {
                nnode->neighbors[i] = rec(node->neighbors[i]);
            }


            return nnode;
        }

        return M[node];
    }
    Node* cloneGraph(Node* node) { return rec(node); }
};