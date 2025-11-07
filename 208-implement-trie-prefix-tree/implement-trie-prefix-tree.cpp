class Trie {

    struct Node {
        bool isEnd = true;
        Node* child['z' - 'a' + 1] = {nullptr};

        Node(bool iE) : isEnd(iE) {}
    };

    Node* root = nullptr;

public:
    Trie() { root = new Node(0); }

    void insert(string word) {
        Node* curr = root;

        for (char ch : word) {
            int idx = ch - 'a';
            if (!curr->child[idx]) {
                curr->child[idx] = new Node(0);
            }
            curr = curr->child[idx];
        }
        curr->isEnd = 1;
    }

    bool search(string word) {
        Node* curr = root;

        for (char ch : word) {
            int idx = ch - 'a';
            if (!curr->child[idx]) {
                return false;
            }
            curr = curr->child[idx];
        }

        return curr->isEnd;
    }

    bool startsWith(string prefix) {
        Node* curr = root;

        for (char ch : prefix) {
            int idx = ch - 'a';
            if (!curr->child[idx]) {
                return false;
            }
            curr = curr->child[idx];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */