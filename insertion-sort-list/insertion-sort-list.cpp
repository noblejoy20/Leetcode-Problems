/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool solve(ListNode* left,ListNode* right){
        if(!right){
            return false;
        }
        if(left->val>right->val){
            return true;
        }
        if(solve(left,right->next)){
            swap(right->val,right->next->val);
            return true;
        }
        return false;
    }
    ListNode* insertionSortList(ListNode* head) {
        if(!head||!head->next){
            return head;
        }
        ListNode* left=head;
        ListNode* right;
        
        while(left!=NULL){
            bool ans=true;
            right=left->next;
            while(ans){
                ans=solve(left,right);
                if(ans){
                    swap(left->val,right->val);                   
                }
            }
            left=left->next;
        }
        return head;
    }
};