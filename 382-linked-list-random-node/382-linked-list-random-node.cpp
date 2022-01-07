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
    ListNode* first;
    Solution(ListNode* head) {
        srand(time(NULL));
        first=head;
    }
    
    int getRandom() {
        ListNode* ptr=first;
        if(!ptr->next){
            return ptr->val;
        }
        int ans=ptr->val;
        int count=0;
        while(ptr!=NULL){
            count++;
            int n=(rand()%count)+1;
            if(n==count){
                ans=ptr->val;

            }
            ptr=ptr->next;
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */