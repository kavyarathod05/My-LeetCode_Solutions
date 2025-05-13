class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;

        int ans = 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int sz = q.size();
            unsigned long long mini = q.front().second; // prevent overflow
            unsigned long long first = 0, last = 0;

            for (int i = 0; i < sz; i++) {
                unsigned long long curr = q.front().second ;
                TreeNode* node = q.front().first;
                q.pop();

                if (i == 0) first = curr;
                if (i == sz - 1) last = curr;

                if (node->left)
                    q.push({node->left, curr * 2 + 1});
                if (node->right)
                    q.push({node->right, curr * 2 + 2});
            }

            ans = max(ans, (int)(last - first + 1));
        }

        return ans;
    }
};
