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
    ListNode* oddEvenList(ListNode* head) {
        if(!head||!head->next){
            return head;
        }
        ListNode* ptr1=head;
        ListNode* ptr2=head->next;
        ListNode* temp=ptr2;
        while(ptr1->next&&ptr2->next){
            ptr1->next=ptr2->next;
            ptr1=ptr1->next;
            if(!ptr1->next) break;
            ptr2->next=ptr1->next;
            ptr2=ptr2->next;
        }
        ptr1->next=temp;
        ptr2->next=NULL;
        return head;
    }
};