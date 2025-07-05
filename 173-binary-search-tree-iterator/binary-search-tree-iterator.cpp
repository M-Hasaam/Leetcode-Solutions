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

// class BSTIterator {
//     TreeNode* root = nullptr;

//     stack<TreeNode*> S;
//     TreeNode* ptr = nullptr;
//     bool end = false;

// public:
//     BSTIterator(TreeNode* root) {
//         this->root = root;
//         ptr = root;
//         S.push(ptr);

//         while (ptr->left) {
//             ptr = ptr->left;
//             S.push(ptr);
//         }
//     }

//     int next() {
//         int ans = ptr->val;
//         if (!end) {

//             ptr->val = -1;

//             if (ptr->left && ptr->left->val != -1) {

//                 ptr = ptr->left;
//                 S.push(ptr);

//             } else if (!ptr->left || ptr->left->val == -1) {
//                 if (ptr->right) {
//                     ptr = ptr->right;
//                     S.push(ptr);
//                     while (ptr->left) {
//                         ptr = ptr->left;
//                         S.push(ptr);
//                     }
//                 } else {
//                     S.pop();
//                     if (S.top()->val == -1) {
//                         end = true;
//                     } else
//                         ptr = S.top();
//                 }
//             }
//         }

//         return ans;
//     }

//     bool hasNext() { return !end; }
// };

// class BSTIterator {

//     stack<TreeNode*> S;

//     void move_left() {
//         while (S.top()->left) {
//             S.push(S.top()->left);
//         }
//     }

// public:
//     BSTIterator(TreeNode* root) {

//         S.push(root);
//         move_left();
//     }

//     int next() {
//         int ans = S.top()->val;
//         TreeNode * node = S.top();

//         S.pop();

//         if (node->right) {
//             S.push(node->right);
//             move_left();
//         }

//         return ans;
//     }

//     bool hasNext() { return !S.empty(); }
// };

class BSTIterator {
    stack<TreeNode*> S;

    void move_left(TreeNode* node) {
        while (node) {
            S.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        move_left(root);
    }

    int next() {
        TreeNode* node = S.top(); S.pop();
        if (node->right)
            move_left(node->right);
        return node->val;
    }

    bool hasNext() {
        return !S.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */