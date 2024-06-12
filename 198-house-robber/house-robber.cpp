class Solution {
public:

    // tabulation 
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp (n, 0);
        dp[0] = nums[0];

        for(int i = 1;i < n;i ++){
            int take  = nums[i] + ((i>1) ? dp[i-2] : 0);
            int notTake = 0 + dp[i-1];

            dp[i] = max(take,notTake);
        }

        return dp[n-1];
    }








    // correct implementation 
    int util(vector<int>& nums, int ind, vector<int>& dp){
        if(ind == 0){
            return nums[ind];
        }
        if(ind < 0){
            return 0;
        }

        if(dp[ind] != -1){
            return dp[ind];
        }

        // here the logic is either you take or not take 
        int not_take = 0 + util(nums, ind-1, dp);  // as this is not taken so we dont need to add anuything
        int take = nums[ind] + util(nums, ind-2, dp); // as taken we need to leave the adjacent and add the current value 

        return dp[ind] = max(take,not_take);

    }
    // int rob(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> dp (n, -1);
        
    //     return util(nums,n-1,dp);
    // }





    // this is a wrong code as it forces to take the last element in the solution(so either you have to make this solution for 
    // last and 2nd last elemnent then byh fluke it works )


//     int util(vector<int>& nums, int n, vector<int>& dp){
//         if(n==0){
//             return dp[n] = nums[0];
//         }
//         if(n < 0){
//             return 0;
//         }

//         if(dp[n] != -1) {
//             return dp[n];
//         }

//         int sum = nums[n];
//         int maax = 0;

//         for(int i = n-2; i>=0 ; i--){
//             int sum2 = util(nums, i,dp);
//             maax = max(maax, sum2);
//         }

//         return dp[n] = sum+maax;

//     }
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp (n, -1);
//         int one  =  util(nums,n-1,dp);
//         int two =  util(nums,n-2,dp);
//         return  max(one,two);
//     }
};