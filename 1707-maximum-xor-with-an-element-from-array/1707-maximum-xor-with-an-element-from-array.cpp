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

            if (!node->links[bit]) {
                node->links[bit] = new Node();
            }

            node = node->links[bit];
        }
    }

    int getMax(int x) {
        Node* node = root;

        if (!node->links[0] && !node->links[1]) return -1;

        int maxi = 0;

        for (int i = 31; i >= 0; i--) {
            int bit = (x >> i) & 1;

            if (node->links[1 - bit]) {
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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {

        sort(nums.begin(), nums.end());

        vector<tuple<int,int,int>> offlineQueries;

        for (int i = 0; i < queries.size(); i++) {
            int xi = queries[i][0];
            int mi = queries[i][1];
            offlineQueries.push_back({mi, xi, i});
        }

        sort(offlineQueries.begin(), offlineQueries.end());

        Trie trie;
        vector<int> ans(queries.size());

        int j = 0;

        for (auto &[mi, xi, idx] : offlineQueries) {

            while (j < nums.size() && nums[j] <= mi) {
                trie.insert(nums[j]);
                j++;
            }

            if (j == 0) {
                ans[idx] = -1;
            } else {
                ans[idx] = trie.getMax(xi);
            }
        }

        return ans;
    }
};