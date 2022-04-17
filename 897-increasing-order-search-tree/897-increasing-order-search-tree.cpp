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
    void solve(TreeNode* root,vector<int>& ans){
        if(!root) return;
        solve(root->left,ans);
        ans.push_back(root->val);
        solve(root->right,ans);
    }
    TreeNode* increasingBST(TreeNode* root) {
        if(root==NULL) return root;
        vector<int> ans;
        solve(root,ans);
        
        TreeNode* ptr=new TreeNode(ans[0]);
        root=ptr;
        for(int i=1;i<ans.size();i++){
            ptr->right=new TreeNode(ans[i]);
            ptr=ptr->right;
        }
        return root;
    }
};