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
    int maxProfit_memo(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(), vector<int>(2,-1));
        return util(prices, 0, 1, dp, fee);
    }





    //space opt
    int maxProfit_spcOPT(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> front1(2,0), curr(2,0);

        // //base case
        // front1[0] = front1[1] = 0;

        // as it is top doun go from n-1 to 0
        for(int ind = n-1; ind >= 0; ind--){
            for(int buy = 0; buy <=1; buy++){
                int profit = 0;
                if(buy){
                    profit = max(-prices[ind]+ front1[0], 0 + front1[1]);
                } else {
                    profit = max(prices[ind] + front1[1] -fee, 0 + front1[0]);
                }
                curr[buy] = profit;
            }
            front1 = curr;
        }
        return curr[1];
    }


 int maxProfit(vector<int>& prices, int fee) {
    if (prices.empty()) return 0;
    
    int maxProfit = 0;
    int buyPrice = prices[0];

    for (int i = 1; i < prices.size(); i++) {
        // If selling at the current price is profitable
        if (prices[i] > buyPrice + fee) {
            maxProfit += prices[i] - buyPrice - fee;
            // After selling, we need to set the new buy price
            buyPrice = prices[i] - fee;  // This handles the case where we continue holding
        } else if (prices[i] < buyPrice) {
            // If we find a lower price to buy, update the buy price
            buyPrice = prices[i];
        }
    }
    return maxProfit;
}






    // TAbulatin
    int maxProfit_tab(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2,0));

        //base case
        dp[n][0] = dp[n][1] = 0;

        // as it is top doun go from n-1 to 0
        for(int ind = n-1; ind >= 0; ind--){
            for(int buy = 0; buy <=1; buy++){
                int profit = 0;
                if(buy){
                    profit = max(-prices[ind]+ dp[ind+1][0], 0 + dp[ind+1][1]);
                } else {
                    profit = max(prices[ind] + dp[ind+1][1] -fee, 0 + dp[ind+1][0]);
                }
                dp[ind][buy] = profit;
            }
        }
        return dp[0][1];
    }
};