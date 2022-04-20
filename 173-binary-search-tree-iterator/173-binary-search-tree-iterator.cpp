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
private:
    int i;
    TreeNode* curr;
public:    
    BSTIterator(TreeNode* root) {
        curr=root;
        i=-1;        
    }
    
    int next() {    
        int val=-1;
        while(val==-1){
            if(!curr) return 0;
            if(!curr->left){
                val = curr->val;
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
                    val = curr->val;
                    curr=curr->right;
                }
            }
        }
        return val;
        
        
    }
    
    bool hasNext() {
        return curr!=NULL;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */