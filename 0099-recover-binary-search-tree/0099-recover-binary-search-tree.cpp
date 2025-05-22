class Solution {
public:
    void getInorder(TreeNode* root, vector<int>& inorder) {
        if (!root) return;
        getInorder(root->left, inorder);
        inorder.push_back(root->val);
        getInorder(root->right, inorder);
    }

    void setInorder(TreeNode* root, vector<int>& inorder, int& i) {
        if (!root) return;
        setInorder(root->left, inorder, i);
        root->val = inorder[i++];
        setInorder(root->right, inorder, i);
    }

    void recoverTree(TreeNode* root) {
        vector<int> inorder;
        getInorder(root, inorder);
        sort(inorder.begin(), inorder.end());
        int i = 0;
        setInorder(root, inorder, i);
    }
};
