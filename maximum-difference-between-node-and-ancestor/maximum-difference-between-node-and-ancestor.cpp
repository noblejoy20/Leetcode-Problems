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

// Brute force approach O(N^2)
class Solution {
public:
     int ans=INT_MIN;
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

// Optimized Approach O(N)
// Calculate min and max at each node recursively and update the ans at each point.

class Solution {
public:
    int ans=INT_MIN;
    void findMinMax(TreeNode* root,int mn,int mx){
        if(!root){
            return;
        }
        mn=min(root->val,mn);
        mx=max(root->val,mx);
        ans=max(ans,abs(mx-mn));
        findMinMax(root->left,mn,mx);
        findMinMax(root->right,mn,mx);
    }
    int maxAncestorDiff(TreeNode* root) {
        int mn=INT_MAX,mx=INT_MIN;
        findMinMax(root,mn,mx);
        return ans;
    }
};
