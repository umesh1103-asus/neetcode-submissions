struct TrieNode {
    vector<TrieNode*> children;
    bool isEnd;

    TrieNode() : children(26, nullptr), isEnd(false) {}
};

class PrefixTree {
    TrieNode* root;

public:
    PrefixTree() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node || !node->children[idx]) return false;
            node = node->children[idx];
        }
        return node && node->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (!node || !node->children[idx]) return false;
            node = node->children[idx];
        }
        return true;
    }
};
