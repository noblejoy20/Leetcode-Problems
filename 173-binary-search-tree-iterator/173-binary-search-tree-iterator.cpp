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
class BSTIterator {
public:
    vector<int> inorder;
    int i=0;
    BSTIterator(TreeNode* root) {
        TreeNode* curr=root;
        i=-1;
        while(curr!=NULL){
            if(!curr->left){
                inorder.push_back(curr->val);
                curr=curr->right;
            }else{
                TreeNode* prev=curr->left;
                while(prev->right && prev->right!=curr ){
                    prev=prev->right;
                }
                if(!prev->right){
                    prev->right=curr;
                    curr=curr->left;
                }
                if(prev->right==curr){
                    prev->right=NULL;
                    inorder.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
    }
    
    int next() {
        
        int val = inorder[i+1];
        i++;
        return val;
        
    }
    
    bool hasNext() {
        return i+1<inorder.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */