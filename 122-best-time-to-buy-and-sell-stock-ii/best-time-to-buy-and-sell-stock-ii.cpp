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
    int maxProfit_recursive(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2,-1));
        return util(prices, 0, 1, dp);
    }


    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> ahead(2,0), curr(2,0);

        //base case
        ahead[0] = ahead[1] = 0;

        // as it is top doun go from n-1 to 0
        for(int ind = n-1; ind >= 0; ind--){
            for(int buy = 0; buy <=1; buy++){
                int profit = 0;
                if(buy){
                    profit = max(-prices[ind]+ ahead[0], 0 + ahead[1]);
                } else {
                    profit = max(prices[ind] + ahead[1], 0 + ahead[0]);
                }
                curr[buy] = profit;
            }
            ahead = curr;
        }
        return ahead[1];
    }


    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     vector<vector<int>> dp(n+1, vector<int>(2,0));

    //     //base case
    //     dp[n][0] = dp[n][1] = 0;

    //     // as it is top doun go from n-1 to 0
    //     for(int ind = n-1; ind >= 0; ind--){
    //         for(int buy = 0; buy <=1; buy++){
    //             int profit = 0;
    //             if(buy){
    //                 profit = max(-prices[ind]+ dp[ind+1][0], 0 + dp[ind+1][1]);
    //             } else {
    //                 profit = max(prices[ind] + dp[ind+1][1], 0 + dp[ind+1][0]);
    //             }
    //             dp[ind][buy] = profit;
    //         }
    //     }
    //     return dp[0][1];
    // }


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