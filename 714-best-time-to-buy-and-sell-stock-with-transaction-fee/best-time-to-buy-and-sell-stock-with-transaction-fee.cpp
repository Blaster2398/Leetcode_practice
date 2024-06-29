class Solution {
public:
    // recursive + memo
    int util(vector<int>& prices, int ind, int buy,vector<vector<int>>& dp, int fee){
        // base cases 
        if(ind >= prices.size()){
            return 0;
        }
        if(dp[ind][buy] != -1){
            return dp[ind][buy];
        }
        // steps
        int profit = 0;
        if(buy){
            profit = max(-prices[ind]+ util(prices, ind+1, 0, dp, fee), 0 + util(prices, ind+1, 1, dp,fee));
        } else {
            profit = max(prices[ind] + util(prices, ind+1, 1, dp, fee) - fee, 0 + util(prices, ind+1, 0, dp, fee));
        }

        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(), vector<int>(2,-1));
        return util(prices, 0, 1, dp, fee);
    }
};