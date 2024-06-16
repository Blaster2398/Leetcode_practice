class Solution {
public:
    // bool isSubsetSum(vector<int>arr, int sum){
    //     int n = arr.size();
    //     vector<vector<bool>> dp (n, vector<bool>(sum+1 , false));
        
    //     for(int i = 0; i < n; i++){
    //         dp[i][0] = true;
    //     }
    //     if (arr[0] <= sum) {
    //         dp[0][arr[0]] = true;
    //     }

        
    //     for(int ind = 1; ind < n; ind++){
    //         for(int target = 1; target <= sum; target++){
    //             bool take = false;
    //             bool not_take = dp[ind-1][target];
    //             if(target >= arr[ind]){
    //                 take = dp[ind-1][target-arr[ind]];
    //             }
    //             dp[ind][target] = not_take || take;
    //         }
    //     }
    //     return dp[n-1][sum];
    // }
    // bool canPartition(vector<int>& nums) {
    //     int n = nums.size();

    //     int sum = 0;
    //     for(int i = 0; i<n; i++){
    //         sum+= nums[i];
    //     }
    //     if(sum %2 != 0){
    //         return false;
    //     }
    //     // cout << sum << endl;
    //     sum = sum/2;
    //     vector<vector<int>> dp (n+1, vector<int>(sum+1, -1));

    //     return isSubsetSum(nums, sum);
    // }




    // memoization based gives tle

    int f(vector<int>nums, int ind, int target, vector<vector<int>>& dp){
        // base cases
        if(target == 0){
            return 1;
        }
        else if(target != 0 && ind < 0){
            return 0;
        }
        if(ind == 0){
            return (nums[0] == target);
        }
        
        // return if already present 
        if(dp[ind][target] != -1){
            return dp[ind][target];
        }
        if(nums[ind] <= target){
            return dp[ind][target] = f(nums,ind-1,target - nums[ind],dp) or f(nums,ind-1,target,dp);
        }
        else return dp[ind][target] = f(nums,ind-1,target,dp);
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        for(int i = 0; i<n; i++){
            sum+= nums[i];
        }
        if(sum %2 != 0){
            return false;
        }
        // cout << sum << endl;
        sum = sum/2;
        vector<vector<int>> dp (n+1, vector<int>(sum+1, -1));

        return (f(nums, n-1, sum, dp) == 1 ? true : false);
    }
};
