class Solution {
public:
    bool findLeft(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return false;
        if (root == p || root == q) return true;
        return findLeft(root->left, p, q) || findLeft(root->right, p, q);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;

        bool inLeft = findLeft(root->left, p, q);
        bool inRight = findLeft(root->right, p, q);

        if (inLeft && inRight) return root;

        if (inLeft) return lowestCommonAncestor(root->left, p, q);
        return lowestCommonAncestor(root->right, p, q);
    }
};
