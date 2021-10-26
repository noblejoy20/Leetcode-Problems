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
        // Initialise pointers same as single linked list reversal.
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* nxt;
        
        // check whether node are of length k else return head
        ListNode* check=head;
        int count=0;
        
        while(check!=NULL && count<k){
            check=check->next;
            count++;
        }
        
        if(count<k){
            return head;
        }
        
        
        //Initialise counter back to zero.
        count=0;
        
        //Do single LL reverse upto k nodes
        while(curr!=NULL && count<k){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
            count++;
        }
        
        //if the k+1 node is not null do recursive call.
        if(nxt!=NULL){
            head->next=reverseKGroup(nxt,k);
        }
        
        //return the prev node.
        return prev;
        
    }
};
