/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return f(preorder, i, INT_MAX);
    }
    TreeNode* f(vector<int>&preorder, int &ind, int ub){
        if(ind==preorder.size() || preorder[ind]>ub)return NULL;
        TreeNode* root= new TreeNode(preorder[ind++]);
        root->left= f(preorder, ind , root->val);
        root->right = f(preorder, ind , ub);
        return root;
    }
};