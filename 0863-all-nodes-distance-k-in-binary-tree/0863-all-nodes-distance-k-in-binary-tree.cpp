class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;

    void buildParent(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            auto node = q.front();
            q.pop();

            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }

            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root,
                          TreeNode* target,
                          int k) {

        buildParent(root);

        queue<TreeNode*> q;
        unordered_set<TreeNode*> vis;

        q.push(target);
        vis.insert(target);

        int dist = 0;

        while (!q.empty()) {

            int sz = q.size();

            if (dist == k)
                break;

            dist++;

            while (sz--) {

                auto node = q.front();
                q.pop();

                if (node->left &&
                    !vis.count(node->left)) {

                    vis.insert(node->left);
                    q.push(node->left);
                }

                if (node->right &&
                    !vis.count(node->right)) {

                    vis.insert(node->right);
                    q.push(node->right);
                }

                if (parent.count(node) &&
                    !vis.count(parent[node])) {

                    vis.insert(parent[node]);
                    q.push(parent[node]);
                }
            }
        }

        vector<int> ans;

        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};