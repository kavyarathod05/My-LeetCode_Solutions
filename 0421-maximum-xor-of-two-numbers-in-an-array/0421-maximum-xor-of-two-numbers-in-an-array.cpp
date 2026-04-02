class Node {
public:
    Node* links[2];

    Node() {
        links[0] = links[1] = NULL;
    }
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(int x) {
        Node* node = root;

        for (int i = 31; i >= 0; i--) {
            int bit = (x >> i) & 1;

            if (node->links[bit] == NULL) {
                node->links[bit] = new Node();
            }

            node = node->links[bit];
        }
    }

    int getMax(int x) {
        Node* node = root;
        int maxi = 0;

        for (int i = 31; i >= 0; i--) {
            int bit = (x >> i) & 1;

            if (node->links[1 - bit] != NULL) {
                maxi |= (1 << i);
                node = node->links[1 - bit];
            } else {
                node = node->links[bit];
            }
        }

        return maxi;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;

        for (int num : nums) {
            trie.insert(num);
        }

        int maxi = 0;

        for (int num : nums) {
            maxi = max(maxi, trie.getMax(num));
        }

        return maxi;
    }
};