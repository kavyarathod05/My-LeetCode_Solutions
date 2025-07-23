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
    bool bal= true;
    int f(TreeNode* root){
        if(!root) return true;
        int left = f(root->left);
        int right = f(root->right);
        if(abs(right-left)>1){
            bal = false;
        }
        return max(left ,right)+1;
    }
    bool isBalanced(TreeNode* root) {
        f(root);    
        return bal;
    }
};