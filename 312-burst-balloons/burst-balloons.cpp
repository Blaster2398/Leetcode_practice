class Solution {
public:
    int f(int i , int j ,vector<int> & nums, vector<vector<int>> & dp){
        //base cases 
        if(i > j) return 0;

        // if present then return 
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        // stuff to do
        int maxi = INT_MIN; 
        for(int k = i; k <=j ; k++){
            int coins = (nums[i-1] * nums[k] * nums[j+1]) + f(i, k -1, nums, dp) + f(k+1, j, nums, dp);
            maxi = max(maxi, coins);
        }
        // return the max
        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return f(1, n, nums, dp);
    }
};