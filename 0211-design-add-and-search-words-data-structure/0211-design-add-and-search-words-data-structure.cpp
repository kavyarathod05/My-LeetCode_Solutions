class Node {
public:
    Node* links[26];
    bool isEnd;

    Node() {
        for (int i = 0; i < 26; i++) {
            links[i] = nullptr;
        }
        isEnd = false;
    }
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(string s) {
        Node* node = root;
        for (char ch : s) {
            int idx = ch - 'a';
            if (node->links[idx] == nullptr) {
                node->links[idx] = new Node();
            }
            node = node->links[idx];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        return searchUtil(root, word, 0);
    }

    bool searchUtil(Node* node, string& word, int i) {
        if (!node) return false;

        if (i == word.size()) {
            return node->isEnd;
        }

        char ch = word[i];

        if (ch == '.') {
            for (int j = 0; j < 26; j++) {
                if (node->links[j] &&
                    searchUtil(node->links[j], word, i + 1)) {
                    return true;
                }
            }
            return false;
        }

        if (!node->links[ch - 'a']) return false;

        return searchUtil(node->links[ch - 'a'], word, i + 1);
    }
};

class WordDictionary {
public:
    Trie trie;

    WordDictionary() {}

    void addWord(string word) {
        trie.insert(word);
    }

    bool search(string word) {
        return trie.search(word);
    }
};