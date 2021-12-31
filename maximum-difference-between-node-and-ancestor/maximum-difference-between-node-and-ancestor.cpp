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
     int ans=INT_MIN;
//      void findMax(TreeNode* root,int& mx){
//         if(!root){
//             return;
//         }
        
//         findMax(root->left,mx);
//         findMax(root->right,mx);
//     }
    void findMinMax(TreeNode* root,int& mn,int& mx){
        if(!root){
            return;
        }
        mn=min(root->val,mn);
        mx=max(root->val,mx);
        findMinMax(root->left,mn,mx);
        findMinMax(root->right,mn,mx);
    }
    void solve(TreeNode* root){
        if(!root) return;
        int mn=INT_MAX,mx=INT_MIN;
        findMinMax(root,mn,mx);
        //cout<<root->val<<" "<<mn<<" "<<mx<<"\n";
        if(mn!=INT_MAX){
            ans = max(ans,abs(root->val-mn));
        }
        if(mx!=INT_MIN){
            ans = max(ans,abs(root->val-mx));
        }
        solve(root->left);
        solve(root->right);
    }
    int maxAncestorDiff(TreeNode* root) {
        solve(root);
        return ans;
    }
};