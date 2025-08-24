class Solution {
public:
    bool geek(vector<int>& nums, int t, int mid){
        long long ans = 0;
        for(int i = 0;i < nums.size(); i++){
            ans += (nums[i]+mid-1)/mid;
        }
        return (ans <= t);
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        int ans = high;

        while(low <= high){
            int mid = (low + high)/ 2;
            int check = geek(nums, threshold, mid);
            if(check){
                high = mid - 1;
                ans = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};