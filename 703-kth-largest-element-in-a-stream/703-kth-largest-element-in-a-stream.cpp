class KthLargest {
private:
    priority_queue<int,vector<int>,greater<int>> pq;
    
    int no;
public:
    KthLargest(int k, vector<int>& nums) {
        for(auto it:nums){
            pq.push(it);
        }
        no=k;
    }
    
    int add(int val) {
        
        pq.push(val);
        while(pq.size()>no){
            pq.pop();
        }
        
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 2 4 5 8
 2 3 4 5 8
 2 3 4 5 5 8
 2 3 4 5 5 8 10
 2 3 4 5 5 8 9 10
 2 3 4 4 5 5 8 9 10
 */