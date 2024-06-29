class Solution {
public:
    int util(vector<int>& prices, int ind, int buy,vector<vector<int>>& dp){
        // base cases 
        if(ind == prices.size()){
            return 0;
        }
        if(dp[ind][buy] != -1){
            return dp[ind][buy];
        }
        // steps
        int profit = 0;
        if(buy){
            profit = max(-prices[ind]+ util(prices, ind+1, 0, dp), 0 + util(prices, ind+1, 1, dp));
        } else {
            profit = max(prices[ind] + util(prices, ind+1, 1, dp), 0 + util(prices, ind+1, 0, dp));
        }

        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2,-1));
        return util(prices, 0, 1, dp);
    }
    // int maxProfit(vector<int>& prices) {
    //     int maxProfit = 0;
    //     int buyPrice = prices[0];
    //     for(int i = 0; i< prices.size(); i++){
    //         if(buyPrice < prices[i]){
    //             int profit = prices[i] - buyPrice;
    //             maxProfit += profit;
    //             buyPrice = prices[i];
    //         }
    //         else{
    //             buyPrice = prices[i];
    //         }
    //     }
    //     return maxProfit;
    // }
};