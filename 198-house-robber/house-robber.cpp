class Solution {
public:
    // this is a wrong code as it forces to take the last element in the solution 
    int util(vector<int>& nums, int n, vector<int>& dp){
        if(n==0){
            return dp[n] = nums[0];
        }
        if(n < 0){
            return 0;
        }

        if(dp[n] != -1) {
            return dp[n];
        }

        int sum = nums[n];
        int maax = 0;

        for(int i = n-2; i>=0 ; i--){
            int sum2 = util(nums, i,dp);
            maax = max(maax, sum2);
        }

        return dp[n] = sum+maax;

    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp (n, -1);
        int one  =  util(nums,n-1,dp);
        int two =  util(nums,n-2,dp);

        return  max(one,two);
    }
};