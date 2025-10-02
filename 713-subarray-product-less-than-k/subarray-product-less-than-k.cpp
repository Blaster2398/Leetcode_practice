class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int n = nums.size();
        int l = 0, r = 0;
        int prod = 1;
        int count = 0;
        while(r < n){
                prod*= nums[r];

            while( l <= r && prod >= k){
                prod /= nums[l];
                l++;
            }
            count += r- l + 1;

            r++;
        }
        return count;
    }
};