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
    
    // Think of target sum problem and simulate the same way.
    // TC:O(N^2)
    int ans=0;
    int pathSum(TreeNode* root, int sum) {
        if(root){
            dfs(root,sum); // this will count the path having target sum == sum with corresponding root
            
            // recursively call the left and right subtrees for the same target sum.
            pathSum(root->left,sum);
            pathSum(root->right,sum);
        }
        return ans;
    }
    
    // search for target sum starting from passed root.
    void dfs(TreeNode* root, int sum){
        if(!root)return;
        if(root->val==sum)ans++;
        dfs(root->left,sum-root->val);
        dfs(root->right,sum-root->val);
    }

};