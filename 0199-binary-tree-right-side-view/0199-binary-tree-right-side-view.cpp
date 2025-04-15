class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            int rightmost = 0;
            for (int i = 0; i < n; ++i) {
                TreeNode* curr = q.front(); q.pop();
                if (i == n - 1) {
                    ans.push_back(curr->val);
                }
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }
        return ans;
    }
};
