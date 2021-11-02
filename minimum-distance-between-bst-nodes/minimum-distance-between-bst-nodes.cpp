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
    int prev=-1000000;
    int mn=INT_MAX;
    void solve(TreeNode* root){
        if(!root){
            return;
        }
        minDiffInBST(root->left);
       
        mn=min(mn,root->val-prev);
         prev=root->val;
        
        minDiffInBST(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        solve(root);
        return mn;
    }
};