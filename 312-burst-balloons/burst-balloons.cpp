class Solution {
public:
    int n;
    vector<vector<int>> dp;
    vector<int> nums;
    int f(int i, int j){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0;
        for(int k = i; k <= j; k++){
            ans = max(ans, nums[i-1]*nums[k]*nums[j+1] + f(i, k-1) + f(k+1, j));
        }

        return dp[i][j] = ans;
    }
    int maxCoins(vector<int>& _nums) {
        nums= _nums;
        reverse(nums.begin(), nums.end());
        nums.push_back(1);
        reverse(nums.begin(), nums.end());
        nums.push_back(1);
        n = nums.size();
        dp.assign(n+1, vector<int>(n+1, -1));
        return f(1, n-2);
    }
};