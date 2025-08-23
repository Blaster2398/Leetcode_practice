class Solution {
public:
    using ll = long long;
    bool geek(vector<int>& nums, int h , int mid){
        ll ans= 0;
        int i = 0;
        while(i < nums.size()){
            ans += nums[i]/mid;
            if(nums[i] % mid) ans++;
            // ans += (nums[i] + mid -1) / mid;
            i++;
        }
        return (ans > h) ? false : true;
    }
    int minEatingSpeed(vector<int>& nums, int h) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        int  ans = high;
        while(low <= high){
            int mid = (low + high) /2;
            int check = geek(nums, h, mid);
            if(check){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};