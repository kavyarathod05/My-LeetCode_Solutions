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
    int check(TreeNode* root, int &maxi){
        if(!root){
            return 0;
        }
        int lh = max(0, check(root->left, maxi));
        int rh = max(0,check(root->right,maxi));
        maxi =max(maxi , lh+rh+root->val);
        return max(lh+root->val, rh+root->val);
    }
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int maxi = INT_MIN;
        check(root,maxi);
        return maxi;
    }
};