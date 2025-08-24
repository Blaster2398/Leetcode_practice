class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        int n = nums.size();
        int low =0, high = n-1;
        while(low <= high){
            int mid = (low+high) /2;
            if(nums[mid] - (mid+1) >= k){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low +k ;
    }
};