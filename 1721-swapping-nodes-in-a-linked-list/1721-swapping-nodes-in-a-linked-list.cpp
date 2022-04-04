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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* first=head;
        while(first && --k>0){
            first=first->next;
        }
        //cout<<first->val;
        ListNode* ptr = first;
        ListNode* second=head;
        while(ptr->next){
            ptr=ptr->next;
            second=second->next;
        }
        swap(first->val,second->val);
        return head;
    }
};