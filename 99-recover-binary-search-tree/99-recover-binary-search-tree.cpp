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
    TreeNode* temp=NULL;
    TreeNode* temp1=NULL;
    void findRight(TreeNode* root,int val){
        if(!root) return;
        if(root->val<val){
            if(temp){
                if(temp->val>root->val){
                    temp=root;
                }
            }else{
                temp=root;
            }
        }
        findRight(root->left,val);
        findRight(root->right,val);
    }
    void findLeft(TreeNode* root,int val){
        if(!root) return;
        if(root->val>val){
            if(temp1){
                if(temp1->val<root->val){
                    temp1=root;
                }
            }else{
                temp1=root;
            }
        }
        findLeft(root->left,val);
        findLeft(root->right,val);
    }
    bool solve(TreeNode* root){
        if(!root) return false;
        temp1=NULL;
        findLeft(root->left,root->val);
        
        temp=NULL;
        findRight(root->right,root->val);

        if(temp && temp1){
            swap(temp->val,temp1->val);
            return true;
        }
        else if(temp1){
            swap(root->val,temp1->val);
            return true;
        }
        else if(temp){
            
            swap(root->val,temp->val);
            return true;
        }
         if(solve(root->left)){
             return true;
         }
        if(solve(root->right)){
            return true;
        }
        return false;
    }
    void recoverTree(TreeNode* root) {
        solve(root);        
    }
    
};