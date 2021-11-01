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
        ListNode* temp=NULL;
        ListNode* head=temp;
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1->val<l2->val){
            temp=l1;
            head=l1;
            l1=l1->next;
        }else{
            temp=l2;
            head=l2;
            l2=l2->next;
        }
        while(l1&&l2){
            if(l1->val<l2->val){
                temp->next=l1;
                temp=l1;
                l1=l1->next;
            }else{
                temp->next=l2;
                temp=l2;
                l2=l2->next;
            }
        }
        if(!l1){
            temp->next=l2;
        }else{
            temp->next=l1;
        }
        return head;
    }
};