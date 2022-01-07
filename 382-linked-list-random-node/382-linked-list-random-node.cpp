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
    vector<int> nums;
    Solution(ListNode* head) {
        //srand(time(NULL));
        while(head!=NULL){
            nums.push_back(head->val);
            head=head->next;
        }
    }
    
    int getRandom() {
        
        int n=rand()%nums.size();
        cout<<n<<" ";
        // double d=n/RAND_MAX;
        // //cout<<d<<" ";
        // double val=d*(nums.size()-1);
        // int result=(int)val;
        return nums[n];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */