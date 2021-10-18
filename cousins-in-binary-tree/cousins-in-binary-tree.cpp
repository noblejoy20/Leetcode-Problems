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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<pair<TreeNode*,int>> q; // node and its root value;
        q.push({root,-1});
        // keep variable to check if one value is found and the corresponding root of the value;
        int isFound=0,previousNodeRoot=-1;
        
        // perform BFS
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto front=q.front();q.pop();
                if(front.first){
                    q.push({front.first->left,front.first->val});
                    q.push({front.first->right,front.first->val});
                    
                    // check if the node is of the given values.
                    if(front.first->val==x||front.first->val==y){
                        // make it true the first time if we find x or y.
                        // make it false the second time if we find x or y
                        isFound=!isFound; 
                        
                        // if we have found the previousNode.
                        if(previousNodeRoot>0){
                            return previousNodeRoot!=front.second;
                        }
                        
                        //store the root node value of the first value(x or y)
                        previousNodeRoot=front.second;
                    }
                }
                
            }
            if(isFound){
                return false;
            }
        }
        return false;
    }
};