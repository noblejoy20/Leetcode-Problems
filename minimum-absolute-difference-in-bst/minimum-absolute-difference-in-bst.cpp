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
    int mn=INT_MAX;
    int getMin(TreeNode* root){
        if(!root){
            return INT_MAX;
        }
        int left=getMin(root->left);
        int right=getMin(root->right);
        return min(root->val,min(left,right));
    }
    int getMax(TreeNode* root){
        if(!root){
            return INT_MIN;
        }
        int left=getMax(root->left);
        int right=getMax(root->right);
        return max(root->val,max(left,right));
    }
    void solve(TreeNode* root){
        if(!root){
            return;
        }
        
        solve(root->left);
        solve(root->right);
        if(root->left){
            mn=min(mn,abs(root->val-getMax(root->left)));
        }
        if(root->right){
            mn=min(mn,abs(root->val-getMin(root->right)));
        }
    }
    int getMinimumDifference(TreeNode* root) {
        solve(root);
        return mn;
    }
};