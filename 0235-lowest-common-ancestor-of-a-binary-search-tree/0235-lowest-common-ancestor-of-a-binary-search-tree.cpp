class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        if (root == p || root == q) return root;

        if (root->val >= min(p->val, q->val) && root->val <= max(p->val, q->val)) {
            return root;
        }

        if (root->val < min(p->val, q->val)) {
            return lowestCommonAncestor(root->right, p, q);
        }

        return lowestCommonAncestor(root->left, p, q);
    }
};
