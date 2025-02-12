class Solution {
public:
    int sum_num(int num){
        int sum = 0;
        while(num > 0){
            int rem = num % 10;
            sum += rem;
            num = num / 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        map<int, int> mp;
        int maxi = -1;

        for(int i = 0; i < nums.size(); i++){
            int sum = sum_num(nums[i]);
            if(mp.count(sum) != 0){
                maxi = max(maxi, nums[i] + mp[sum]);
                mp[sum] = max(mp[sum], nums[i]);
            }
            else{
                mp[sum] = nums[i];
            }
        }
        return maxi;
    }
};