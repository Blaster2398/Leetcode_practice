class Solution {
public:
    bool geek(vector<int>& nums, int k, int mid){
        int sum = 0;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] + sum > mid){
                sum = 0;
                ans++;
            }
            sum += nums[i];
        }
        if(sum != 0) ans++;
        return (ans <= k);
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = -1;
        while(low <= high){
            int mid = (low+high) / 2;
            bool check = geek(nums, k, mid);
            if(check){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};