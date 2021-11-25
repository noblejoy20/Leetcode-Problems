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
typedef pair<int,pair<int,ListNode*>> pp;
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
          priority_queue<pp,vector<pp>,greater<pp>> pq;
          for(int i=0;i<lists.size();i++){
              ListNode* ptr = lists[i];
              if(ptr!=NULL){
                pq.push({ptr->val,{i,ptr}});
              }
          }
          ListNode* res=NULL;
          ListNode* curr=NULL;
          if(!pq.empty()){
              auto val=pq.top();pq.pop();
              res=new ListNode(val.first);
              curr=res;
              if(val.second.second->next!=NULL){
                  pq.push({val.second.second->next->val,{val.second.first,val.second.second->next}});
              }
          }
          while(!pq.empty()){
              auto val=pq.top();pq.pop();
              curr->next=new ListNode(val.first);
              curr=curr->next;
              if(val.second.second->next!=NULL){
                  pq.push({val.second.second->next->val,{val.second.first,val.second.second->next}});
              }
          }
        return res;
    }
};