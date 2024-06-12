class Solution {
public:
    int util(vector<int>& nums, vector<int>& dp, int ind){
        if(ind == 0){
            return nums[0];
        }
        if(ind<0){
            return 0;
        }
        if(dp[ind] != -1){
            return dp[ind];
        }
        
        int not_take = 0 + util(nums, dp, ind-1);
        int take = nums[ind] + util(nums, dp, ind-2);

        return dp[ind] = max(take,not_take);

    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n-1,-1);
        vector<int> dp2(n-1,-1);
        
        if(n ==1){
            return nums[0];
        }
        vector<int> temp;
        vector<int> temp2;

        for(int i = 0; i < n; i++){
            if(i!=0)temp.push_back(nums[i]);
            if(i!=n-1)temp2.push_back(nums[i]);
        }
        int ans1 = util(temp, dp1, n-2);
        int ans2 = util(temp2, dp2, n-2);


        return  max(ans1,ans2);
    }
};