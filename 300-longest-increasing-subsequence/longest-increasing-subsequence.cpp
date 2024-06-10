class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        // initialize the dp array
        vector<int> dp(nums.size(), 1);
        int muux = 1;

        for (int i = 1; i < nums.size(); i++) {
            for (int j = i; j>=0; j--) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            muux = max(muux, dp[i]);
        }
        return muux;
    }
    
};