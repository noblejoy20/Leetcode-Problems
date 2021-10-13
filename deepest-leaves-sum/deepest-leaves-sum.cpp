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
    int mx=INT_MIN;
    
    // DFS maintaining current maximum depth and sum and reseting if new maximum found;
    void solve(TreeNode* root,int& sum,int depth){
        if(root==NULL){
            return;
        }
        solve(root->left,sum,depth+1);
        solve(root->right,sum,depth+1);
        if(!root->left&&!root->right){
            if(depth>mx){
                sum=root->val;
                mx=depth;
            }
            else if(depth==mx){
                sum+=root->val;
            }
        }
        
    }
    int deepestLeavesSum(TreeNode* root) {
        int sum=0;
        solve(root,sum,0);
        return sum;
    }
    
    
    // BFS method using queue.
    int deepestLeavesSumBFS(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int sum=0;
        while(!q.empty()){
            int size=q.size();
            sum=0;
            while(size--){
                TreeNode* front=q.front();
                sum+=front->val;
                q.pop();
                if(front->left!=NULL){
                    q.push(front->left);
                }
                if(front->right!=NULL){
                    q.push(front->right);
                }
                
            }            
        }
        return sum;        
    }
};