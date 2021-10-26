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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
       ListNode* head;
        ListNode* temp;
        
        if(l1==NULL&&l2==NULL){
            return NULL;
        }else if(l1==NULL){
            return l2;
        }else if(l2==NULL){
            return l1;
        }
        if(l1->val<=l2->val){
            temp=l1;
            l1=temp->next;
        }else{
            temp=l2;
            l2=temp->next;
        }
        head=temp;
         while(l1!=NULL&&l2!=NULL){
            if(l1->val<=l2->val){
                temp->next=l1;
                temp=l1;
                l1=l1->next;
                continue;
            }
            if(l1->val>=l2->val){
                temp->next=l2;
                temp=l2;
                l2=l2->next;
                continue;
            }
        }
    
        if(l1==NULL){
            temp->next=l2;
        }else{
            temp->next=l1;
        }
        return head;
    }
};