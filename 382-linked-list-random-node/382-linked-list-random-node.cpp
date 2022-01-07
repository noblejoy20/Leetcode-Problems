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
        int ans=first->val;
        ListNode* ptr=first->next;
        int count=2;
        while(ptr!=NULL){            
            int n=rand()%count;
            if(n==0){
                ans=ptr->val;
            }
            ptr=ptr->next;
            count++;
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */