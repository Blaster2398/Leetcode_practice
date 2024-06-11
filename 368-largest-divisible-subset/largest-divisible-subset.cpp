class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();

        if(nums.empty()) {
            return {};
        }
        // initialize the dp array
        vector<int> dp(n, 1);
        vector<int> hash(n);
        sort(nums.begin(), nums.end());

        for (int i = 1; i <= n-1; i++) {
            hash[i] = i;
            for (int j = 0; j <= i-1; j++) {
                if (((nums[i] % nums[j]) ==0 || (nums[j] % nums[i]) ==0 )&& 1+dp[j] > dp[i]) {
                    dp[i] =  dp[j] + 1;
                    hash[i] = j;
                }
            }
        }
        // now to get the max in dp and its index
        int lastInd = -1;
        int ans = -1;
        
        for(int i = 0; i< n; i++){
            if(dp[i] > ans){
                ans = dp[i];
                lastInd = i;
            }
        }
        
        vector<int> res;
        res.push_back(nums[lastInd]);
        
        while(hash[lastInd] != lastInd){
            lastInd = hash[lastInd];
            res.push_back(nums[lastInd]);
        }
        
        reverse(res.begin(),res.end());
        return res;
    }
















    // void LDS(vector<int>& nums, vector<vector<int>> & dp, int n, int ind, int j, vector<int> &res){
    //     if(ind == n){
    //         return 0;
    //     }
    //     // if you have the ans 

    // }
    // vector<int> largestDivisibleSubset(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> res;
    //     sort(nums.begin(),nums.end());
    //     vector<vector<int>> dp(n, vector<int>(n+1, -1));
    //     LDS(nums, dp, n, 0, -1, res);
    // }
};