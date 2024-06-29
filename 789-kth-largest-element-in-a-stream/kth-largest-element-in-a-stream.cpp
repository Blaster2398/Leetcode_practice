class KthLargest {
public:
    priority_queue<int, vector<int> , greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        if(k > nums.size()){
            for(int i = 0;i < k-nums.size(); i++){
                pq.push(INT_MIN);
            }
        }
        for(int i : nums){
            pq.push(i);
            if(pq.size() > k){
                pq.pop();
            }

        }
    }
    
    int add(int val) {
        pq.push(val);
        pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
