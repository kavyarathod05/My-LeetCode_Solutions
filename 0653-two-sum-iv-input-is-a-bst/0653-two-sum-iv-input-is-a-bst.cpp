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
    bool f(TreeNode* root,set<int>&st, int k){
        if(!root)return false;
        if(f(root->left, st, k)) return true;
        int v = root->val;
        if(st.count(k-v)) return true;
        st.insert(v);
        if(f(root->right, st, k)) return true;
        return false;
    }

    bool findTarget(TreeNode* root, int k) {
        if(!root)return false;
        set<int>st;
        return f(root, st, k);
    }
};