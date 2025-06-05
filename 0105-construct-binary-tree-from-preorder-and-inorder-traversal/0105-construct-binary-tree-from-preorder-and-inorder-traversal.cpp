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
    TreeNode* f(vector<int>&pre, vector<int>&in,int start , int end, int& idx){
        if(start>end){
            return NULL;
        }
        int i=start;
        int val = pre[idx];
        TreeNode* root= new TreeNode(val);
        for(;i<=end;i++){
            if(in[i]==val) break;
        }
        idx++;
        root->left= f(pre,in, start,i-1,idx);
        root->right= f(pre, in, i+1, end,idx);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int idx=0;
        return f(preorder, inorder, 0, n-1, idx);
    }
};