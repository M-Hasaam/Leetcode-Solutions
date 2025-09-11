class WordDictionary {

    struct TreeNode {
        bool isWord = false;
        TreeNode* children[26] = {nullptr};

        TreeNode() {}
    };

    TreeNode* root;

    bool bfs(string word, int pos, TreeNode* node) {

        if (!node)
            return false;

        if (word.size() == pos)
            return node->isWord;

        if (word[pos] == '.') {
            for (int i = 0; i < 26; i++) {
                if (bfs(word, pos + 1, node->children[i]))
                    return true;
            }
            return false;
        }

        return bfs(word, pos + 1, node->children[word[pos] - 'a']);
    }

public:
    WordDictionary() { root = new TreeNode(); }

    void addWord(string word) {

        TreeNode* node = root;

        for (char c : word) {

            int idx = c - 'a';

            if (!node->children[idx])
                node->children[idx] = new TreeNode();

            node = node->children[idx];
        }

        node->isWord = true;
    }

    bool search(string word) { return bfs(word, 0, root); }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */