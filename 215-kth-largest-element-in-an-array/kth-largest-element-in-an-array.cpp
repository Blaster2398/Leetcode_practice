class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return nums[n-k];
    }
    // int findKthLargest(vector<int>& nums, int k) {
    //     priority_queue<int, vector<int> , greater<int>> pq;
    //     for(int i : nums){
    //         pq.push(i);
    //         if(pq.size() > k){
    //             pq.pop();
    //         }

    //     }
    //     return pq.top();
    // }
};