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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* nxt;
        
        ListNode* check=head;
        int count=1;
        
        while(check->next!=NULL && count<=k){
            check=check->next;
            count++;
        }
        
        if(count<k){
            return head;
        }
        
        count=0;
        
        while(curr!=NULL && count<k){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
            count++;
        }
        if(nxt!=NULL){
            head->next=reverseKGroup(nxt,k);
        }
        
        return prev;
        
    }
};