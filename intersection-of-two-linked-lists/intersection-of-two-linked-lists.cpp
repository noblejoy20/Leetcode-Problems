/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL||headB==NULL)return NULL;
        ListNode *ptrA=headA,*ptrB=headB;
        while(ptrA!=ptrB){
            if(ptrA==NULL) {ptrA=headB;continue;}
            if(ptrB==NULL) {ptrB=headA;continue;}
            ptrA=ptrA->next;
            ptrB=ptrB->next;
        }
        return ptrA;
    }
};