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
    ListNode* mergeTwoSortedLists(ListNode* first,ListNode* second){
        ListNode* dummy = new ListNode();
        ListNode* start = dummy;
        
        while(first && second){
            if(first->val<=second->val){
                start->next = first;
                first = first->next;
                start = start->next;
            }else{
                start->next = second;
                second = second->next;
                start = start->next;
            }
        }
        
        while(first){
            start->next = first;
            first = first->next;
            start=start->next;
        }
        
        while(second){
            start->next = second;
            second = second->next;
            start=start->next;
        }
        
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
        
        if(lists.size() == 1){
            return lists[0];
        }
        
        ListNode* result = mergeTwoSortedLists(lists[0],lists[1]);
            
        for(int i=2;i<lists.size();i++){
            result = mergeTwoSortedLists(result,lists[i]);
        }
        
        return result;
    }
};