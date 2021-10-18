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
        int previousNodeRoot=-1;
        
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
                        
                        // if we have found the previousNode.
                        if(previousNodeRoot>0){
                            // return true if root node value's are different else false.
                            return previousNodeRoot!=front.second;
                        }
                        
                        //store the root node value of the first value(x or y)
                        previousNodeRoot=front.second;
                    }
                }
                
            }
            // if a node value is found in one level then there cannot be any cousin.
            if(previousNodeRoot>0){
                return false;
            }
        }
        return false;
    }
};