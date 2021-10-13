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
    
    TreeNode* solve(vector<int>& preorder,int i,int j){
        if(i==j){
            return new TreeNode(preorder[i]);
        }
        if(i>j){
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[i]);
        //TC:O(N^2) SC:O(H)
        // int high=i+1;
        // while(high<preorder.size()&&preorder[high]<root->val){
        //     high++;
        // }
        //TC:O(NlogN) SC:O(H)
        int high=upper_bound(preorder.begin()+i+1,preorder.begin()+j+1,preorder[i])-preorder.begin();
        root->left=solve(preorder,i+1,high-1);
        root->right=solve(preorder,high,j);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return solve(preorder,0,preorder.size()-1);        
    }
    
    int idx=0;
    //TC:O(N) SC:O(H)
    TreeNode* bstFromPreorderOptimized(vector<int>& preorder,int low=INT_MIN,int high=INT_MAX) {
        if(idx>=preorder.size()||preorder[idx]<low||preorder[idx]>high){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[idx++]);
        root->left = bstFromPreorderOptimized(preorder,low,root->val);
        root->right = bstFromPreorderOptimized(preorder,root->val,high);
        return root;
    }
};