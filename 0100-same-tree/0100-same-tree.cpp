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
    bool check(TreeNode* p , TreeNode* q){
        if(!p && !q) return true;
        if(!p && q) return false;
        if(!q && p) return false;
        if(p->val != q->val) return false;
        bool u= check(p->left,q->left);
        bool v= check(p->right,q->right);
        return u&&v;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr && q==nullptr) return true;
        return check(p,q);
    }
};